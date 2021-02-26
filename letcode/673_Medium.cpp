#include<iostream>
#include<vector>

using namespace std;

//给定一个未排序的整数数组，找到最长递增子序列的个数。
//
//
//注意 : 给定的数组长度不超过 2000 并且结果一定是32位有符号整数
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//一维动态规划。维护两个数组：dp[i] 表示以索引为 i 的元素结尾的子序列中的最长严格递增子序列的长度。cnt[i] 表示以索引为 i 的元素结尾的子序列中取得最长严格递增子序列时的可行解（“路径”）个数。
//状态转移函数：对 dp[i] ，遍历 nums 数组的 j ∈ [0,i - 1]，令 dp[i] 为满足 nums[j] < nums[i] 的 dp[j] 的最大值 + 1，令 cnt[i] 为与该 dp[j] 数值相等的可行解（“路径”）的个数的总和。若无满足  nums[j] < nums[i] 的 j ，则令 dp[i] = 1 ，cnt[i] = 1 。
//边界条件：dp[0] = 1 。
//最优解：dp[:] 取得最大值时对应的 cnt[i] 的总和。
int findNumberOfLIS(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(n, 1);
	vector<int> cnt(n, 1);
	int currentLength;
	int feasibleCnt;
	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		//维护 dp 数组、cnt 数组
		currentLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				if (dp[j] > currentLength)
				{
					currentLength = dp[j];
					cnt[i] = cnt[j];
				}
				else
				{
					if (dp[j] == currentLength)
						cnt[i] += cnt[j];
				}
			}
		}
		dp[i] = currentLength + 1;

		//记录 dp 数组的最大值处对应的 cnt 值的总和
		if (dp[i] > maxLength)
		{
			maxLength = dp[i];
			feasibleCnt = cnt[i];
		}
		else
		{
			if (dp[i] == maxLength)
				feasibleCnt += cnt[i];
		}
	}
	return feasibleCnt;
}




int main673()
{
	vector<int> test = { 0,8,4,12,2,3 };
	//vector<int> test = { 2,2,2,2,2 };
	//vector<int> test = { 1,3,5,4,7 };
	int ret = findNumberOfLIS(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}