#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对(answer[i], answer[j]) 都应当满足：
//	answer[i] % answer[j] == 0 ，或
//	answer[j] % answer[i] == 0
//如果存在多个有效解子集，返回其中任何一个均可。
//
//
//提示：
//
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 10^9
//	nums 中的所有整数 互不相同
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/largest-divisible-subset
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//一维动态规划。计算一个数组：dp[i] 表示在输入数组 nums 升序排列的前提下，以 nums[i] 为最大整数的整除子集的最大长度。
//状态转移函数：对 dp[i] ，遍历升序排列的 nums 数组的 j ∈ [0,i - 1]，令 dp[i] 为满足 nums[j] 可以被 nums[i] 整除的 dp[j] 的最大值 + 1。若无满足 nums[j] 可以被 nums[i] 整除的 j ，则令 dp[i] = 1 。
//边界条件：max(dp[j]) = 0 ，当没有 j 满足条件时。
//最优解：dp[:] 取得最大值处所构成的子集（需通过倒推得到）。
//首先将输入数组 nums 升序排列；随后使用一维动态规划计算以 nums[i] 为最大整数的整除子集的最大长度；最后倒推计算dp[:] 取得最大值处所构成的子集，即为所求。
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();

	//遍历计算 dp 数组
	vector<int> dp(n, 1);
	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		int currentMaxLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
				currentMaxLength = currentMaxLength > dp[j] ? currentMaxLength : dp[j];
		}
		dp[i] = currentMaxLength + 1;
		maxLength = maxLength > dp[i] ? maxLength : dp[i];
	}

	//倒推计算最大整除子集
	vector<int> ret;
	for (int i = n - 1; i >= 0; i--)
	{
		if (dp[i] == maxLength && (ret.empty() || ret.back() % nums[i] == 0))
		{
			ret.push_back(nums[i]);
			maxLength--;
		}
	}
	return ret;
}


int main368()
{
	//vector<int> test = { 1,2,3,4,6,8,18,54,109 };
	//vector<int> test = { 1,2,4,8 };
	vector<int> test = { 5, 9, 18, 54, 108, 540, 90, 180, 360, 720 };
	//vector<int> test = { 1 };
	vector<int> ret = largestDivisibleSubset(test);
	cout << "main：ret = ";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
		cout << *it << "  ";
	return 0;
}