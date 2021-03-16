#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/palindrome-partitioning
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//当区间 [0,i - 1] 上的分割方案已确定时，计算区间 [i,n - 1] 的分割方案。
void findi2End(vector<vector<string>>& ret, vector<string> &currentScheme, const vector<vector<bool>> &dp, const string& s, int i)
{
	int n = s.length();
	if (i == n) //区间 [0,n - 1] 的分割方案已确定完毕
	{
		ret.push_back(currentScheme);
		return;
	}
	for (int j = i; j < n; j++) //查找下一个回文子串 [i,j]
	{
		if (dp[i][j])
		{
			currentScheme.push_back(s.substr(i, j - i + 1)); //回文子串 [i,j] 加入当前分割方案
			findi2End(ret, currentScheme, dp, s, j + 1);
			currentScheme.pop_back(); //回溯：将回文子串 [i,j] 从当前分割方案中删除，因为区间 [i,j] 的情况已考察完毕，接下来将要考察区间 [i,j + 1]
		}
	}
}

//使用深度优先搜索及回溯算法查找所有的分割方案。对任一分割方案的搜索过程，若区间 [0,i] 上的分割方案已确定，则遍历 j ∈ [i + 1,n - 1] ，若 [i + 1,j] 为回文子串，则可确定区间 [0,j] 上的分割方案，使用回溯算法完成全部可能情况的深度优先搜索，直到 i == n - 1 ；在搜索过程中，可使用预计算的基于动态规划的 dp 数组快速判断区间 [i + 1,j] 是否为回文子串。
vector<vector<string>> partition(string s)
{
	//预计算 dp 数组，基于二维动态规划。dp[i][j] 表示区间 [i,j] 是否为回文子串
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, true));
	for (int j = 1; j < n; j++) //列优先遍历
	{
		for (int i = j - 1; i >= 0; i--)
		{
			dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
		}
	}
	vector<vector<string>> ret;
	vector<string> currentScheme;
	findi2End(ret, currentScheme, dp, s, 0);
	return ret;
}


int main131()
{
	string s = "ssabba";
	vector<vector<string>> ret = partition(s);
	cout << "main：ret =" << endl;
	for (vector<vector<string>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[";
		for (vector<string>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}