#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//删除一个字符
//替换一个字符
//
//
//提示：
//
//	0 <= word1.length, word2.length <= 500
//	word1 和 word2 由小写英文字母组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/edit-distance
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：二维动态规划。维护一个二维数组：dp[i][j] 表示将 word1 的前 i 个字符转换成 word2 的前 j 个字符所需的最少操作数。
//状态转移函数：dp[i][j] = dp[i - 1][j - 1]，当 word1[i] == word2[j] 时，min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1，当 word1[i] != word2[j] 时。
//边界条件：dp[i][0] = i, dp[0][j] = j 。
//最优解：dp[word1.size()][word2.size()] 。
//int minDistance(string word1, string word2)
//{
//	int m = word1.size();
//	int n = word2.size();
//	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//
//	//初始化 dp 数组边界条件
//	for (int i = 0; i <= m; i++)
//		dp[i][0] = i;
//	for (int j = 0; j <= n; j++)
//		dp[0][j] = j;
//
//	//行优先遍历计算 dp 数组
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (word1[i - 1] == word2[j - 1])
//				dp[i][j] = dp[i - 1][j - 1];
//			else
//				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
//		}
//	}
//	return dp[m][n];
//}


int minDistanceRecursion(const string& word1, const string& word2, vector<vector<int>>& minDistVec)
{
	if (word1.length() == 0 || word2.length() == 0) //某串为空时，另一字符串的全部字符均需操作
		return max(word1.length(), word2.length());
	if (word1.back() == word2.back()) //串尾字符无需操作
	{
		if (minDistVec[word1.length() - 1][word2.length() - 1] == -1)
			minDistVec[word1.length() - 1][word2.length() - 1] = minDistanceRecursion(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() - 1), minDistVec);
		minDistVec[word1.length()][word2.length()] = minDistVec[word1.length() - 1][word2.length() - 1];
	}
	else
	{
		if (minDistVec[word1.length() - 1][word2.length() - 1] == -1)
			minDistVec[word1.length() - 1][word2.length() - 1] = minDistanceRecursion(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() - 1), minDistVec);
		if (minDistVec[word1.length() - 1][word2.length()] == -1)
			minDistVec[word1.length() - 1][word2.length()] = minDistanceRecursion(word1.substr(0, word1.length() - 1), word2, minDistVec);
		if (minDistVec[word1.length()][word2.length() - 1] == -1)
			minDistVec[word1.length()][word2.length() - 1] = minDistanceRecursion(word1, word2.substr(0, word2.length() - 1), minDistVec);
		minDistVec[word1.length()][word2.length()] = 1 + min(min(minDistVec[word1.length() - 1][word2.length()], minDistVec[word1.length()][word2.length() - 1]), minDistVec[word1.length() - 1][word2.length() - 1]);
	}
	return minDistVec[word1.length()][word2.length()];
}


//解法二：递归。递归调用 minDistanceRecursion() 函数；根据当前串尾字符是否需要操作及操作方式，决定子问题的状态；取各子问题的最小值加 1 作为返回值；递归基：某个输入字符串为空时，返回另一字符串的长度。使用 minDistVec 数组记录已计算出的最少操作数，避免重复计算。
int minDistance(string word1, string word2)
{
	vector<vector<int>> minDistVec(word1.length() + 1, vector<int>(word2.length() + 1, -1));
	return minDistanceRecursion(word1, word2, minDistVec);
}


int main72()
{
	string word1 = "intention";
	string word2 = "execution";
	int ret = minDistance(word1, word2);
	cout << "main：ret = " << ret << endl;
	return 0;
}