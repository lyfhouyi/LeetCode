#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//在给定的网格中，每个单元格可以有以下三个值之一：
//
//	值 0 代表空单元格；
//	值 1 代表新鲜橘子；
//	值 2 代表腐烂的橘子。
//	每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
//
//返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 - 1。
//
//
//提示：
//
//	1 <= grid.length <= 10
//	1 <= grid[0].length <= 10
//	grid[i][j] 仅为 0、1 或 2
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/rotting-oranges
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//广度优先搜索。使用队列存储最新腐烂的橘子。首先遍历原始数组，将当前已腐烂的橘子的位置压入队列；随后循环取出队列（直到已没有新鲜的橘子或没有新的橘子腐烂），将当前橘子的相邻橘子置为腐烂，并将其压入队列，同时更新最新腐烂的橘子数及腐烂用时；循环完成后，若仍有新鲜的橘子，则返回 -1 ，否则返回腐烂用时。
int orangesRotting(vector<vector<int>>& grid)
{
	int freshCnt = 0; //新鲜橘子的数量
	int lastRotCnt = 0; //最新腐烂的橘子的数量
	queue<int> rotQueue; //腐烂队列
	int m = grid.size();
	int n = grid[0].size();
	for (int i = 0; i < m; i++) //初始化腐烂队列
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1)
				freshCnt++;
			else if (grid[i][j] == 2)
			{
				rotQueue.push(i * n + j);
				lastRotCnt++;
			}
		}
	}

	int decayTime = 0;
	int newRotCnt;
	while (freshCnt != 0 && lastRotCnt != 0) //已没有新鲜的橘子或没有新的橘子腐烂时退出循环
	{
		newRotCnt = 0;
		while (lastRotCnt != 0) //最新腐烂的橘子腐烂其相邻的橘子
		{
			int i = rotQueue.front() / n;
			int j = rotQueue.front() % n;
			rotQueue.pop();
			if (i != 0 && grid[i - 1][j] == 1) //腐烂上方的橘子
			{
				grid[i - 1][j] = 2;
				rotQueue.push((i - 1)*n + j);
				newRotCnt++;
				freshCnt--;
			}
			if (i != m - 1 && grid[i + 1][j] == 1) //腐烂下方的橘子
			{
				grid[i + 1][j] = 2;
				rotQueue.push((i + 1)*n + j);
				newRotCnt++;
				freshCnt--;
			}
			if (j != 0 && grid[i][j - 1] == 1) //腐烂左方的橘子
			{
				grid[i][j - 1] = 2;
				rotQueue.push(i*n + j - 1);
				newRotCnt++;
				freshCnt--;
			}
			if (j != n - 1 && grid[i][j + 1] == 1) //腐烂右方的橘子
			{
				grid[i][j + 1] = 2;
				rotQueue.push(i*n + j + 1);
				newRotCnt++;
				freshCnt--;
			}
			lastRotCnt--;
		}
		lastRotCnt = newRotCnt;
		decayTime++; //更新腐烂用时
	}
	if (freshCnt != 0)
		return -1;
	return decayTime;
}


int main994()
{
	//vector<vector<int>> test = { {0,2} };
	vector<vector<int>> test = { {2,1,1},{0,1,1},{1,0,1} };
	//vector<vector<int>> test = { {2,1,1},{1,1,0},{0,1,1} };
	int ret = orangesRotting(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}