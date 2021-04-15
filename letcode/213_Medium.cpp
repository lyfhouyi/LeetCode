#include<iostream>
#include<vector>

using namespace std;


//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
//
//
//提示：
//
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 1000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/house-robber-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。维护一个二维数组：dp[i][j] 表示在 nums[i,j] 上能够偷窃到的最高金额。
//状态转移函数：dp[i][j] = max(nums[i] + dp[i + 2][j - 1], dp[i + 1][j]) ，当 i != 0 || j != n - 1 时；dp[0][n - 1] = nums[0] + dp[2][n - 2] > dp[1][n - 1] ? nums[0] + dp[2][n - 2] : dp[1][n - 1] 。
//边界条件：dp[:][:] = 0 。
//最优解：dp[0][n - 1] 的值。
//int rob213(vector<int>& nums)
//{
//	int n = nums.size();
//	if (n == 1)
//		return nums[0];
//	vector<vector<int>> dp(n + 2, vector<int>(n, 0));
//	//列优先遍历计算 dp 数组
//	for (int j = 0; j < n; j++)
//	{
//		dp[j][j] = nums[j];
//		for (int i = j; i >= 0; i--)
//		{
//			if (i == j)
//				dp[j][j] = nums[j];
//			else
//				dp[i][j] = nums[i] + dp[i + 2][j] > dp[i + 1][j] ? nums[i] + dp[i + 2][j] : dp[i + 1][j];
//		}
//	}
//	return (nums[0] + dp[2][n - 2] > dp[1][n - 1] ? nums[0] + dp[2][n - 2] : dp[1][n - 1]);
//}


//一维动态规划。维护一个二维数组：dp[i] 表示在 nums[i,indexLast] 上能够偷窃到的最高金额。
//状态转移函数：dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]) 。
//边界条件：dp[:] = 0 。
//最优解：dp[indexBegin] 的值。
int calcRob(vector<int>& nums, int indexBegin, int indexLast)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	vector<int> dp(n + 1, 0);
	dp[indexLast] = nums[indexLast];
	for (int i = indexLast - 1; i >= indexBegin; i--)
		dp[i] = nums[i] + dp[i + 2] > dp[i + 1] ? nums[i] + dp[i + 2] : dp[i + 1];
	return dp[indexBegin];
}


//动态规划。计算偷窃区间分别为 [0,n - 2] 和 [1,n - 1] 的二者的较大值。
int rob213(vector<int>& nums)
{
	int n = nums.size();
	int front = calcRob(nums, 0, n - 2);
	int back = calcRob(nums, 1, n - 1);
	return front > back ? front : back;
}


int main213()
{
	//vector<int> test = { 1,2,3,1 };
	//vector<int> test = { 1,4,5,2,1 };
	vector<int> test = { 1 };
	//vector<int> test = { 1,2,1,1 };
	int ret = rob213(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}