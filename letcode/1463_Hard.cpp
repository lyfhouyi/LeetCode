#include<iostream>
#include<vector>

using namespace std;

//给你一个 rows x cols 的矩阵 grid 来表示一块樱桃地。 grid 中每个格子的数字表示你能获得的樱桃数目。
//
//你有两个机器人帮你收集樱桃，机器人 1 从左上角格子(0, 0) 出发，机器人 2 从右上角格子(0, cols - 1) 出发。
//
//请你按照如下规则，返回两个机器人能收集的最多樱桃数目：
//
//从格子 (i, j) 出发，机器人可以移动到格子 (i + 1, j - 1)，(i + 1, j) 或者 (i + 1, j + 1) 。
//当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
//当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
//两个机器人在任意时刻都不能移动到 grid 外面。
//两个机器人最后都要到达 grid 最底下一行。
//
//
//提示：
//
//	rows == grid.length
//	cols == grid[i].length
//	2 <= rows, cols <= 70
//	0 <= grid[i][j] <= 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/cherry-pickup-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//三维动态规划。维护一个三维数组：dp[r1][r2][c2] 表示二人分别到达网格 (r1,r2 + c2 - r1),(r2,c2) 时（如果可以）手里最多摘到的樱桃数量。
//状态转移函数：dp[r1][r2][c2] = max(dp[r1 - 1][r2 - 1][c2],dp[r1 - 1][r2][c2 - 1],dp[r1][r2 - 1][c2],dp[r1][r2][c2 - 1]) + grid[r1][r2 + c2 - r1] + grid[r2][c2]，当 (r1,c1) != (r2,c2) 时（等于时只加一次 grid[r2][c2] ），-1 ，当 max(dp[r1 - 1][r2 - 1][c2],dp[r1 - 1][r2][c2 - 1]) == -1 或 max(dp[r1][r2 - 1][c2],dp[r1][r2][c2 - 1]) == -1 时。
//边界条件：dp[0][0][0] = grid[0][0] 。
//最优解：dp[n - 1][n - 1][n - 1] 。
int cherryPickup(vector<vector<int>>& grid)
{
	return 0;
}


int main1463()
{
	//vector<vector<int>> test = { {3} };
	vector<vector<int>> test = { {1,1,1,1,1},{1,1,-1,1,1},{-1,-1,1,1,1},{1,1,1,1,1},{-1,1,1,1,1} };
	//vector<vector<int>> test = { {1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1} };
	//vector<vector<int>> test = { {0,1,-1},{1,0,-1},{1,-1,1} };
	//vector<vector<int>> test = { {1,1,-1},{1,-1,1},{-1,1,1} };
	int ret = cherryPickup(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}