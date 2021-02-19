#include<iostream>
#include<vector>

using namespace std;

//给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
//
//返回仅包含 1 的最长（连续）子数组的长度。
//
//
//提示：
//
//	1 <= A.length <= 20000
//	0 <= K <= A.length
//	A[i] 为 0 或 1 
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/max-consecutive-ones-iii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针构造滑动窗。实时统计窗内 0 的个数，若 0 的个数小于等于 K ，则可将右端指针右移，若 0 的个数大于 K ，则需将左端指针右移；如此当滑动窗移动至数组尾时，记录窗宽的最大值即为返回值。 
int longestOnes(vector<int>& A, int K)
{
	int n = A.size();
	int maxLength = 0;
	int currentLength;
	int windowRight = 0;
	int windowLeft = 0;
	int zeroCnt = 0;

	//以 [windowLeft,windowRight] 作为滑动窗口
	while (windowRight < n)
	{
		//滑动窗包含右指针所指元素
		zeroCnt += (1 - A[windowRight]);

		//调整滑动窗左指针
		while (zeroCnt > K)
		{
			zeroCnt -= (1 - A[windowLeft]);
			windowLeft++;
		}

		//此时的滑动窗满足题意且为以 windowRight 为右端点的滑动窗中最长的一个
		currentLength = windowRight - windowLeft + 1;
		maxLength = maxLength > currentLength ? maxLength : currentLength;
		windowRight++;
	}
	return maxLength;
}


int main()
{
	vector<int> test = { 1 };
	//vector<int> test = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
	//vector<int> test = { 1,1,1,0,0,0,1,1,1,1,0 };
	//vector<int> test = { 0,0,0,1,0,1,1,0 };
	int ret = longestOnes(test, 0);
	cout << "main：ret = " << ret << endl;
	return 0;
}