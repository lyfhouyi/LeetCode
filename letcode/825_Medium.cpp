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


//双指针遍历数组
int numFriendRequests(vector<int>& ages)
{
	sort(ages.begin(), ages.end());
	vector<int>::reverse_iterator ritJ;
	vector<int>::reverse_iterator ritI;
	int tmp;
	int requestCnt = 0;
	for (ritI = ages.rbegin(); ritI != ages.rend(); ritI++)
	{
		ritJ = ritI + 1;
		tmp = *ritI*0.5 + 7;
		while (ritJ != ages.rend() && *ritJ > tmp)
		{
			cout << "numFriendRequests：产生好友请求  " << *ritI << " -> " << *ritJ << endl;
			requestCnt++;
			if (*ritI == *ritJ) //两人年纪相等时，可以互相发送好友请求
				requestCnt++;
			ritJ++;
		}
	}
	return requestCnt;
}


int main()
{
	vector<int> test = { 16,16 };
	int ret = numFriendRequests(test);
	cout << "main：ret = " << ret << endl;
}