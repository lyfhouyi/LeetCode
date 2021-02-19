#include<iostream>
#include<vector>

using namespace std;

//在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为 0。
//
//返回所需的 K 位翻转的最小次数，以便数组没有值为 0 的元素。如果不可能，返回 - 1。
//
//
//提示：
//
//	1 <= A.length <= 30000
//	1 <= K <= A.length
//	通过次数6, 749提交次数13, 850
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//
////贪心算法，暴力版。使用滑动窗口掠过原始数组。当窗口的左端指针值为 0 时，翻转窗口内的值；若如此进行至数组尾时，最后窗口内元素不全为 1 ，则答案为不可能，否则返回翻转次数。
////算法正确，但时间超时。
//int minKBitFlips(vector<int>& A, int K)
//{
//	int n = A.size();
//	int flipCnt = 0;
//	int i;
//	int j;
//
//	//移动滑动窗，翻转窗内元素使满足题意
//	for (i = 0; i < n - K + 1; i++)
//	{
//		if (0 == A[i]) //翻转滑动窗内的值
//		{
//			flipCnt++;
//			for (j = 0; j < K; j++)
//			{
//				A[i + j] = !A[i + j];
//			}
//		}
//	}
//
//	//检查最后一个窗口是否满足题意
//	while (i < n)
//	{
//		if (0 == A[i])
//			return -1;
//		i++;
//	}
//	return flipCnt;
//}


//贪心算法，差分数组优化版。使用单指针遍历原始数组。当指针所指实际值为 0 时（值可通过初始值和当前位置翻转次数计算得到），更新当前位置翻转次数及相应位置的差分数组；如此进行至数组尾部时，若当前指针已进入最后一个翻转窗口但仍需翻转，则答案为不可能，否则返回翻转次数。
int minKBitFlips(vector<int>& A, int K)
{
	int n = A.size();
	int flipCnt = 0;
	vector<int> diff(n); //差分数组。差分数组 diff[i] 表示位置 i 相比于位置 i - 1 多需要翻转的次数
	int currentFlipCnt = 0; //当前位置的实际翻转次数

	//移动指针，计算当前位置元素是否需要翻转
	for (int i = 0; i < n; i++)
	{
		currentFlipCnt += diff[i];
		if (0 == (currentFlipCnt + A[i]) % 2) //当前位置需翻转
		{
			flipCnt++;
			currentFlipCnt++;
			if (i + K > n)
				return -1;
			if (i + K != n)
				diff[i + K]--;
		}
	}
	return flipCnt;
}


int main995()
{
	//vector<int> test = { 0,1,0 };
	//vector<int> test = { 1,1,0 };
	vector<int> test = { 0,0,0,1,0,1,1,0 };
	int ret = minKBitFlips(test, 3);
	cout << "main：ret = " << ret << endl;
	return 0;
}