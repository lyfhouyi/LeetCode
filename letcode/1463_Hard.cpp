#include<iostream>
#include<vector>
#include<climits>

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


class Mydp
{
public:
	Mydp(int rows, int cols) :rows(rows), cols(cols), dp(rows, vector<vector<int>>(cols, vector<int>(cols, INT_MIN))) {};
	void set(int r, int c1, int c2, int value)
	{
		dp[r][c1][c2] = value;
	}
	int get(int r, int c1, int c2)
	{
		if (c1<0 || c1>cols - 1 || c2<0 || c2 > cols - 1)
			return INT_MIN;
		return dp[r][c1][c2];
	}

	//计算（上一时刻的）九种可能状态的最大值。上一时刻的就种可能状态：dp[r - 1][c1 - 1][c2 - 1],dp[r - 1][c1 - 1][c2],dp[r - 1][c1 - 1][c2 + 1],dp[r - 1][c1][c2 - 1],dp[r - 1][c1][c2],dp[r - 1][c1][c2 + 1],dp[r - 1][c1 + 1][c2 - 1],dp[r - 1][c1 + 1][c2],dp[r - 1][c1 + 1][c2 + 1]
	int myMax(int r, int c1, int c2)
	{
		int ret = INT_MIN;
		int tmp;
		for (int j1 = c1 - 1; j1 <= c1 + 1; j1++)
		{
			for (int j2 = c2 - 1; j2 <= c2 + 1; j2++)
			{
				tmp = this->get(r - 1, j1, j2);
				ret = ret > tmp ? ret : tmp;
			}
		}
		return ret;
	}
private:
	int rows;
	int cols;
	vector<vector<vector<int>>> dp;
};


//三维动态规划。维护一个三维数组：dp[r][c1][c2] 表示二机器人分别到达网格 (r,c1),(r,c2) 时（如果可以）手里最多摘到的樱桃数量。
//状态转移函数：dp[r][c1][c2] = max(dp[r - 1][c1 - 1][c2 - 1],dp[r - 1][c1 - 1][c2],dp[r - 1][c1 - 1][c2 + 1],dp[r - 1][c1][c2 - 1],dp[r - 1][c1][c2],dp[r - 1][c1][c2 + 1],dp[r - 1][c1 + 1][c2 - 1],dp[r - 1][c1 + 1][c2],dp[r - 1][c1 + 1][c2 + 1]) + grid[r][c1] + grid[r][c2]，当 (r,c1) != (r,c2) 时（等于时只加一次 grid[rows][c1] ） 。
//边界条件：dp[:][:][:] = INT_MIN ，dp[0][0][cols - 1] 除外；dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1]。
//最优解：dp[rows - 1][:][:] 的最大值。
int cherryPickup1463(vector<vector<int>>& grid)
{
	int rows = grid.size();
	int cols = grid[0].size();
	Mydp mydp(rows, cols);
	mydp.set(0, 0, cols - 1, grid[0][0] + grid[0][cols - 1]); //初始化边界条件
	int cherryCnt = 0;
	int currentPickup;
	for (int r = 1; r < rows; r++)
	{
		int upperBound = r < cols - 1 ? r : cols - 1;
		int lowerBound = 0 > cols - 1 - r ? 0 : cols - 1 - r;
		for (int c1 = 0; c1 <= upperBound; c1++)
		{
			for (int c2 = lowerBound; c2 <= cols - 1; c2++)
			{
				if (c1 == c2)
					currentPickup = mydp.myMax(r, c1, c2) + grid[r][c1];
				else
					currentPickup = mydp.myMax(r, c1, c2) + grid[r][c1] + grid[r][c2];
				mydp.set(r, c1, c2, currentPickup);
				if (r == rows - 1)
					cherryCnt = cherryCnt > currentPickup ? cherryCnt : currentPickup;
			}
		}
	}
	return cherryCnt;
}


int main1463()
{
	//vector<vector<int>> test = { {3,1,1},{2,5,1},{1,5,5},{2,1,1} };
	vector<vector<int>> test = { {1,1},{1,1} };
	//vector<vector<int>> test = { {1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3} };
	//vector<vector<int>> test = { {1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6} };
	int ret = cherryPickup1463(test);
	std::cout << "main：ret = " << ret << endl;
	return 0;
}