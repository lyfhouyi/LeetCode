#include<iostream>
#include<vector>

using namespace std;

//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//
//题目数据保证答案符合 32 位整数范围。
//
//
//提示：
//
//	1 <= nums.length <= 200
//	1 <= nums[i] <= 1000
//	nums 中的所有元素 互不相同
//	1 <= target <= 1000
//
//
//进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/combination-sum-iv
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//回溯算法。根据当前组合元素和 currentSum 判断下一步可以将哪个元素加入到当前组合中。回溯于下一步加入当前组合的是哪一个元素；递归基：当前组合元素和满足要求时，将可行组合数 ret 加一。
void validCombination(vector<int>& nums, int currentSum, int target, int& ret)
{
	if (currentSum == target)
	{
		cout << "find:" << ret << endl;
		ret++;
		return;
	}
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (nums[i] + currentSum <= target)
			validCombination(nums, nums[i] + currentSum, target, ret);
	}
	return;
}


//递归。递归调用 validCombination() 函数，判断应在当前组合中加入哪个元素。
//算法正确，但时间超时。
//int combinationSum4(vector<int>& nums, int target)
//{
//	int ret = 0;
//	validCombination(nums, 0, target, ret);
//	return ret;
//}


//一维动态规划。维护一个一维数组：dp[i] 表示元素之和为 i 的组合的个数。
//状态转移函数：dp[i] = sum(dp[i - nums[j]]) ，其中 nums[j] <= i 。
//边界条件：dp[:] = 0 ，dp[0] = 1 。
//最优解：dp[target] 的值。
int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	int n = nums.size();
	//遍历计算 dp 数组
	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (nums[j] <= i && dp[i - nums[j]] < INT_MAX - dp[i])
				dp[i] += dp[i - nums[j]];
		}
	}
	return dp[target];
}


int main377()
{
	//vector<int> test = { 1,2,3 };
	vector<int> test = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111 };
	//vector<int> test = { 9 };
	int ret = combinationSum4(test, 999);
	cout << "main：ret = " << ret << endl;
	return 0;
}