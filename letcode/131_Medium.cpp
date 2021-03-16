#include<iostream>
#include<vector>
#include<string>

using namespace std;

//����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���
//
//���� s ���п��ܵķָ����
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/palindrome-partitioning
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//������ [0,i - 1] �ϵķָ����ȷ��ʱ���������� [i,n - 1] �ķָ����
void findi2End(vector<vector<string>>& ret, vector<string> &currentScheme, const vector<vector<bool>> &dp, const string& s, int i)
{
	int n = s.length();
	if (i == n) //���� [0,n - 1] �ķָ����ȷ�����
	{
		ret.push_back(currentScheme);
		return;
	}
	for (int j = i; j < n; j++) //������һ�������Ӵ� [i,j]
	{
		if (dp[i][j])
		{
			currentScheme.push_back(s.substr(i, j - i + 1)); //�����Ӵ� [i,j] ���뵱ǰ�ָ��
			findi2End(ret, currentScheme, dp, s, j + 1);
			currentScheme.pop_back(); //���ݣ��������Ӵ� [i,j] �ӵ�ǰ�ָ����ɾ������Ϊ���� [i,j] ������ѿ�����ϣ���������Ҫ�������� [i,j + 1]
		}
	}
}

//ʹ��������������������㷨�������еķָ��������һ�ָ�����������̣������� [0,i] �ϵķָ����ȷ��������� j �� [i + 1,n - 1] ���� [i + 1,j] Ϊ�����Ӵ������ȷ������ [0,j] �ϵķָ����ʹ�û����㷨���ȫ������������������������ֱ�� i == n - 1 �������������У���ʹ��Ԥ����Ļ��ڶ�̬�滮�� dp ��������ж����� [i + 1,j] �Ƿ�Ϊ�����Ӵ���
vector<vector<string>> partition(string s)
{
	//Ԥ���� dp ���飬���ڶ�ά��̬�滮��dp[i][j] ��ʾ���� [i,j] �Ƿ�Ϊ�����Ӵ�
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, true));
	for (int j = 1; j < n; j++) //�����ȱ���
	{
		for (int i = j - 1; i >= 0; i--)
		{
			dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
		}
	}
	vector<vector<string>> ret;
	vector<string> currentScheme;
	findi2End(ret, currentScheme, dp, s, 0);
	return ret;
}


int main131()
{
	string s = "ssabba";
	vector<vector<string>> ret = partition(s);
	cout << "main��ret =" << endl;
	for (vector<vector<string>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[";
		for (vector<string>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}