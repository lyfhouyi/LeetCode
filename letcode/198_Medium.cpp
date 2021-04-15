#include<iostream>
#include<vector>

using namespace std;

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//
//
//提示：
//
//	0 <= nums.length <= 100
//	0 <= nums[i] <= 400
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/house-robber
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//一维动态规划。维护一个二维数组：dp[i] 表示在 nums[i,n - 1] 上能够偷窃到的最高金额。
//状态转移函数：dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]) 。
//边界条件：dp[:] = 0 。
//最优解：dp[0] 的值。
int rob198(vector<int>& nums)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	vector<int> dp(n + 2, 0);
	for (int i = n - 1; i >= 0; i--)
		dp[i] = nums[i] + dp[i + 2] > dp[i + 1] ? nums[i] + dp[i + 2] : dp[i + 1];
	return dp[0];
}


int main198()
{
	//vector<int> test = { 2,7,9,3,1 };
	//vector<int> test = { 1,2,3,1 };
	//vector<int> test = { 1,4,5,2,1 };
	vector<int> test = { 1 };
	//vector<int> test = { 1,2,1,1 };
	int ret = rob198(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}