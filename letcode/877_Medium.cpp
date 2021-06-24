#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
//
//游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
//
//亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
//
//假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。
//
//
//提示：
//
//	2 <= piles.length <= 500
//	piles.length 是偶数。
//	1 <= piles[i] <= 500
//	sum(piles) 是奇数。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/stone-game
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。维护一个二维数组：dp[i][j] 表示当只剩下区间 [i,j] 的石头堆时，先取的人可获得的最大净胜石头数。
//状态转移函数：dp[i][j] = max(piles[i] - dp[i + 1][j] ,piles[j] - dp[i][j - 1]) 。
//边界条件：dp[x][x] = piles[x] 。
//最优解：dp[0][n - 1] > 0 。
bool stoneGame(vector<int>& piles)
{
	int n = piles.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	//初始化 dp 数组边界条件
	for (int i = 0; i < n; i++)
		dp[i][i] = piles[i];

	//列优先遍历计算 dp 数组
	for (int j = 1; j < n; j++)
	{
		for (int i = j - 1; i >= 0; i--)
		{
			dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
		}
	}
	return dp[0][n - 1] > 0;
}


int main877()
{
	vector<int> test = { 5,3,4,5 };
	bool ret = stoneGame(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}