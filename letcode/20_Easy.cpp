#include<iostream>
#include<stack>
#include<string>

using namespace std;

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//	左括号必须用相同类型的右括号闭合。
//	左括号必须以正确的顺序闭合。
//
//
//提示：
//
//	1 <= s.length <= 10^4
//	s 仅由括号 '()[]{}' 组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/valid-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//栈。单指针遍历字符串。遇到左括号则压栈；遇到右括号判断栈顶元素是否与之匹配，若匹配则弹出栈顶，并丢弃当前右括号，若栈空或不匹配则字符串无效；遍历结束后，若栈非空则字符串无效。
bool isValid(string s)
{
	stack<char> parenthesesStack;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it == '(' || *it == '[' || *it == '{')
			parenthesesStack.push(*it);
		else
		{
			if (parenthesesStack.empty() || abs(*it - parenthesesStack.top()) > 2)
				return false;
			parenthesesStack.pop();
		}
	}
	return parenthesesStack.empty();
}


int main20()
{
	string test = "({{{{}}}))";
	bool ret = isValid(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}