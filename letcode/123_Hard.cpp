#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>


using namespace std;


//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//提示：
//
//1 <= prices.length <= 105
//0 <= prices[i] <= 105
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//动态规划。计算两个数组：buy[i][j] 表示下标第 i 天操作后，持有股票、已完成 j 次交易的情况下，手上持有的现金；sell[i][j] 表示下标第 i 天操作后，不持有股票、已完成 j 次交易的情况下，手上持有的现金。
//状态转移函数：若在下标第 i 天买入，则 buy[i][j] = sell[i-1][j] - prices[i]；若在下标第 i 天不买入，则 buy[i][j] = buy[i-1][j] ，则 buy[i][j] = max(sell[i-1][j] - prices[i] , buy[i-1][j])。
//				若在下标第 i 天卖出，则 sell[i][j] = buy[i-1][j-1] + prices[i]；若在下标第 i 天不卖出，则 sell[i][j] = sell[i-1][j] ，则 sell[i][j] = max(buy[i-1][j-1] + prices[i] , sell[i-1][j])。
//边界条件：sell[0][:] = 0，sell[:][0] = 0；buy[0][0] = -prices[0]，buy[0][1:] = INT_MIN。
//最优解：sell[n - 1][:] 的最大值
int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	int k = min(n / 2, 2);
	int i;
	vector<vector<int>> buy(n, vector<int>(k + 1));
	vector<vector<int>> sell(n, vector<int>(k + 1));
	//初始化边界条件
	for (i = 0; i < k; i++)
	{
		if (i != 0)
			buy[0][i] = INT_MIN;
		else
			buy[0][i] = -prices[0];
		sell[0][i] = 0;
	}

	//计算 buy 数组、sell 数组。下标第 i 天操作后，最大只能有 min((i+1)/2+1,k+1) 次交易，行优先遍历
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < min((i + 1) / 2 + 1, k + 1); j++)
		{
			sell[i][j] = j == 0 ? 0 : max(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]);
			buy[i][j] = max(sell[i - 1][j] - prices[i], buy[i - 1][j]);
		}
	}
	return *max_element(sell[n - 1].begin(), sell[n - 1].end());
}


int main123()
{
	vector<int> test = { 3,3,5,0,0,3,1,4 };
	int ret = maxProfit(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}