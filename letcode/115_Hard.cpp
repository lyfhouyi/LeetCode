#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
//
//字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
//
//题目数据保证答案符合 32 位带符号整数范围。
//
//
//提示：
//
//	0 <= s.length, t.length <= 1000
//	s 和 t 由英文字母组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/distinct-subsequences
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//找到字符串 s 从 begin 开始的子串中，包含子序列 t 的个数
void numSubsequence(const string& s, const string& t, int beginS, int beginT, int& cnt)
{
	int n = s.length();
	int m = t.length();
	for (int i = beginS; i < n; i++)
	{
		if (s[i] == t[beginT])
		{
			if (beginT == m - 1)
				cnt++;
			else
				numSubsequence(s, t, i + 1, beginT + 1, cnt);
		}
	}
	return;
}


//回溯算法。减而治之。不断地在更短的 s 中查找更短的 t ，在找到时更新总数量。
//算法正确，但时间超时。
//int numDistinct(string s, string t)
//{
//	int ret = 0;
//	numSubsequence(s, t, 0, 0, ret);
//	return ret;
//}


//二维动态规划。维护一个二维数组：dp[i][j] 表示 s 中以 s[j] 结尾的满足要求的子序列数量，满足要求指：该子序列包含字符串 t[0:i] 且尾字母相同（即 t[i] == s[j]）。
//状态转移函数：dp[i][j] = sum(dp[i - 1][x]) ，x ∈ [0,j) 当 s[j] == t[i] 时，0 ，当 t[i] != s[j] 时。
//边界条件：dp[:][:] = 0 。
//最优解：sum(dp[m - 1][:]) 。
//优化：使用 sumLine 记录第 i 行的前缀和（前 indexJ 项），使得在计算 sum(dp[i - 1][x]) ，x ∈ [0,j) 时避免重复计算。
int numDistinct(string s, string t)
{
	int n = s.length();
	int m = t.length();
	long sumLine;
	int indexJ;
	vector<vector<long>> dp(m, vector<long>(n, 0));
	for (int i = 0; i < m; i++)
	{
		sumLine = 0;
		indexJ = 0;
		for (int j = 0; j < n; j++)
		{
			if (t[i] == s[j])
			{
				if (i == 0)
					dp[i][j] = 1;
				else
				{
					for (int x = indexJ; x < j; x++)
					{
						sumLine += dp[i - 1][x];
					}
					dp[i][j] = sumLine;
				}
				indexJ = j;
			}
		}
	}
	int ret = 0;
	for (int j = 0; j < n; j++)
		ret += dp[m - 1][j];
	return ret;
}


int main115()
{
	//string s = "rabbbit";
	//string t = "rabbit";
	string s = "babgbag";
	string t = "bag";
	//string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
	//string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
	int ret = numDistinct(s, t);
	cout << "main：ret = " << ret << endl;
	return 0;
}