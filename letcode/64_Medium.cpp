#include<iostream>
#include<vector>

using namespace std;

//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//
//提示：
//
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 200
//	0 <= grid[i][j] <= 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/minimum-path-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//计算相邻格子的最小值
int myMin(vector<vector<int>>& dp, int i, int j)
{
	int n = dp.size();
	if (i - 1 < 0)
		return dp[i][j - 1];
	if (j - 1 < 0)
		return dp[i - 1][j];
	return dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
}


//二维动态规划。维护一个二维数组：dp[i][j] 表示到达网格 (i,j) 时的最小路径和。
//状态转移函数：dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j] 。
//边界条件：dp[0][0] = grid[0][0] 。
//最优解：dp[m - 1][n - 1] 的值。
//int minPathSum(vector<vector<int>>& grid)
//{
//	int m = grid.size();
//	int n = grid[0].size();
//	vector<vector<int>> dp(m, vector<int>(n, 0));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (0 == i && 0 == j)
//			{
//				dp[i][j] = grid[0][0];
//				continue;
//			}
//			dp[i][j] = myMin(dp, i, j) + grid[i][j];
//		}
//	}
//	return dp[m - 1][n - 1];
//}


//二维动态规划。维护一个二维数组：dp[i][j] 表示到达网格 (i,j) 时的最小路径和。
//状态转移函数：dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j] 。
//边界条件：dp[0][0] = grid[0][0] 。
//最优解：dp[m - 1][n - 1] 的值。
//滚动数组优化。使用单行的一维数组替代二维数组。
int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<int> dp(n, INT_MAX);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (0 == i && 0 == j)
			{
				dp[j] = grid[0][0];
				continue;
			}
			if (0 == j)
				dp[j] = dp[j] + grid[i][j];
			else
				dp[j] = (dp[j - 1] < dp[j] ? dp[j - 1] : dp[j]) + grid[i][j];
		}
	}
	return dp[n - 1];
}


int main64()
{
	//vector<vector<int>> test = { {3} };
	vector<vector<int>> test = { {1,2,3},{4,5,6} };
	//vector<vector<int>> test = { {1,3,1},{1,5,1},{4,2,1} };
	int ret = minPathSum(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}