#include<iostream>
#include<string>
#include<deque>
#include<stack>

using namespace std;

//实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
//
//
//提示：
//
//	1 <= s.length <= 3 * 105
//	s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
//	s 表示一个有效的表达式
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/basic-calculator
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：前缀表达式。首先将原始字符串表示的中缀表达式转换成前缀表达式的形式，储存在双端队列中（队尾至队首即为前缀表达式）；随后使用栈对前缀表达式进行计算，最终栈中的数值即为原中缀表达式的计算结果。
//int calculate224(string s)
//{
//	deque<int> prefixQueue; //储存前缀表达式（队尾至队首）
//	stack<char> tmpStack; //计算前缀表达式的辅助栈
//	int n = s.size();
//
//	//将中缀表达式转换为前缀表达式
//	int len = 0;
//	bool pad = false;
//	for (int i = n - 1; i >= 0; i--)
//	{
//		switch (s[i])
//		{
//		case ' ':
//			if (len != 0) //将数字串转换为数值
//			{
//				prefixQueue.push_back(stoi(s.substr(i + 1, len)));
//				len = 0;
//			}
//			break;
//		case '+':
//		case '-':
//			if (len != 0) //将数字串转换为数值
//			{
//				prefixQueue.push_back(stoi(s.substr(i + 1, len)));
//				len = 0;
//			}
//			tmpStack.push(s[i]);
//			pad = true;
//			break;
//		case ')':
//			pad = false;
//			tmpStack.push(s[i]);
//			break;
//		case '(':
//			if (pad)
//			{
//				prefixQueue.push_back(0);
//				pad = false;
//			}
//			if (len != 0) //将数字串转换为数值
//			{
//				prefixQueue.push_back(stoi(s.substr(i + 1, len)));
//				len = 0;
//			}
//			while (tmpStack.top() != ')')
//			{
//				prefixQueue.push_back(-1 * tmpStack.top());
//				tmpStack.pop();
//			}
//			tmpStack.pop();
//			break;
//		default:
//			pad = false;
//			len++;
//			break;
//		}
//	}
//	if (pad)
//		prefixQueue.push_back(0);
//	if (len != 0)  //将最后（原字符串首）的数字串转换为数值
//		prefixQueue.push_back(stoi(s.substr(0, len)));
//	while (!tmpStack.empty()) //将辅助栈中剩余的运算符弹出并压入前缀表达式
//	{
//		prefixQueue.push_back(-1 * tmpStack.top());
//		tmpStack.pop();
//	}
//
//	//使用前缀表达式计算结果
//	int tmp;
//	stack<int> temStack; //使用前缀表达式计算结果的辅助栈
//	while (!prefixQueue.empty())
//	{
//		switch (prefixQueue.front())
//		{
//		case -1 * '+': //计算辅助栈顶的两个数值并将结果压入辅助栈
//			tmp = temStack.top();
//			temStack.pop();
//			tmp += temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '-': //计算辅助栈顶的两个数值并将结果压入辅助栈
//			tmp = temStack.top();
//			temStack.pop();
//			tmp -= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		default:
//			temStack.push(prefixQueue.front()); //将数值压入辅助栈
//			prefixQueue.pop_front();
//			break;
//		}
//	}
//	return temStack.top(); //辅助栈中剩余的唯一数值即为所求
//}


//解法一，优化版：前缀表达式。首先将原始字符串表示的中缀表达式转换成前缀表达式的形式，储存在双端队列中（队尾至队首即为前缀表达式）；随后使用栈对前缀表达式进行计算，最终栈中的数值即为原中缀表达式的计算结果。
//int calculate224(string s)
//{
//	deque<int> prefixQueue; //储存前缀表达式（队尾至队首）
//	stack<char> tmpStack; //计算前缀表达式的辅助栈
//	int n = s.length();
//	int i = n - 1;
//	int len;
//	bool pad = false; //是否补 0 ，以处理负数
//	while (i >= 0)
//	{
//		if (s[i] == ' ') //跳过无效字符
//			i--;
//		else if (s[i] == '+' || s[i] == '-')
//		{
//			while (!tmpStack.empty() && (tmpStack.top() == '*' || tmpStack.top() == '/'))
//			{
//				prefixQueue.push_back(-1 * tmpStack.top());
//				tmpStack.pop();
//			}
//			tmpStack.push(s[i]);
//			pad = true;
//			i--;
//		}
//		else if (s[i] == '*' || s[i] == '/' || s[i] == ')')
//		{
//			tmpStack.push(s[i]);
//			i--;
//			pad = false; //上一个（后面的） '-' 无需补 0
//		}
//		else if (s[i] == '(')
//		{
//			if (pad) //补 0
//			{
//				prefixQueue.push_back(0);
//				pad = false;
//			}
//			while (tmpStack.top() != ')')
//			{
//				prefixQueue.push_back(-1 * tmpStack.top());
//				tmpStack.pop();
//			}
//			tmpStack.pop();
//			i--;
//		}
//		else
//		{
//			len = 1;
//			pad = false; //上一个（后面的） '-' 无需补 0
//			while (i >= 0 && s[i] >= '0' && s[i] <= '9') //提取数值
//			{
//				len++;
//				i--;
//			}
//			prefixQueue.push_back(stoi(s.substr(i + 1, len)));
//		}
//	}
//	if (pad) //原表达式以 '-' 开头时，需要补 0
//		prefixQueue.push_back(0);
//	while (!tmpStack.empty()) //将辅助栈中剩余的运算符弹出并压入前缀表达式
//	{
//		prefixQueue.push_back(-1 * tmpStack.top());
//		tmpStack.pop();
//	}
//
//	//使用前缀表达式计算结果
//	int tmp;
//	stack<int> temStack; //使用前缀表达式计算结果的辅助栈
//	while (!prefixQueue.empty())
//	{
//		switch (prefixQueue.front())
//		{
//		case -1 * '+': //计算辅助栈顶的两个数值并将结果压入辅助栈
//			tmp = temStack.top();
//			temStack.pop();
//			tmp += temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '-': //计算辅助栈顶的两个数值并将结果压入辅助栈
//			tmp = temStack.top();
//			temStack.pop();
//			tmp -= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '*': //计算辅助栈顶的两个数值并将结果压入辅助栈
//			tmp = temStack.top();
//			temStack.pop();
//			tmp *= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '/': //计算辅助栈顶的两个数值并将结果压入辅助栈
//			tmp = temStack.top();
//			temStack.pop();
//			tmp /= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		default:
//			temStack.push(prefixQueue.front()); //将数值压入辅助栈
//			prefixQueue.pop_front();
//			break;
//		}
//	}
//	return temStack.top(); //辅助栈中剩余的唯一数值即为所求
//}


//解法二：后缀表达式。首先将原始字符串表示的中缀表达式转换成后缀表达式的形式，储存在双端队列中（队首至队尾即为后缀表达式）；随后使用栈对后缀表达式进行计算，最终栈中的数值即为原中缀表达式的计算结果。
int calculate224(string s)
{
	deque<int> postfixQueue; //储存后缀表达式（队首至队尾）
	stack<char> tmpStack; //计算后缀表达式的辅助栈
	int n = s.length();
	int i = 0;
	int numValue;
	bool pad = true; //是否补 0 ，以处理负数
	while (i < n)
	{
		if (s[i] == ' ') //跳过无效字符
			i++;
		else if (s[i] == '+' || s[i] == '-')
		{
			if (pad) //补 0
				postfixQueue.push_back(0);
			pad = false;
			while (!tmpStack.empty() && tmpStack.top() != '(')
			{
				postfixQueue.push_back(-1 * tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.push(s[i]);
			i++;
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!tmpStack.empty() && tmpStack.top() != '(' && tmpStack.top() != '+' && tmpStack.top() != '-')
			{
				postfixQueue.push_back(-1 * tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.push(s[i]);
			i++;
			pad = false; //下一个（后面的） '-' 无需补 0
		}
		else if (s[i] == '(')
		{
			tmpStack.push(s[i]);
			i++;
			pad = true; //下一个（后面的） '-' 需要补 0
		}
		else if (s[i] == ')')
		{
			while (tmpStack.top() != '(')
			{
				postfixQueue.push_back(-1 * tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.pop();
			i++;
			pad = false; //下一个（后面的） '-' 无需补 0
		}
		else
		{
			numValue = 0;
			pad = false; //下一个（后面的） '-' 无需补 0
			while (i < n && s[i] >= '0' && s[i] <= '9') //提取数值
			{
				numValue = numValue * 10 - '0' + s[i];
				i++;
			}
			postfixQueue.push_back(numValue);
		}
	}
	while (!tmpStack.empty()) //将辅助栈中剩余的运算符弹出并压入后缀表达式
	{
		postfixQueue.push_back(-1 * tmpStack.top());
		tmpStack.pop();
	}

	//使用后缀表达式计算结果
	int tmp;
	stack<int> temStack; //使用后缀表达式计算结果的辅助栈
	while (!postfixQueue.empty())
	{
		switch (postfixQueue.front())
		{
		case -1 * '+': //计算辅助栈顶的两个数值并将结果压入辅助栈
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() + tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		case -1 * '-': //计算辅助栈顶的两个数值并将结果压入辅助栈
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() - tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		case -1 * '*': //计算辅助栈顶的两个数值并将结果压入辅助栈
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() * tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		case -1 * '/': //计算辅助栈顶的两个数值并将结果压入辅助栈
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() / tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		default:
			temStack.push(postfixQueue.front()); //将数值压入辅助栈
			postfixQueue.pop_front();
			break;
		}
	}
	return temStack.top(); //辅助栈中剩余的唯一数值即为所求
}


//解法三：使用栈将括号展开。栈内存放当前展开位置的操作符，-1 表示减法，1 表示加法。单指针遍历字符串，当前指针为 '(' 时，将当前展开位置的操作符压栈；当前指针为 ')' 时，出栈；当前指针为 '+' '-' 根据栈顶元素更改当前位置的操作符；当前指针为数字时，提取数值后根据当前位置的操作符计算结果。
//int calculate224(string s)
//{
//	stack<char> signStack;
//	signStack.push(1);
//	int n = s.length();
//	int sign = 1;
//	int numValue;
//	int ret = 0;
//	int i = 0;
//	while (i < n)
//	{
//		if (s[i] == ' ') //跳过无效字符
//			i++;
//		else if (s[i] == '+') //调整当前位置的操作符
//		{
//			sign = signStack.top();
//			i++;
//		}
//		else if (s[i] == '-') //调整当前位置的操作符
//		{
//			sign = -signStack.top();
//			i++;
//		}
//		else if (s[i] == '(') //将当前位置的操作符压栈
//		{
//			signStack.push(sign);
//			i++;
//		}
//		else if (s[i] == ')') //操作符出栈
//		{
//			signStack.pop();
//			i++;
//		}
//		else
//		{
//			numValue = 0;
//			while (i < n && s[i] >= '0' && s[i] <= '9') //提取数值
//			{
//				numValue = 10 * numValue - '0' + s[i];
//				i++;
//			}
//			ret += sign * numValue; //根据当前位置的操作符计算结果
//		}
//	}
//	return ret;
//}



int main224()
{
	//string test = "5+(1+(1 + (4 + 5 + 2) - 3)) + (6 + 8)";
	//string test = "2147483647";
	string test = " (-5)*(8)/8*8/8*8/8";
	//string test = "1-(+1+1)";
	//string test = " - 5 + ( - 8 ) - ( 6 + 7 ) ";
	//string test = " -5 - 8  * ( 6 + 7) +  9  / 4 ";
	//string test = "1+(0-2)+(0-3)";
	//string test = "1+( -2)+(-3)";
	//string test = " ( 3 )";
	//string test = "1+(212-(3+4))-5";
	//string test = " - 2 +(-1)+ 1";
	//string test = "2-1 + 2";
	int ret = calculate224(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}