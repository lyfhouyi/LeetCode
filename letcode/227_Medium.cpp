#include<iostream>
#include<string>
#include<deque>
#include<stack>

using namespace std;

//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//
//整数除法仅保留整数部分。
//
//
//提示：
//
//	1 <= s.length <= 3 * 105
//	s 由整数和算符('+', '-', '*', '/') 组成，中间由一些空格隔开
//	s 表示一个 有效表达式
//	表达式中的所有整数都是非负整数，且在范围[0, 231 - 1] 内
//	题目数据保证答案是一个 32 - bit 整数
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/basic-calculator-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：后缀表达式。首先将原始字符串表示的中缀表达式转换成后缀表达式的形式，储存在双端队列中（队首至队尾即为后缀表达式）；随后使用栈对后缀表达式进行计算，最终栈中的数值即为原中缀表达式的计算结果。
int calculate(string s)
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


//解法二：栈。优先计算乘除运算，将所有的运算转换为加法运算后的右操作数压栈，最后栈中的数值之和即为所求。将所有的减法运算变换为加法运算，乘除运算直接计算，使用栈存储尚未被计算（加法）的右操作数。正序遍历原字符串，当前为操作符时，更新“最新操作符”；当前为数字时，继续右移指针提取数值，数值提取后根据“最新操作符”进行运算或压栈（“最新操作符”为 '+' 时，直接压栈；“最新操作符”为 '-' 时，将相反数压栈；“最新操作符”为 '*' 或 '/' 时，计算栈顶（作为左操作数）与当前数值（作为右操作数）的计算结果后压栈）；遍历结束后，将栈中的各数值累加即为最终计算结果。
//int calculate(string s)
//{
//	int n = s.length();
//	stack<int> operandRight;
//	int numValue;
//	char op = '+';
//	int i = 0;
//	while (i < n) //将所有的运算转换为加法运算后的右操作数压栈
//	{
//		if (s[i] == ' ')
//			i++;
//		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
//		{
//			op = s[i];
//			i++;
//		}
//		else
//		{
//			numValue = 0;
//			while (i < n && s[i] >= '0' && s[i] <= '9')
//			{
//				numValue = numValue * 10 - '0' + s[i];
//				i++;
//			}
//			switch (op)
//			{
//			case '*':
//				numValue = operandRight.top()*numValue;
//				operandRight.pop();
//				operandRight.push(numValue);
//				break;
//			case '/':
//				numValue = operandRight.top() / numValue;
//				operandRight.pop();
//				operandRight.push(numValue);
//				break;
//			case '+':
//				operandRight.push(numValue);
//				break;
//			case '-':
//				operandRight.push(-numValue);
//				break;
//			}
//		}
//	}
//	int ret = 0;
//	while (!operandRight.empty()) //将栈中的各数值累加
//	{
//		ret += operandRight.top();
//		operandRight.pop();
//	}
//	return ret;
//}


int main227()
{
	//string test = "5+(1+(1 + (4 + 5 + 2) - 3)) + (6 + 8)";
	//string test = "2147483647";
	string test = "42";
	//string test = "1-(+1+1)";
	//string test = " - 5 + ( - 8 ) - ( 6 + 7 ) ";
	//string test = " -5 - 8  * ( 6 + 7) +  9  / 4 ";
	//string test = "1+(0-2)+(0-3)";
	//string test = "1+( -2)+(-3)";
	//string test = " ( 3 )";
	//string test = "1+(212-(3+4))-5";
	//string test = " - 2 +(-1)+ 1";
	//string test = "2-1 + 2";
	int ret = calculate(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}