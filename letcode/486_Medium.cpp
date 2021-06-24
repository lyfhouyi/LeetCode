#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
//
//给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
//
//
//提示：
//
//	1 <= 给定的数组长度  <= 20.
//	数组里所有分数都为非负数且不会大于 10000000 。
//	如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/predict-the-winner
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。维护一个二维数组：dp[i][j] 表示当只剩下区间 [i,j] 的石头堆时，先取的人可获得的最大净胜石头数。
//状态转移函数：dp[i][j] = max(nums[i] - dp[i + 1][j] ,nums[j] - dp[i][j - 1]) 。
//边界条件：dp[x][x] = nums[x] 。
//最优解：dp[0][n - 1] > 0 。
bool PredictTheWinner(vector<int>& nums)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	//初始化 dp 数组边界条件
	for (int i = 0; i < n; i++)
		dp[i][i] = nums[i];

	//列优先遍历计算 dp 数组
	for (int j = 1; j < n; j++)
	{
		for (int i = j - 1; i >= 0; i--)
		{
			dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
		}
	}
	return dp[0][n - 1] >= 0;
}


int main486()
{
	vector<int> test = { 1,5,2 };
	bool ret = PredictTheWinner(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}