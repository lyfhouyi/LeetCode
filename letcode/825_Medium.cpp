#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//人们会互相发送好友请求，现在给定一个包含有他们年龄的数组，ages[i] 表示第 i 个人的年龄。
//
//当满足以下任一条件时，A 不能给 B（A、B不为同一人）发送好友请求：
//
//	age[B] <= 0.5 * age[A] + 7
//	age[B] > age[A]
//	age[B] > 100 && age[A] < 100
//
//否则，A 可以给 B 发送好友请求。
//
//注意如果 A 向 B 发出了请求，不等于 B 也一定会向 A 发出请求。而且，人们不会给自己发送好友请求。 
//
//求总共会发出多少份好友请求 ?
//
//
//提示：
//
//	1 <= ages.length  <= 20000.
//	1 <= ages[i] <= 120.
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/friends-of-appropriate-ages
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


////原版：双指针遍历数组
//int numFriendRequests(vector<int>& ages)
//{
//	sort(ages.begin(), ages.end());
//	vector<int>::reverse_iterator ritJ;
//	vector<int>::reverse_iterator ritI;
//	int tmp;
//	int requestCnt = 0;
//	for (ritI = ages.rbegin(); ritI != ages.rend(); ritI++)
//	{
//		ritJ = ritI + 1;
//		tmp = *ritI*0.5 + 7;
//		while (ritJ != ages.rend() && *ritJ > tmp)
//		{
//			cout << "numFriendRequests：产生好友请求  " << *ritI << " -> " << *ritJ << endl;
//			requestCnt++;
//			if (*ritI == *ritJ) //两人年纪相等时，可以互相发送好友请求
//				requestCnt++;
//			ritJ++;
//		}
//	}
//	return requestCnt;
//}


//双指针升级版：双指针遍历双数组。用 lowerbounds 数组记录 A 的适龄好友的年龄下确界。
//int numFriendRequests(vector<int>& ages)
//{
//	sort(ages.begin(), ages.end(), [](int ageA, int ageB) {return ageA > ageB; });
//	int requestCnt = 0;
//	int currentBound;
//	int sameAgeCnt = 0;
//	vector<int> lowerbounds;
//	int indexBound = 0;
//	for (vector<int>::iterator it = ages.begin(); it != ages.end(); it++)
//	{
//		if (*it > 14 && it != ages.begin() && *it == *(it - 1)) //计算在之前已判断的人中，与当前人的年龄相等的人数
//		{
//			sameAgeCnt++;
//			requestCnt += sameAgeCnt; //两人年纪相等时，可以互相发送好友请求
//		}
//		else
//			sameAgeCnt = 0;
//		while (indexBound != lowerbounds.size() && lowerbounds[indexBound] >= *it)
//		{
//			indexBound++;
//		}
//		requestCnt += (lowerbounds.size() - indexBound);
//		currentBound = *it*0.5 + 7;
//		lowerbounds.push_back(currentBound);
//	}
//	return requestCnt;
//}


//桶排序再升级版：双指针遍历双数组。用年龄桶同代替排序，用 lowerbounds 数组记录 A 的适龄好友的年龄下确界。
int numFriendRequests(vector<int>& ages)
{
	const int AgeUpperBound = 120;
	const int BucketSize = AgeUpperBound + 1 - 15;
	vector<int> ageBucket(BucketSize, 0); //年龄桶，只有年龄段在 [15, 120] 内的人才有朋友

	//装填年龄桶（降序）
	for (int i = 0; i < ages.size(); i++)
	{
		if (ages[i] > 14)
			ageBucket[AgeUpperBound - ages[i]]++; // ageBucket[i] 为年龄为 AgeUpperBound - i 的人数
	}

	//遍历年龄桶，装填有可能作为 A 的年龄数组，计算好友数量
	vector<int> ageA; //有可能作为 A 的年龄数组
	int requestCnt = 0;
	int indexA = 0;
	int candidateCnt = 0; //当前 lowerbounds 数组中，有可能作为 A 的人数
	for (int i = 0; i < BucketSize; i++)
	{
		//索引 i 对应的年龄为 AgeUpperBound - i ，人数为 ageBucket[i]
		if (0 == ageBucket[i])
			continue;
		requestCnt += ageBucket[i] * (ageBucket[i] - 1); //年龄相等的人互相发送好友邀请
		while (indexA != ageA.size() && ageA[indexA] / 2 + 7 >= AgeUpperBound - i) //年龄为 AgeUpperBound - i 的人作为 B 接收好友邀请
		{
			candidateCnt -= ageBucket[AgeUpperBound - ageA[indexA]]; //年龄为 ageA[indexA] 的人已不可能作为 A 而发送好友邀请
			indexA++;
		}
		requestCnt += ageBucket[i] * candidateCnt; // ageBucket[i] * candidateCnt 为年龄为 AgeUpperBound - i 的人作为 B 接收到的好友邀请的数量。
		ageA.push_back(AgeUpperBound - i); //年龄为 AgeUpperBound - i 的人有可能作为 A 而发送好友邀请
		candidateCnt += ageBucket[i]; //年龄为 AgeUpperBound - i 的人都可能作为 A 而发送好友邀请
	}
	return requestCnt;
}


int main825()
{
	//vector<int> test = { 16,17,18 };
	vector<int> test = { 20,30,37,37,37,37,37 };
	//vector<int> test = { 20,30,100,110,120 };
	//vector<int> test = { 73, 106, 6,39,26, 15, 30, 6,6,6,6,6,100, 71, 35, 46, 112, 6, 60, 110 };
	int ret = numFriendRequests(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}