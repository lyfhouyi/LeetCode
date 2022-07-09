#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。
//
//
//提示：
//
//	1 <= s.length <= 1000
//	s 只包含小写英文字母
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-palindromic-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//动态规划。计算一个数组：dp[i][j] 表示子串 [i,j] 上的最长回文子序列的长度。
//状态转移函数：j != i + 1 时，s[i] == s[j] 时，dp[i][j] = dp[i + 1][j - 1] + 2 ，s[i] != s[j] 时，dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])；j == i + 1 时，dp[i][j] = s[i] == s[j] ? 2 : 1 。
//边界条件：dp[i][i] = 1
//最优解：dp[0][n-1] 的值
int longestPalindromeSubseq(string s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n)); // dp 矩阵的每列存储为一个数组
	//列优先遍历
	for (int j = 0; j < n; j++)
	{
		for (int i = j; i >=0; i--)
		{
			if (i == j)
				dp[j][i] = 1;
			else
			{
				if (i + 1 == j)
					dp[j][i] = s[i] == s[j] ? 2 : 1;
				else
				{
					if (s[i] == s[j])
						dp[j][i] = dp[j - 1][i + 1] + 2;
					else
						dp[j][i] = max(dp[j - 1][i], dp[j][i + 1]);
				}		
			}
		}
	}
	return dp[n-1][0];
}


int main516()
{
	string test = "abxyxdby";
	//string test = "bb";
	int ret = longestPalindromeSubseq(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}