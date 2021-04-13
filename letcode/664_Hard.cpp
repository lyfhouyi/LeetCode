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


//����Ľⷨ��ջ��ʹ��ջ�洢�ȴ���ӡ����ĸ�飬��ջ����ĸ�鱻��ӡ��Ϊ���ϲ����ĸ�飻�����ȴ�ӡ����ĸ�����ϲ㣬���ӡ����ĸ�����²㣬�ϲ����ĸ����ڱ��²����ĸ�飻ʹ������ inStackVec ���ĳ��ĸ���Ƿ���ջ�С��������ԭʼ�ַ���������ǰ��ĸ��δ��ջ�У��򽫵�ǰ��ĸ��ѹջ�����������ջֱ����ѹջ�ĵ�ǰ��ĸ�飨��ѹջ�ĵ�ǰ��ĸ�鲻��ջ������ջ����ĸ��ȫ����ӡ����Ϊ�ϲ����ĸ�飨Խ���ջԽ���ϲ㣩�����������󣬴�ӡջ��ʣ�����ĸ�飬Խ���ջԽ���ϲ㡣
//int strangePrinter(string s)
//{
//	vector<bool> inStackVec(26, false);
//	stack<char> charStack;
//	char lastChar = '\0';
//	int printCnt = 0;
//	for (string::iterator it = s.begin(); it != s.end(); it++)
//	{
//		if (*it == lastChar)
//			continue;
//		//�������µ���ĸ��
//		lastChar = *it;
//		if (inStackVec[*it - 'a'] == false) //��ǰ��ĸ��δ��ջ��
//		{
//			charStack.push(*it);
//			inStackVec[*it - 'a'] = true;
//		}
//		else //��ǰ��ĸ������ջ��
//		{
//			while (charStack.top() != *it) //�����������Դ�ӡ����ĸ��
//			{
//				inStackVec[charStack.top() - 'a'] = false;
//				charStack.pop();
//				printCnt++; //���´�ӡ����
//			}
//		}
//	}
//	while (!charStack.empty()) //��ӡջ��ʣ�����ĸ�飨Խ����ջ�ף�Խ�����²㣩
//	{
//		printCnt++;
//		charStack.pop();
//	}
//	return printCnt;
//}


//��ά��̬�滮��ά��һ����ά���飺dp[i][j] ��ʾ��ӡ [i,j] �����ϵ��ַ�����������ٴ�ӡ������
//״̬ת�ƺ�����dp[i][j] = min(dp[i][k - 1] + dp[k + 1][j], 1 + dp[i + 1][j]) ������ k ��(i,j] �� s[k] == s[i] ��
//�߽�������dp[:][:] = 0 ��
//���Ž⣺dp[0][n - 1] ��
int strangePrinter(string s)
{
	int n = s.length();
	if (n == 0)
		return 0;
	vector<vector<int>> dp(n + 1, vector<int>(n, 0));

	//����б�����ȱ������� dp ����
	for (int len = 1; len <= n; len++)
	{
		for (int i = 0; i + len - 1 < n; i++)
		{
			int j = i + len - 1;

			//��ǰ��������Ϊ [i,j]
			dp[i][j] = 1 + dp[i + 1][j];
			for (int k = i + 1; k <= j; k++)
			{
				if (s[k] == s[i])
					dp[i][j] = dp[i][k - 1] + dp[k + 1][j] < dp[i][j] ? dp[i][k - 1] + dp[k + 1][j] : dp[i][j];
			}
		}
	}
	return dp[0][n - 1];
}


int main664()
{
	//string test = "aabbcdabcbd";
	//string test = "aabbaa";
	string test = "tbgtgb";
	//string test="aabbcbbaadeda";
	//string test = "";
	//string test = "xaxaxbbxa";
	int ret = strangePrinter(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}