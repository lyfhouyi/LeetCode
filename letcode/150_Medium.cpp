#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//根据 逆波兰表示法，求表达式的值。
//
//有效的算符包括  + 、 - 、 * 、 / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//
//说明：
//
//	整数除法只保留整数部分。
//	给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//
//
//
//提示：
//
//	1 <= tokens.length <= 104
//	tokens[i] 要么是一个算符（"+"、"-"、"*" 或 "/"），要么是一个在范围[-200, 200] 内的整数
//
//
//逆波兰表达式：
//
//逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
//
//	平常使用的算式则是一种中缀表达式，如(1 + 2) * (3 + 4) 。
//	该算式的逆波兰表达式写法为((1 2 + ) (3 4 + ) *) 。
//
//逆波兰表达式主要有以下两个优点：
//
//	去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + *也可以依据次序计算出正确结果。
//	适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/evaluate-reverse-polish-notation
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//栈。使用一个辅助栈，正序遍历原始字符串数组；遇到数字则入栈，遇到运算符则取出栈顶两个数字进行计算（先弹的元素为右操作数，后弹的元素为左操作数），并将结果压入栈中；最终栈中只剩余一个元素，该元素即为原逆波兰表达式的计算结果。
int evalRPN(vector<string>& tokens) {
	stack<int> operandStack;
	int n = tokens.size();
	int operandRight;
	int operandLeft;
	for (int i = 0; i < n; i++)
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			operandRight = operandStack.top();
			operandStack.pop();
			operandLeft = operandStack.top();
			operandStack.pop();
			switch (tokens[i][0])
			{
			case '+':operandStack.push(operandLeft + operandRight); break;
			case '-':operandStack.push(operandLeft - operandRight); break;
			case '*':operandStack.push(operandLeft * operandRight); break;
			case '/':operandStack.push(operandLeft / operandRight); break;
			}
		}
		else
			operandStack.push(stoi(tokens[i]));
	}
	return operandStack.top();
}


int main150()
{

	vector<string> test = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	int ret = evalRPN(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}