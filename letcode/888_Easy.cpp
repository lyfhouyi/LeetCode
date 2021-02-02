#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_set>

using namespace std;

//爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。
//
//因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）
//
//返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。
//
//如果有多个答案，你可以返回其中任何一个。保证答案存在。
//
//
//提示：
//
//	1 <= A.length <= 10000
//	1 <= B.length <= 10000
//	1 <= A[i] <= 100000
//	1 <= B[i] <= 100000
//	保证爱丽丝与鲍勃的糖果总量不同。
//	答案肯定存在。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/fair-candy-swap
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//排序后双指针遍历双数组。原版。
//vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
//{
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//	int sumA = accumulate(A.begin(), A.end(), 0);
//	int sumB = accumulate(B.begin(), B.end(), 0);
//	int changeValueDiff = (sumA - sumB) / 2;
//	int tmp = abs(changeValueDiff);
//	vector<int>& searchSmall = changeValueDiff > 0 ? B : A;
//	vector<int>& searchBig = changeValueDiff > 0 ? A : B;
//	vector<int>::iterator itSmall = searchSmall.begin();
//	vector<int>::iterator itBig = searchBig.begin();
//	for (; itSmall != searchSmall.end(); itSmall++)
//	{
//		while (itBig != searchBig.end() && *itBig < *itSmall + tmp)
//			*itBig++;
//		if (*itBig == *itSmall + tmp)
//			break;
//	}
//	vector<int> ret(2);
//	ret[0]=*itSmall;
//	ret[1]=*itBig;
//	if (changeValueDiff > 0)
//		swap(ret[0], ret[1]);
//	return ret;
//}


//排序后双指针遍历双数组。优化版。
//vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
//{
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//	int sumA = accumulate(A.begin(), A.end(), 0);
//	int sumB = accumulate(B.begin(), B.end(), 0);
//	int changeValueDiff = (sumA - sumB) / 2;
//	vector<int>::iterator itA = A.begin();
//	vector<int>::iterator itB = B.begin();
//	while (itA != A.end() && itB != B.end() && *itA != *itB + changeValueDiff)
//	{
//		if (*itA < *itB + changeValueDiff)
//			itA++;
//		else
//			itB++;
//	}
//	vector<int> ret(2);
//	ret[0] = *itA;
//	ret[1] = *itB;
//	return ret;
//}

//哈希表。单指针遍历数组。
vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
{
	int sumA = accumulate(A.begin(), A.end(), 0);
	int sumB = accumulate(B.begin(), B.end(), 0);
	int changeValueDiff = (sumA - sumB) / 2;
	unordered_set<int> setA(A.begin(), A.end());
	vector<int> ret(2);
	for (vector<int>::iterator it = B.begin(); it != B.end(); it++)
	{
		if (setA.count(*it + changeValueDiff))
		{
			ret[0] = *it + changeValueDiff;
			ret[1] = *it;
			break;
		}
	}
	return ret;
}


int main888()
{
	vector<int> B = { 1,2,5 };
	vector<int> A = { 2,4 };
	vector<int> ret = fairCandySwap(A, B);
	cout << "main：ret = [" << ret[0] << "," << ret[1] << "]" << endl;
	return 0;
}