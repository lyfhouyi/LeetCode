#include<iostream>
#include<vector>
#include<string>

using namespace std;

//����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��ġ�
//
//���ط���Ҫ��� ���ٷָ���� ��
//
//
//��ʾ��
//
//	1 <= s.length <= 2000
//	s ����СдӢ����ĸ���
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/palindrome-partitioning-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//һά��̬�滮��ά��һ��һά���飺dp[i] ��ʾ���� [0,i] ���Ӵ�����Ҫ������ٷָ������
//״̬ת�ƺ�����dp[i] = min(dp[j]) + 1 ��j �� [0,i - 1] �� [j + 1,i] �ǻ��Ĵ����� [0,i] ���ǻ��Ĵ�ʱ��0 ���� [0,i] �ǻ��Ĵ�ʱ��
//�߽�������dp[0] = 0 ��
//���Ž⣺dp[n - 1] ��ֵ��
//ʹ��Ԥ����Ļ��ڶ�̬�滮�� p ��������ж����� [j + 1,i] ��[0,i] �Ƿ�Ϊ�����Ӵ���
int minCut(string s)
{
	//Ԥ���� p ���飬���ڶ�ά��̬�滮��p[i][j] ��ʾ���� [i,j] �Ƿ�Ϊ�����Ӵ�
	int n = s.length();
	vector<vector<bool>> p(n, vector<bool>(n, true));
	for (int j = 1; j < n; j++) //�����ȱ���
	{
		for (int i = j - 1; i >= 0; i--)
		{
			p[i][j] = (s[i] == s[j] && p[i + 1][j - 1]);
		}
	}

	//���� dp ����
	int tmp;
	vector<int> dp(n, 0);
	for (int i = 1; i < n; i++)
	{
		if (p[0][i])
			dp[i] = 0;
		else
		{
			tmp = i - 1;
			for (int j = 0; j < i; j++)
			{
				if (p[j + 1][i])
					tmp = tmp < dp[j] ? tmp : dp[j];
			}
			dp[i] = tmp + 1;
		}
	}
	return dp[n - 1];
}


int main132()
{
	//string test = "ab";
	string test = "leet";
	//string test = "ssabba";
	int ret = minCut(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}