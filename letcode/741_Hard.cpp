#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//一个N x N的网格(grid) 代表了一块樱桃地，每个格子由以下三种数字的一种来表示：
//
//	0 表示这个格子是空的，所以你可以穿过它。
//	1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
//	- 1 表示这个格子里有荆棘，挡着你的路。
//
//你的任务是在遵守下列规则的情况下，尽可能的摘到最多樱桃：
//
//	从位置 (0, 0) 出发，最后到达(N - 1, N - 1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为0或者1的格子）；
//	当到达(N - 1, N - 1) 后，你要继续走，直到返回到(0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
//	当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为0）；
//	如果在(0, 0) 和(N - 1, N - 1) 之间不存在一条可经过的路径，则没有任何一个樱桃能被摘到。
//
//说明 :
//
//	grid 是一个 N * N 的二维数组，N的取值范围是1 <= N <= 50。
//	每一个 grid[i][j] 都是集合 { -1, 0, 1 }其中的一个数。
//	可以保证起点 grid[0][0] 和终点 grid[N - 1][N - 1] 的值都不会是 - 1。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/cherry-pickup
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//计算相邻格子的最大值及方向
int myMax(vector<vector<int>>& dp, int i, int j, char dir, char& ori)
{
	int n = dp.size();
	if ('g' == dir) //“出发”路径
	{
		if (i - 1 < 0)
		{
			ori = 'u';
			return dp[i][j - 1];
		}
		if (j - 1 < 0)
		{
			ori = 'l';
			return dp[i - 1][j];
		}
		ori = dp[i - 1][j] > dp[i][j - 1] ? 'l' : 'u';
		return dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
	}
	else //“返回”路径
	{
		if (i + 1 > n - 1)
		{
			ori = 'd';
			return  dp[i][j + 1];
		}
		if (j + 1 > n - 1)
		{
			ori = 'r';
			return dp[i + 1][j];
		}
		ori = dp[i + 1][j] > dp[i][j + 1] ? 'r' : 'd';
		return dp[i + 1][j] > dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];
	}
}


//计算（上一时刻的）四种可能状态的最大值。上一时刻的四种可能状态：dp[r1 - 1][r2 - 1][c2], dp[r1 - 1][r2][c2 - 1], dp[r1][r2 - 1][c2], dp[r1][r2][c2 - 1]
int myMax4(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r1, int r2, int s)
{
	if (0 == s)
		return 0;
	if (((r1 == 0 || -1 == grid[r1 - 1][s - r1]) && (r1 == s || -1 == grid[r1][s - r1 - 1])) || ((r2 == 0 || -1 == grid[r2 - 1][s - r2]) && (r2 == s || -1 == grid[r2][s - r2 - 1])))
		return -1;
	int tmp1 = INT_MIN;
	if (r1 != 0)
	{
		if (0 == r2)
			tmp1 = dp[r1 - 1][r2][s - 1 - r2];
		else
		{
			if (s == r2)
				tmp1 = dp[r1 - 1][r2 - 1][s - r2];
			else
				tmp1 = dp[r1 - 1][r2 - 1][s - r2] > dp[r1 - 1][r2][s - 1 - r2] ? dp[r1 - 1][r2 - 1][s - r2] : dp[r1 - 1][r2][s - 1 - r2];
		}
	}

	int tmp2 = INT_MIN;
	if (r1 != s)
	{
		if (0 == r2)
			tmp2 = dp[r1][r2][s - 1 - r2];
		else
		{
			if (s == r2)
				tmp2 = dp[r1][r2 - 1][s - r2];
			else
				tmp2 = dp[r1][r2 - 1][s - r2] > dp[r1][r2][s - r2 - 1] ? dp[r1][r2 - 1][s - r2] : dp[r1][r2][s - r2 - 1];
		}
	}
	return tmp1 > tmp2 ? tmp1 : tmp2;
}


//贪心算法。首先考察“出发”路径；随后根据 dp 数组计算“出发”路径途径的网格，并摘取其中的樱桃；最后根据调整后的 grid 数组考察“返回”路径；最终得到的 dp[0][0] 即为所求。
//二维动态规划。将问题分为“出发”和“返回”两条路径。对每条路径分别维护一个二维数组：dp[i][j] 表示到达网格 (i,j) 时（如果可以）手里最多摘到的樱桃数量。
//状态转移函数：“出发”：dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) + grid[i][j] ，当 max(dp[i - 1][j],dp[i][j - 1]) != -1 时，-1 ，当 max(dp[i - 1][j],dp[i][j - 1]) == -1 时；“返回”：dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]) + grid[i][j] ，当 max(dp[i + 1][j],dp[i][j + 1]) != -1 时，-1 ，当 max(dp[i + 1][j],dp[i][j + 1]) == -1 时。
//边界条件：“出发”：dp[0][0] = grid[0][0] ；“返回”：dp[n - 1][n - 1] = grid[n - 1][n - 1] 。
//最优解：若“出发”的 dp[n - 1][n - 1] == -1 ，则返回 0 ；否则返回“出发”的 dp[n - 1][n - 1] + “返回”的 dp[0][0] 。
//代码优化：“出发”和“返回”两条路径的 dp 数组可仅用一个 dp 数组实现，只需将“返回”路径的边界 dp[n - 1][n - 1] 置为“出发”路径的 dp[n - 1][n - 1] 即可，此时所求为“返回”路径维护后的 dp[0][0] 。
//该算法是错误的！
//int cherryPickup741(vector<vector<int>>& grid)
//{
//	int n = grid.size();
//	int tmp;
//	char ori;
//	vector<vector<int>> dp(grid);
//	for (int i = 0; i < n; i++) //维护路径“出发”的 dp 数组
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if ((0 == i & 0 == j) || -1 == grid[i][j])
//				continue;
//			tmp = myMax(dp, i, j, 'g', ori);
//			if (-1 == tmp)
//				dp[i][j] = -1;
//			else
//				dp[i][j] = tmp + grid[i][j];
//		}
//	}
//
//	if (-1 == dp[n - 1][n - 1])
//		return 0;
//
//	int i = n - 1;
//	int j = n - 1;
//	while (i != 0 || j != 0) //调整“出发”路径上的网格值（樱桃数量）
//	{
//		myMax(dp, i, j, 'g', ori);
//		if ('u' == ori) //从上方摘樱桃而来
//		{
//			grid[i][j - 1] = 0;
//			j--;
//		}
//		else //从左方摘樱桃而来
//		{
//			grid[i - 1][j] = 0;
//			i--;
//		}
//	}
//
//	for (int i = n - 1; i >= 0; i--) //维护路径“返回”的 dp 数组
//	{
//		for (int j = n - 1; j >= 0; j--)
//		{
//			if ((n - 1 == i & n - 1 == j) || -1 == grid[i][j])
//				continue;
//			tmp = myMax(dp, i, j, 'b', ori);
//			if (-1 == tmp)
//				dp[i][j] = -1;
//			else
//				dp[i][j] = tmp + grid[i][j];
//		}
//	}
//	return dp[0][0];
//}


//将问题转化为：两个人从左上角同时出发，只能向右或向下移动，经过 2 * (n - 1) 步后，同时到达右下角，求二人沿途摘到的樱桃数量之和。设二人的坐标分别为 (r1,c1),(r2,c2) ，则可用三维动态规划求解。
//三维动态规划。维护一个三维数组：dp[r1][r2][c2] 表示二人分别到达网格 (r1,r2 + c2 - r1),(r2,c2) 时（如果可以）手里最多摘到的樱桃数量。
//状态转移函数：dp[r1][r2][c2] = max(dp[r1 - 1][r2 - 1][c2],dp[r1 - 1][r2][c2 - 1],dp[r1][r2 - 1][c2],dp[r1][r2][c2 - 1]) + grid[r1][r2 + c2 - r1] + grid[r2][c2]，当 (r1,c1) != (r2,c2) 时（等于时只加一次 grid[r2][c2] ），-1 ，当 max(dp[r1 - 1][r2 - 1][c2],dp[r1 - 1][r2][c2 - 1]) == -1 或 max(dp[r1][r2 - 1][c2],dp[r1][r2][c2 - 1]) == -1 时。
//边界条件：dp[0][0][0] = grid[0][0] 。
//最优解：dp[n - 1][n - 1][n - 1] 。
int cherryPickup741(vector<vector<int>>& grid)
{
	int n = grid.size();
	int sMax = 2 * (n - 1); //移动 sMax 步后到达右下角
	int tmp;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
	for (int s = 0; s <= sMax; s++) //遍历各步
	{
		for (int r1 = 0; r1 <= s && r1 < n; r1++)
		{
			if (s - r1 >= n) // 1 号人的位置非法
				continue;
			//此时 1 号人的位置在 (r1,i - r1)

			for (int r2 = 0; r2 <= s && r2 < n; r2++)
			{
				if (s - r2 >= n) // 2 号人的位置非法
					continue;
				//此时 2 号人的位置在 (r2,i - r2)

				if ((-1 == grid[r1][s - r1]) || (-1 == grid[r2][s - r2])) //当前网格由于有荆棘无法到达
					continue;

				tmp = myMax4(grid, dp, r1, r2, s);
				if (-1 == tmp) //当前网格由于相邻网格有荆棘无法到达
					dp[r1][r2][s - r2] = -1;
				else
				{
					if (r1 == r2) //二人位置重合
						dp[r1][r2][s - r2] = tmp + grid[r1][s - r1];
					else //二人位置不重合
						dp[r1][r2][s - r2] = tmp + grid[r1][s - r1] + grid[r2][s - r2];
				}
			}

		}
	}
	if (-1 == dp[n - 1][n - 1][n - 1])
		return 0;
	return dp[n - 1][n - 1][n - 1];
}


int main741()
{	
	//vector<vector<int>> test = { {3} };
	vector<vector<int>> test = { {1,1,1,1,1},{1,1,-1,1,1},{-1,-1,1,1,1},{1,1,1,1,1},{-1,1,1,1,1} };
	//vector<vector<int>> test = { {1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1} };
	//vector<vector<int>> test = { {0,1,-1},{1,0,-1},{1,-1,1} };
	//vector<vector<int>> test = { {1,1,-1},{1,-1,1},{-1,1,1} };
	int ret = cherryPickup741(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}