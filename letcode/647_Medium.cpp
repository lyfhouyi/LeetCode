#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//����һ���ַ�������������Ǽ�������ַ������ж��ٸ������Ӵ���
//
//���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���
//
//
//��ʾ��
//
//	������ַ������Ȳ��ᳬ�� 1000 ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/palindromic-substrings
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


////�ⷨһ����ָ��������顣���һ����Ӵ��ĺ����ǣ����û����ַ�����ԳƵ����ʣ���ԭ�ַ����ĸ��ַ�������Ϊ�Ӵ��ĶԳ��ᣨ�������ģ���ÿ���趨�Գ���󣬲�����չ�Ӵ����ҵ������Ļ����Ӵ���ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ� O(1)��
//int countSubstrings(string s)
//{
//	int palindromeCnt = 0;
//	int sSize = s.size();
//	int j;
//	for (int i = 0; i < sSize; i++)
//	{
//		j = 0;
//		while (i - j >= 0 && i + j < sSize && s[i - j] == s[i + j]) //�ҵ��� s[i] Ϊ���ĵĻ����Ӵ�
//		{
//			palindromeCnt++;
//			cout << "countSubstrings���ҵ������ִ�  " << string(s.begin() + i - j, s.begin() + i + j + 1) << endl;
//			j++;
//		}
//
//		if (s[i] == s[i + 1]) //�ҵ��� s[i] s[i+1] Ϊ���ĵĻ����ִ�
//		{
//			j = 0;
//			while (i - j >= 0 && i + j + 1 < sSize && s[i - j] == s[i + j + 1]) //�ҵ��� s[i]s[i+1] Ϊ���ĵĻ����Ӵ�
//			{
//				palindromeCnt++;
//				cout << "countSubstrings���ҵ������ִ�  " << string(s.begin() + i - j, s.begin() + i + j + 1 + 1) << endl;
//				j++;
//			}
//		}
//
//		cout << endl;
//	}
//	return palindromeCnt;
//}


//�ⷨ�������� Manacher �㷨�����������İ뾶�������ÿ����ѡ�������ĵ���չ�������Կռ任ʱ�䣬ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)��
int countSubstrings(string s)
{
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
	int palindromeCnt = 0;
	int cnt = 0;
	for (int i = 1; i < MsSize; i++)
	{
		j = 2 * rCentre - i;
		r = i < rMax ? min(rMaxArray[j] - 1, rMax - i) : 1;
		while (Ms[i - r] == Ms[i + r])
		{
			if (1 == r % 2)
				cout << "countSubstrings���ҵ������Ӵ�  " << ++cnt << "  " << string(Ms.begin() + i - r, Ms.begin() + i + r + 1) << endl;
			r++;
		}
		rMaxArray[i] = r;
		rCentre = i + r - 1 > rMax ? i : rCentre;
		rMax = i + r - 1 > rMax ? i + r - 1 : rMax;
		palindromeCnt += r / 2; //�����İ뾶 - 1 = �û�������������Ӵ��ĳ��ȣ���������Ч�ַ�����
	}
	return palindromeCnt;
}


int main647()
{
	string test = "dfghjkl";
	int ret = countSubstrings(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}