#include<iostream>
#include<vector>

using namespace std;

//给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
//
//我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
//
//所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
//
//请你返回「表现良好时间段」的最大长度。
//
//
//提示：
//
//	1 <= hours.length <= 10000
//	0 <= hours[i] <= 16
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-well-performing-interval
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。计算一个数组：dp[i][j] 表示子串[i, j] 上“劳累的天数”与“不劳累的天数”的差值。
//状态转移函数：j != i + 1 时，hours[j] 为“劳累的一天”时，dp[i][j] = dp[i][j - 1] + 1 ，hours[j] 为“不劳累的一天”时，dp[i][j] = dp[i][j - 1] - 1 。
//边界条件：dp[i][i] = (hours[i] 为“劳累的一天” ? 1 : 0) 。
//最优解：dp[:][:] 的最大值。
//使用滚动数组进行优化。
int longestWPI(vector<int>& hours)
{
	int n = hours.size();
	int maxLength=0;
	int diff;
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && hours[i - 1] > 8)
			continue;
		diff =0;
		for (int j = i; j < n; j++)
		{
			diff += (hours[j] > 8 ? 1 : -1);
			if (diff > 0)
				maxLength =( maxLength > (j - i + 1) ? maxLength : (j - i + 1));
		}
	}
	return maxLength;
}


int main()
{
	vector<int> test = { 9,9,6,0,6,6,9 };
	int ret = longestWPI(test);
	cout << "main：ret = " << ret << endl;
}



