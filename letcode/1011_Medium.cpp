#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
//
//传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
//
//返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
//
//
//提示：
//
//	1 <= D <= weights.length <= 50000
//	1 <= weights[i] <= 500
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。维护一个二维数组：dp[i][j] 表示在 i + 1 天内将传送带上 [0:j] 范围内的所有包裹送达的船的最低运载能力。
//状态转移函数：dp[i][j] = min(max(dp[i - 1][x - 1],sum(weights[x:j]))) ，其中 x ∈ [0,j]
//边界条件：dp[0][j] = sum(weights[0:j]) 。
//最优解：dp[D-1][n-1] 。
int shipWithinDays(vector<int>& weights, int D)
{
	int n = weights.size();
	vector<vector<int>> dp(D, vector<int>(n, INT_MAX));
	dp[0][0] = weights[0];
	for (int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + weights[j];
	int currentCapacity;
	for (int i = 1; i < D; i++)
	{
		for (int j = i; j < n; j++)
		{
			int lastDay = 0;
			for (int tmpIndex = j; tmpIndex > 0; tmpIndex--)
			{
				lastDay += weights[tmpIndex];
				currentCapacity = dp[i - 1][tmpIndex - 1] > lastDay ? dp[i - 1][tmpIndex - 1] : lastDay;
				dp[i][j] = dp[i][j] < currentCapacity ? dp[i][j] : currentCapacity;
				if (lastDay >= dp[i - 1][tmpIndex - 1]) //剪枝：最后一天的运载量过大时，可以提前退出循环，因为后面的 currentCapacity 只会更大
					break;
			}
		}
	}
	return dp[D - 1][n - 1];
}


int main()
{
	vector<int> test = { 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> test = { 1,2,3,1,1 };
	//vector<int> test = { 3,2,2,4,1,4};
	int ret = shipWithinDays(test, 5);
	cout << "main：ret = " << ret << endl;
	return 0;
}