#include<iostream>
#include<string>
#include<deque>
#include<stack>

using namespace std;

//ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ s ��ֵ��
//
//
//��ʾ��
//
//	1 <= s.length <= 3 * 105
//	s �����֡�'+'��'-'��'('��')'���� ' ' ���
//	s ��ʾһ����Ч�ı��ʽ
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/basic-calculator
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ��ǰ׺���ʽ�����Ƚ�ԭʼ�ַ�����ʾ����׺���ʽת����ǰ׺���ʽ����ʽ��������˫�˶����У���β�����׼�Ϊǰ׺���ʽ�������ʹ��ջ��ǰ׺���ʽ���м��㣬����ջ�е���ֵ��Ϊԭ��׺���ʽ�ļ�������
//int calculate224(string s)
//{
//	deque<int> prefixQueue; //����ǰ׺���ʽ����β�����ף�
//	stack<char> tmpStack; //����ǰ׺���ʽ�ĸ���ջ
//	int n = s.size();
//
//	//����׺���ʽת��Ϊǰ׺���ʽ
//	int len = 0;
//	bool pad = false;
//	for (int i = n - 1; i >= 0; i--)
//	{
//		switch (s[i])
//		{
//		case ' ':
//			if (len != 0) //�����ִ�ת��Ϊ��ֵ
//			{
//				prefixQueue.push_back(stoi(s.substr(i + 1, len)));
//				len = 0;
//			}
//			break;
//		case '+':
//		case '-':
//			if (len != 0) //�����ִ�ת��Ϊ��ֵ
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
//			if (len != 0) //�����ִ�ת��Ϊ��ֵ
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
//	if (len != 0)  //�����ԭ�ַ����ף������ִ�ת��Ϊ��ֵ
//		prefixQueue.push_back(stoi(s.substr(0, len)));
//	while (!tmpStack.empty()) //������ջ��ʣ��������������ѹ��ǰ׺���ʽ
//	{
//		prefixQueue.push_back(-1 * tmpStack.top());
//		tmpStack.pop();
//	}
//
//	//ʹ��ǰ׺���ʽ������
//	int tmp;
//	stack<int> temStack; //ʹ��ǰ׺���ʽ�������ĸ���ջ
//	while (!prefixQueue.empty())
//	{
//		switch (prefixQueue.front())
//		{
//		case -1 * '+': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
//			tmp = temStack.top();
//			temStack.pop();
//			tmp += temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '-': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
//			tmp = temStack.top();
//			temStack.pop();
//			tmp -= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		default:
//			temStack.push(prefixQueue.front()); //����ֵѹ�븨��ջ
//			prefixQueue.pop_front();
//			break;
//		}
//	}
//	return temStack.top(); //����ջ��ʣ���Ψһ��ֵ��Ϊ����
//}


//�ⷨһ���Ż��棺ǰ׺���ʽ�����Ƚ�ԭʼ�ַ�����ʾ����׺���ʽת����ǰ׺���ʽ����ʽ��������˫�˶����У���β�����׼�Ϊǰ׺���ʽ�������ʹ��ջ��ǰ׺���ʽ���м��㣬����ջ�е���ֵ��Ϊԭ��׺���ʽ�ļ�������
//int calculate224(string s)
//{
//	deque<int> prefixQueue; //����ǰ׺���ʽ����β�����ף�
//	stack<char> tmpStack; //����ǰ׺���ʽ�ĸ���ջ
//	int n = s.length();
//	int i = n - 1;
//	int len;
//	bool pad = false; //�Ƿ� 0 ���Դ�����
//	while (i >= 0)
//	{
//		if (s[i] == ' ') //������Ч�ַ�
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
//			pad = false; //��һ��������ģ� '-' ���貹 0
//		}
//		else if (s[i] == '(')
//		{
//			if (pad) //�� 0
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
//			pad = false; //��һ��������ģ� '-' ���貹 0
//			while (i >= 0 && s[i] >= '0' && s[i] <= '9') //��ȡ��ֵ
//			{
//				len++;
//				i--;
//			}
//			prefixQueue.push_back(stoi(s.substr(i + 1, len)));
//		}
//	}
//	if (pad) //ԭ���ʽ�� '-' ��ͷʱ����Ҫ�� 0
//		prefixQueue.push_back(0);
//	while (!tmpStack.empty()) //������ջ��ʣ��������������ѹ��ǰ׺���ʽ
//	{
//		prefixQueue.push_back(-1 * tmpStack.top());
//		tmpStack.pop();
//	}
//
//	//ʹ��ǰ׺���ʽ������
//	int tmp;
//	stack<int> temStack; //ʹ��ǰ׺���ʽ�������ĸ���ջ
//	while (!prefixQueue.empty())
//	{
//		switch (prefixQueue.front())
//		{
//		case -1 * '+': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
//			tmp = temStack.top();
//			temStack.pop();
//			tmp += temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '-': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
//			tmp = temStack.top();
//			temStack.pop();
//			tmp -= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '*': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
//			tmp = temStack.top();
//			temStack.pop();
//			tmp *= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		case -1 * '/': //���㸨��ջ����������ֵ�������ѹ�븨��ջ
//			tmp = temStack.top();
//			temStack.pop();
//			tmp /= temStack.top();
//			temStack.pop();
//			temStack.push(tmp);
//			prefixQueue.pop_front();
//			break;
//		default:
//			temStack.push(prefixQueue.front()); //����ֵѹ�븨��ջ
//			prefixQueue.pop_front();
//			break;
//		}
//	}
//	return temStack.top(); //����ջ��ʣ���Ψһ��ֵ��Ϊ����
//}


//�ⷨ������׺���ʽ�����Ƚ�ԭʼ�ַ�����ʾ����׺���ʽת���ɺ�׺���ʽ����ʽ��������˫�˶����У���������β��Ϊ��׺���ʽ�������ʹ��ջ�Ժ�׺���ʽ���м��㣬����ջ�е���ֵ��Ϊԭ��׺���ʽ�ļ�������
int calculate224(string s)
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


//�ⷨ����ʹ��ջ������չ����ջ�ڴ�ŵ�ǰչ��λ�õĲ�������-1 ��ʾ������1 ��ʾ�ӷ�����ָ������ַ�������ǰָ��Ϊ '(' ʱ������ǰչ��λ�õĲ�����ѹջ����ǰָ��Ϊ ')' ʱ����ջ����ǰָ��Ϊ '+' '-' ����ջ��Ԫ�ظ��ĵ�ǰλ�õĲ���������ǰָ��Ϊ����ʱ����ȡ��ֵ����ݵ�ǰλ�õĲ�������������
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
//		if (s[i] == ' ') //������Ч�ַ�
//			i++;
//		else if (s[i] == '+') //������ǰλ�õĲ�����
//		{
//			sign = signStack.top();
//			i++;
//		}
//		else if (s[i] == '-') //������ǰλ�õĲ�����
//		{
//			sign = -signStack.top();
//			i++;
//		}
//		else if (s[i] == '(') //����ǰλ�õĲ�����ѹջ
//		{
//			signStack.push(sign);
//			i++;
//		}
//		else if (s[i] == ')') //��������ջ
//		{
//			signStack.pop();
//			i++;
//		}
//		else
//		{
//			numValue = 0;
//			while (i < n && s[i] >= '0' && s[i] <= '9') //��ȡ��ֵ
//			{
//				numValue = 10 * numValue - '0' + s[i];
//				i++;
//			}
//			ret += sign * numValue; //���ݵ�ǰλ�õĲ�����������
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
	cout << "main��ret = " << ret << endl;
	return 0;
}