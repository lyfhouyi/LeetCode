#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//��̨��ֵĴ�ӡ����������������Ҫ��
//
//	��ӡ��ÿ��ֻ�ܴ�ӡͬһ���ַ����С�
//	ÿ�ο�����������ʼ�ͽ���λ�ô�ӡ���ַ������һḲ�ǵ�ԭ�����е��ַ���
//����һ��ֻ����СдӢ����ĸ���ַ�������������Ǽ��������ӡ����ӡ����Ҫ�����ٴ�����
//
//
//��ʾ : �����ַ����ĳ��Ȳ��ᳬ�� 100��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/strange-printer
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//ջ��ʹ��ջ�洢�ȴ���ӡ����ĸ�飬��ջ����ĸ�鱻��ӡ��Ϊ���ϲ����ĸ�飻�����ȴ�ӡ����ĸ�����ϲ㣬���ӡ����ĸ�����²㣬�ϲ����ĸ����ڱ��²����ĸ�飻ʹ������ inStackVec ���ĳ��ĸ���Ƿ���ջ�С��������ԭʼ�ַ���������ǰ��ĸ��δ��ջ�У��򽫵�ǰ��ĸ��ѹջ�����������ջֱ����ѹջ�ĵ�ǰ��ĸ�飨��ѹջ�ĵ�ǰ��ĸ�鲻��ջ������ջ����ĸ��ȫ����ӡ����Ϊ�ϲ����ĸ�飨Խ���ջԽ���ϲ㣩�����������󣬴�ӡջ��ʣ�����ĸ�飬Խ���ջԽ���ϲ㡣
int strangePrinter(string s)
{
	vector<bool> inStackVec(26, false);
	stack<char> charStack;
	char lastChar = '\0';
	int printCnt = 0;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it == lastChar)
			continue;
		//�������µ���ĸ��
		lastChar = *it;
		if (inStackVec[*it - 'a'] == false) //��ǰ��ĸ��δ��ջ��
		{
			charStack.push(*it);
			inStackVec[*it - 'a'] = true;
		}
		else //��ǰ��ĸ������ջ��
		{
			while (charStack.top() != *it) //�����������Դ�ӡ����ĸ��
			{
				inStackVec[charStack.top() - 'a'] = false;
				charStack.pop();
				printCnt++; //���´�ӡ����
			}
		}
	}
	while (!charStack.empty()) //��ӡջ��ʣ�����ĸ�飨Խ����ջ�ף�Խ�����²㣩
	{
		printCnt++;
		charStack.pop();
	}
	return printCnt;
}


int main664()
{
	//string test = "aabbcdabcbd";
	//string test = "aabbaa";
	string test = "tbgtgb";
	//string test="aabbcbbaadeda";
	int ret = strangePrinter(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}