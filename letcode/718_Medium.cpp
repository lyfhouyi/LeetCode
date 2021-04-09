#include<iostream>
#include<vector>

using namespace std;

//给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
//
//
//提示：
//
//	1 <= len(A), len(B) <= 1000
//	0 <= A[i], B[i] < 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：二维动态规划。维护一个二维数组：dp[i][j] 表示分别以 A[i - 1]、B[j - 1] 结尾的公共子数组的最大长度。
//状态转移函数：dp[i][j] = dp[i - 1][j - 1] + 1 ，当 A[i - 1] == B[j - 1] 时，0，当 A[i - 1] != B[j - 1] 时。
//边界条件：dp[:][:] = 0 。
//最优解：dp[:][:] 的最大值。
//int findLength(vector<int>& A, vector<int>& B)
//{
//	int m = A.size();
//	int n = B.size();
//	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//
//	int maxLength = 0;
//	//行优先遍历
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (A[i - 1] == B[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = 0;
//			maxLength = maxLength > dp[i][j] ? maxLength : dp[i][j];
//		}
//	}
//	return maxLength;
//}


//解法二：滑动数组。逻辑上，固定数组 A 不动，拉动数组 B ；对每个对齐位置组合，计算当前对齐位置的公共子数组的最大长度，共 M + N - 1 个对齐位置组合；各对齐位置组合的公共子数组的最大长度的最大值即为所求；实现上，使用 beginA、beginB 表征对齐位置。
int findLength(vector<int>& A, vector<int>& B)
{
	int m = A.size();
	int n = B.size();
	int maxLength = 0;
	int curLength;
	int curMaxLength;
	int beginA = m - 1;
	int beginB = 0;
	while (beginB < n) //遍历每一个对齐位置组合
	{
		curMaxLength = 0;
		curLength = 0;
		for (int i = 0; beginA + i < m && beginB + i < n; i++) //计算当前对齐位置的公共子数组的最大长度。
		{
			if (A[beginA + i] == B[beginB + i])
				curLength++;
			else
				curLength = 0;
			curMaxLength = curMaxLength > curLength ? curMaxLength : curLength;
		}
		maxLength = curMaxLength > maxLength ? curMaxLength : maxLength;
		if (beginA != 0)
			beginA--;
		else
			beginB++;
	}
	return maxLength;
}


int main718()
{
	vector<int> A = { 1,2,3,2,1 };
	vector<int> B = { 3,2,1,4,7 };
	int ret = findLength(A, B);
	cout << "maina：ret = " << ret << endl;
	return 0;
}