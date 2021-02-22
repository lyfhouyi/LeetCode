#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。
//
//
//提示：
//
//	1 <= nums.length <= 2500
//	- 10^4 <= nums[i] <= 10^4
//
//
//进阶：
//
//	你可以设计时间复杂度为 O(n^2) 的解决方案吗？
//	你能将算法的时间复杂度降低到 O(n log(n)) 吗 ?
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-increasing-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//一维动态规划。计算一个数组：dp[i] 表示以索引为 i 的元素结尾的子序列中的最长严格递增子序列的长度。
//状态转移函数：对 dp[i] ，遍历 nums 数组的 j ∈ [0,i - 1]，令 dp[i] 为满足 nums[j] < nums[i] 的 dp[j] 的最大值 + 1。若无满足  nums[j] < nums[i] 的 j ，则令 dp[i] = 1 。
//边界条件：dp[0] = 1 。
//最优解：dp[:] 的最大值。
//int lengthOfLIS(vector<int>& nums)
//{
//	int n = nums.size();
//	int j;
//	vector<int> dp(n, 1);
//	int maxLength = 0;
//	int currentLength;
//	for(int i = 0; i < n; i++)
//	{
//		currentLength = 0;
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (nums[j] < nums[i])
//				currentLength = currentLength > dp[j] ? currentLength : dp[j];
//		}
//		dp[i]= currentLength + 1;
//		maxLength = maxLength > dp[i] ? maxLength : dp[i];
//	}
//	return maxLength;
//}


//贪心算法。令上升子序列上升得尽可能慢，即令上升子序列的末元素尽可能小。维护数组 d[i] 表示长度为 i 的最长上升子序列的末尾元素可取到的最小值。
int lengthOfLIS(vector<int>& nums)
{
	int n = nums.size();
	vector<int> d(1, INT_MIN);
	int maxLength = 0;
	int l;
	int r;
	int mid;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] > d[maxLength])
		{
			maxLength++;
			d.push_back(nums[i]);
		}
		else
		{
			l = 0;
			r = maxLength; // maxLength = nums.size() - 1
			while (l != r - 1)
			{
				mid = (l + r) / 2;
				l = nums[i] <= d[mid] ? l : mid;
				r = nums[i] <= d[mid] ? mid : r;
			}
			d[r] = nums[i];
		}
	}
	return maxLength;
}


int main300()
{
	vector<int> test = { -10 ,8,6,5,1,3,38,6,7,2,11,12,13,14 };
	//vector<int> test = { 10 ,9,2,5,3,7,101,18};
	//vector<int> test = { 1,3,5,4,7 };
	//vector<int> test = { 0 ,1,0,3,2,3 };
	//vector<int> test = {7,7,7,7,7,7 };
	//vector<int> test = { };
	int ret = lengthOfLIS(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}