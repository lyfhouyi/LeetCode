#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
//
//一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
//
//若这两个字符串没有公共子序列，则返回 0。
//
//
//提示 :
//
//	1 <= text1.length <= 1000
//	1 <= text2.length <= 1000
//	输入的字符串只含有小写英文字符。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-common-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。维护一个二维数组：dp[i][j] 表示 text1 的子串 [0,i - 1] 与 text2 的子串 [0,j - 1] 的最长公共子序列的长度。
//状态转移函数：dp[i][j] = dp[i - 1][j - 1] + 1 ，当 text1[i - 1] == text2[j - 1] 时，max(dp[i][j - 1],dp[i - 1][j])，当 text1[i - 1] != text2[j - 1] 时。
//边界条件：dp[:][:] = 0 。
//最优解：dp[text1.size()][text2.size()] 。
int longestCommonSubsequence(string text1, string text2)
{
	int m = text1.size();
	int n = text2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	//行优先遍历
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (text1[i - 1] == text2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
		}
	}
	return dp[m][n];
}


int main1143()
{
	string text1 = "abc";
	string text2 = "def";
	int ret = longestCommonSubsequence(text1, text2);
	cout << "main：ret = " << ret << endl;
	return 0;
}