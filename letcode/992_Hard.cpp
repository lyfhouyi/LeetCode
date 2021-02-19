#include<iostream>
#include<vector>
#include<map>

using namespace std;

//给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
//
//（例如，[1, 2, 3, 1, 2] 中有 3 个不同的整数：1，2，以及 3。）
//
//返回 A 中好子数组的数目。
//
//
//提示：
//
//	1 <= A.length <= 20000
//	1 <= A[i] <= A.length
//	1 <= K <= A.length
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/subarrays-with-k-different-integers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//计算最大包含 K 个不同整数的子数组数量。使用双指针构造滑动窗口，统计窗口内不同整数的数量；若该数量大于 k 则将窗口左端右移一位，否则将窗口右端右移一位；
int subarraysMaxKDistinct(vector<int>& A, int K)
{
	int n = A.size();
	int windowLeft = 0;
	int windowRight = -1;
	int subarrayCnt = 0;
	map<int, int> intCountMap;

	//以 [windowLeft,windowRight] 作为滑动窗口
	while (windowLeft < n)
	{
		while (windowRight < n && intCountMap.size() <= K) //移动滑动窗口的右端
		{
			windowRight++;
			if (windowRight == n)
				break;
			if (intCountMap.count(A[windowRight]) > 0)
				intCountMap.at(A[windowRight])++;
			else
				intCountMap[A[windowRight]] = 1;
		}

		//计算以 windowLeft 为左端的最大包含 K 个不同整数的子数组的数量
		subarrayCnt += windowRight - windowLeft;

		//滑动窗口左端右移一位
		if (1 == intCountMap.at(A[windowLeft]))
			intCountMap.erase(A[windowLeft]);
		else
			intCountMap.at(A[windowLeft])--;
		windowLeft++;
	}
	return subarrayCnt;
}


//双指针构造滑动窗。恰好包含 K 个不同整数的子数组数量 = 最大包含 K 个不同整数的子数组数量 - 最大包含 K - 1 个不同整数的子数组数量。
int subarraysWithKDistinct(vector<int>& A, int K)
{
	return subarraysMaxKDistinct(A, K) - subarraysMaxKDistinct(A, K - 1);
}


int main992()
{
	////vector<int> test = { 1};
	//vector<int> test = {7,7,8,9,9};
	vector<int> test = { 1,2,1,2,3 };
	//vector<int> test = { 1,2,1,3,4 };
	int ret = subarraysWithKDistinct(test, 2);
	cout << "main：ret = " << ret << endl;
	return 0;
}