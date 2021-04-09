#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

//给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
//
//返回所有可能的结果。答案可以按 任意顺序 返回。
//
//
//提示：
//
//	1 <= s.length <= 25
//	s 由小写英文字母以及括号 '(' 和 ')' 组成
//	s 中至多含 20 个括号
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-invalid-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 //判断字符串是否有效。
bool isValid(const string &s)
{
	int leftBracketCnt = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			leftBracketCnt++;
		else if (s[i] == ')')
			leftBracketCnt--;
		if (leftBracketCnt < 0)
			return false;
	}
	if (leftBracketCnt != 0)
		return false;
	return true;
}

//解法一，回溯算法。逐括号判断是否应将 s 中的下一个括号加入待定解 currentS ，回溯于加入 s 中的下一个括号和不加入 s 中的下一个括号；递归基：当当前判断位置等于 s 的末尾时，判断当前字符串（待定解） currentS 是否有效，若有效且长度比 sSet 集合中的字符串都长，则用 currentS 字符串替代 sSet 集合，否则丢弃当前字符串。
//void findValidParentheses(unordered_set<string>& sSet, const string& s, int index, string currentS)
//{
//	if (index == s.length())
//	{
//		if (isValid(currentS))
//		{
//			if (sSet.empty())
//				sSet.insert(currentS);
//			else
//			{
//				if (sSet.begin()->length() < currentS.length())
//				{
//					sSet.clear();
//					sSet.insert(currentS);
//				}
//				else if (sSet.begin()->length() == currentS.length())
//					sSet.insert(currentS);
//			}
//		}
//		return;
//	}
//
//	if (s[index] == '(' || s[index] == ')')
//		findValidParentheses(sSet, s, index + 1, currentS);
//	findValidParentheses(sSet, s, index + 1, currentS + s[index]);
//}


//解法一：递归。递归调用 findValidParentheses() 函数，逐括号判断是否应将 s 中的下一个括号加入待定解集合。
//vector<string> removeInvalidParentheses(string s)
//{
//	unordered_set<string> sSet;
//	string currentS = "";
//	findValidParentheses(sSet, s, 0, currentS);
//	vector<string> ret(sSet.begin(), sSet.end());
//	return ret;
//}


//解法二，回溯算法。逐括号判断是否应将 s 中的下一个括号加入待定解 currentS ，回溯于加入 s 中的下一个括号和不加入 s 中的下一个括号；递归基：当当前判断位置等于 s 的末尾时，判断当前字符串（待定解） currentS 是否有效，若有效且长度比 sSet 集合中的字符串都长，则用 currentS 字符串替代 sSet 集合，否则丢弃当前字符串。
void findValidParentheses(unordered_set<string>& sSet, const string& s, int index, string currentS, int leftBracketCnt, int rightBracketCnt)
{
	if (index == s.length())
	{
		if (leftBracketCnt == 0 && rightBracketCnt == 0 && isValid(currentS))
			sSet.insert(currentS);
		return;
	}

	if (s[index] == '(' && leftBracketCnt > 0)
		findValidParentheses(sSet, s, index + 1, currentS, leftBracketCnt - 1, rightBracketCnt);
	else if (s[index] == ')' && rightBracketCnt > 0)
		findValidParentheses(sSet, s, index + 1, currentS, leftBracketCnt, rightBracketCnt - 1);
	findValidParentheses(sSet, s, index + 1, currentS + s[index], leftBracketCnt, rightBracketCnt);
}


//解法二：递归。递归调用 findValidParentheses() 函数，逐括号判断是否应将 s 中的下一个括号加入待定解集合。
vector<string> removeInvalidParentheses(string s)
{
	//计算多余的括号数量
	int leftBracketCnt = 0; //左括号多余的数量
	int rightBracketCnt = 0; //右括号多余的数量
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it == '(')
			leftBracketCnt++;
		else if (*it == ')')
			leftBracketCnt--;
		if (leftBracketCnt < 0)
		{
			leftBracketCnt = 0;
			rightBracketCnt++;
		}
	}

	unordered_set<string> sSet;
	string currentS = "";
	findValidParentheses(sSet, s, 0, currentS, leftBracketCnt, rightBracketCnt);
	vector<string> ret(sSet.begin(), sSet.end());
	return ret;
}


int main301()
{
	//string test = "()()";
	string test = ")(n";
	//string test = "(a)())()";
	vector<string> ret = removeInvalidParentheses(test);
	cout << "main：ret = [";
	for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}