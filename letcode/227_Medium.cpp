#include<iostream>
#include<string>
#include<deque>
#include<stack>

using namespace std;

//����һ���ַ������ʽ s ������ʵ��һ�����������������㲢��������ֵ��
//
//���������������������֡�
//
//
//��ʾ��
//
//	1 <= s.length <= 3 * 105
//	s �����������('+', '-', '*', '/') ��ɣ��м���һЩ�ո����
//	s ��ʾһ�� ��Ч���ʽ
//	���ʽ�е������������ǷǸ����������ڷ�Χ[0, 231 - 1] ��
//	��Ŀ���ݱ�֤����һ�� 32 - bit ����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/basic-calculator-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ����׺���ʽ�����Ƚ�ԭʼ�ַ�����ʾ����׺���ʽת���ɺ�׺���ʽ����ʽ��������˫�˶����У���������β��Ϊ��׺���ʽ�������ʹ��ջ�Ժ�׺���ʽ���м��㣬����ջ�е���ֵ��Ϊԭ��׺���ʽ�ļ�������
int calculate(string s)
{
	deque<int> postfixQueue; //�����׺���ʽ����������β��
	stack<char> tmpStack; //�����׺���ʽ�ĸ���ջ
	int n = s.length();
	int i = 0;
	int numValue;
	bool pad = true; //�Ƿ� 0 ���Դ�����
	while (i < n)
	{
		if (s[i] == ' ') //������Ч�ַ�
			i++;
		else if (s[i] == '+' || s[i] == '-')
		{
			if (pad) //�� 0
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
			pad = false; //��һ��������ģ� '-' ���貹 0
		}
		else if (s[i] == '(')
		{
			tmpStack.push(s[i]);
			i++;
			pad = true; //��һ��������ģ� '-' ��Ҫ�� 0
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
			pad = false; //��һ��������ģ� '-' ���貹 0
		}
		else
		{
			numValue = 0;
			pad = false; //��һ��������ģ� '-' ���貹 0
			while (i < n && s[i] >= '0' && s[i] <= '9') //��ȡ��ֵ
			{
				numValue = numValue * 10 - '0' + s[i];
				i++;
			}
			postfixQueue.push_back(numValue);
		}
	}
	while (!tmpStack.empty()) //������ջ��ʣ��������������ѹ���׺���ʽ
	{
		postfixQueue.push_back(-1 * tmpStack.top());
		tmpStack.pop();
	}

	//ʹ�ú�׺���ʽ������
	int tmp;
	stack<int> temStack; //ʹ�ú�׺���ʽ�������ĸ���ջ
	while (!postfixQueue.empty())
	{
		switch (postfixQueue.front())
		{
		case -1 * '+': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() + tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		case -1 * '-': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() - tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		case -1 * '*': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() * tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		case -1 * '/': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
			tmp = temStack.top();
			temStack.pop();
			tmp = temStack.top() / tmp;
			temStack.pop();
			temStack.push(tmp);
			postfixQueue.pop_front();
			break;
		default:
			temStack.push(postfixQueue.front()); //����ֵѹ�븨��ջ
			postfixQueue.pop_front();
			break;
		}
	}
	return temStack.top(); //����ջ��ʣ���Ψһ��ֵ��Ϊ����
}


//�ⷨ����ջ�����ȼ���˳����㣬�����е�����ת��Ϊ�ӷ��������Ҳ�����ѹջ�����ջ�е���ֵ֮�ͼ�Ϊ���󡣽����еļ�������任Ϊ�ӷ����㣬�˳�����ֱ�Ӽ��㣬ʹ��ջ�洢��δ�����㣨�ӷ������Ҳ��������������ԭ�ַ�������ǰΪ������ʱ�����¡����²�����������ǰΪ����ʱ����������ָ����ȡ��ֵ����ֵ��ȡ����ݡ����²����������������ѹջ�������²�������Ϊ '+' ʱ��ֱ��ѹջ�������²�������Ϊ '-' ʱ�����෴��ѹջ�������²�������Ϊ '*' �� '/' ʱ������ջ������Ϊ����������뵱ǰ��ֵ����Ϊ�Ҳ��������ļ�������ѹջ�������������󣬽�ջ�еĸ���ֵ�ۼӼ�Ϊ���ռ�������
//int calculate(string s)
//{
//	int n = s.length();
//	stack<int> operandRight;
//	int numValue;
//	char op = '+';
//	int i = 0;
//	while (i < n) //�����е�����ת��Ϊ�ӷ��������Ҳ�����ѹջ
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
//	while (!operandRight.empty()) //��ջ�еĸ���ֵ�ۼ�
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
	cout << "main��ret = " << ret << endl;
	return 0;
}