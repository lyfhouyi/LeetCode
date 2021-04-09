#include<iostream>
#include<vector>
#include<string>

using namespace std;

//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//
//提示：
//
//	1 <= n <= 8
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/generate-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//回溯算法。根据当前生成串 currentS 中左、右括号的数量判断下一步可以将哪种括号加入生成串 currentS 中。回溯于 currentS 下一步加入的括号是左括号或右括号；递归基：当生成的括号对数量满足要求时，将 currentS 加入可行解集合。
void generateValidParenthesis(vector<string>& ret, string currentS, int leftBracketCnt, int rightBracketCnt, int pairsCnt)
{
	if (rightBracketCnt == pairsCnt) //生成的括号对数量已满足要求
	{
		ret.push_back(currentS);
		return;
	}
	if (leftBracketCnt > rightBracketCnt)
		generateValidParenthesis(ret, currentS + ')', leftBracketCnt, rightBracketCnt + 1, pairsCnt);
	if (leftBracketCnt < pairsCnt)
		generateValidParenthesis(ret, currentS + '(', leftBracketCnt + 1, rightBracketCnt, pairsCnt);
}


//解法一：递归。递归调用 generateValidParenthesis() 函数，判断应在当前生成串的尾部加入哪种括号。
vector<string> generateParenthesis(int n)
{
	vector<string> ret;
	generateValidParenthesis(ret, "", 0, 0, n);
	return ret;
}


//解法二：一维动态规划。维护一个一维数组：dp[i] 表示 i 组括号的所有有效组合。
//状态转移函数：dp[i] = "(dp[x][:])" + "dp[y][:]" ，其中 x + y = i - 1 。
//边界条件：dp[0] = "" 。
//最优解：dp[n] 。
//vector<string> generateParenthesis(int n)
//{
//	vector<vector<string>> dp(n + 1);
//	dp[0].push_back("");
//
//	//计算 dp 数组
//	string tmp;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int x = 0; x < i; x++)
//		{
//			int y = i - 1 - x;
//			for (vector<string>::iterator itX = dp[x].begin(); itX != dp[x].end(); itX++)
//			{
//				for (vector<string>::iterator itY = dp[y].begin(); itY != dp[y].end(); itY++)
//				{
//					tmp = "(" + *itX + ")" + *itY;
//					dp[i].push_back(tmp);
//				}
//			}
//		}
//	}
//	return dp[n];
//}


int main22()
{
	vector<string> ret = generateParenthesis(3);
	cout << "main：ret = [";
	for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}