#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//����һ���ַ��� s ���ҵ�������Ļ��������У������ظ����еĳ��ȡ����Լ��� s ����󳤶�Ϊ 1000 ��
//
//
//��ʾ��
//
//	1 <= s.length <= 1000
//	s ֻ����СдӢ����ĸ
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/longest-palindromic-subsequence
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//��̬�滮������һ�����飺dp[i][j] ��ʾ�Ӵ� [i,j] �ϵ�����������еĳ��ȡ�
//״̬ת�ƺ�����j != i + 1 ʱ��s[i] == s[j] ʱ��dp[i][j] = dp[i + 1][j - 1] + 2 ��s[i] != s[j] ʱ��dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])��j == i + 1 ʱ��dp[i][j] = s[i] == s[j] ? 2 : 1 ��
//�߽�������dp[i][i] = 1
//���Ž⣺dp[0][n-1] ��ֵ
int longestPalindromeSubseq(string s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n)); // dp �����ÿ�д洢Ϊһ������
	//�����ȱ���
	for (int j = 0; j < n; j++)
	{
		for (int i = j; i >=0; i--)
		{
			if (i == j)
				dp[j][i] = 1;
			else
			{
				if (i + 1 == j)
					dp[j][i] = s[i] == s[j] ? 2 : 1;
				else
				{
					if (s[i] == s[j])
						dp[j][i] = dp[j - 1][i + 1] + 2;
					else
						dp[j][i] = max(dp[j - 1][i], dp[j][i + 1]);
				}		
			}
		}
	}
	return dp[n-1][0];
}


int main516()
{
	string test = "abxyxdby";
	//string test = "bb";
	int ret = longestPalindromeSubseq(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}