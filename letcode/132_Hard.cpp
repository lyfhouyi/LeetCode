#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
//
//返回符合要求的 最少分割次数 。
//
//
//提示：
//
//	1 <= s.length <= 2000
//	s 仅由小写英文字母组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/palindrome-partitioning-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//一维动态规划。维护一个一维数组：dp[i] 表示区间 [0,i] 的子串满足要求的最少分割次数。
//状态转移函数：dp[i] = min(dp[j]) + 1 ，j ∈ [0,i - 1] 且 [j + 1,i] 是回文串，当 [0,i] 不是回文串时，0 ，当 [0,i] 是回文串时。
//边界条件：dp[0] = 0 。
//最优解：dp[n - 1] 的值。
//使用预计算的基于动态规划的 p 数组快速判断区间 [j + 1,i] 、[0,i] 是否为回文子串。
int minCut(string s)
{
	//预计算 p 数组，基于二维动态规划。p[i][j] 表示区间 [i,j] 是否为回文子串
	int n = s.length();
	vector<vector<bool>> p(n, vector<bool>(n, true));
	for (int j = 1; j < n; j++) //列优先遍历
	{
		for (int i = j - 1; i >= 0; i--)
		{
			p[i][j] = (s[i] == s[j] && p[i + 1][j - 1]);
		}
	}

	//计算 dp 数组
	int tmp;
	vector<int> dp(n, 0);
	for (int i = 1; i < n; i++)
	{
		if (p[0][i])
			dp[i] = 0;
		else
		{
			tmp = i - 1;
			for (int j = 0; j < i; j++)
			{
				if (p[j + 1][i])
					tmp = tmp < dp[j] ? tmp : dp[j];
			}
			dp[i] = tmp + 1;
		}
	}
	return dp[n - 1];
}


int main132()
{
	//string test = "ab";
	string test = "leet";
	//string test = "ssabba";
	int ret = minCut(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}