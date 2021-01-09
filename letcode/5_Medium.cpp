#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
//
//
//��ʾ��
//
//	1 <= s.length <= 1000
//	s �������ֺ�Ӣ����ĸ����д�� / ��Сд�����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/longest-palindromic-substring
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//ʹ�� Manacher �㷨��������İ뾶���飬���������İ뾶�����ҵ���Ļ����Ӵ���
string longestPalindrome(string s)
{
	// Manacher �㷨
	//��ʼ��ĸ��
	string Ms = "$#";
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		Ms += *it;
		Ms += '#';
	}
	Ms += "!";
	//cout << s << endl;
	//cout << Ms << endl;

	int MsSize = Ms.size();
	vector<int> rMaxArray(MsSize, 1); //��λ�������İ뾶��ʼ��Ϊ 1

	int r = 0;
	int rMax = 1; //�������Ҷ˵�
	int rCentre = 1; //�������Ҷ˵��Ӧ�Ļ�������
	int j = 0;
	//int cnt = 0;

	for (int i = 1; i < MsSize; i++)
	{
		j = 2 * rCentre - i;
		r = i < rMax ? min(rMaxArray[j] - 1, rMax - i) : 1;
		while (Ms[i - r] == Ms[i + r])
		{
			//if (1 == r % 2)
			//	cout << "countSubstrings���ҵ������Ӵ�  " << ++cnt << "  " << string(Ms.begin() + i - r, Ms.begin() + i + r + 1) << "����="<<r<<endl;
			r++;
		}
		rMaxArray[i] = r;
		rCentre = i + r - 1 > rMax ? i : rCentre;
		rMax = i + r - 1 > rMax ? i + r - 1 : rMax;
	}

	//����������Ӵ�
	vector<int>::iterator longestPos = max_element(rMaxArray.begin(), rMaxArray.end());
	int longestIndex = longestPos - rMaxArray.begin();
	string ret;
	for (string::iterator it = Ms.begin() + longestIndex - *longestPos + 1; it != Ms.begin() + longestIndex + *longestPos; it++)
	{
		if (*it != '#')
			ret += *it;
	}
	return ret;
}


int main5()
{
	string test = "abba";
	string ret = longestPalindrome(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}