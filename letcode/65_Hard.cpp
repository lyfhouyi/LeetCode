#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

//��Ч���֣���˳�򣩿��Էֳ����¼������֣�
//
//	1.һ�� С�� ���� ����
//	2.����ѡ��һ�� 'e' �� 'E' ���������һ�� ����
//
//С������˳�򣩿��Էֳ����¼������֣�
//
//	1.����ѡ��һ�������ַ���'+' �� '-'��
//	2.������ʽ֮һ��
//		1.����һλ���֣��������һ���� '.'
//		2.����һλ���֣��������һ���� '.' �������ٸ�������һλ����
//		3.һ���� '.' �������������һλ����
//
//��������˳�򣩿��Էֳ����¼������֣�
//
//	1.����ѡ��һ�������ַ���'+' �� '-'��
//	2.����һλ����
//
//
//��ʾ��
//
//	1 <= s.length <= 20
//	s ����Ӣ����ĸ����д��Сд�������֣�0 - 9�����Ӻ� '+' ������ '-' �����ߵ� '.' ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/valid-number
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����ⷨ��ʹ�� strtof() �⺯����
bool isNumber(string s)
{
	char *pEnd;
	float f = strtof(s.c_str(), &pEnd);

	//���������ַ�����
	if (isnan(f))
		return false;
	if (isinf(f))
	{
		if (s[0] == '+' || s[0] == '-')
		{
			if ((s[1]<'0' || s[1]>'9') && (s[1] != '.'))
				return false;
		}
		else if ((s[0]<'0' || s[0]>'9') && (s[0] != '.'))
			return false;
	}

	if (*pEnd != '\0')
		return false;
	return true;
}


int main65()
{
	string test = "+Inf";
	bool ret = isNumber(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}

