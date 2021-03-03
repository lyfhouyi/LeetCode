#include<iostream>
#include<vector>

using namespace std;

//����һ���Ǹ����� num������ 0 �� i �� num ��Χ�е�ÿ������ i ����������������е� 1 ����Ŀ����������Ϊ���鷵�ء�
//
//���� :
//
//	����ʱ�临�Ӷ�ΪO(n * sizeof(integer))�Ľ��ǳ����ס��������������ʱ��O(n)����һ��ɨ��������
//	Ҫ���㷨�Ŀռ临�Ӷ�ΪO(n)��
//	���ܽ�һ�����ƽⷨ��Ҫ����C++���κ����������в�ʹ���κ����ú������� C++ �е� __builtin_popcount����ִ�д˲�����
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/counting-bits
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ�����ơ�countBits[i] = countBits[i - 1] + 1 ���� i �����λΪ 1 ʱ��countBits[i / 2] ���� i �����λΪ 0 ʱ��
//vector<int> countBits(int num)
//{
//	vector<int> ret(num + 1);
//	for (int i = 1; i <= num; i++)
//	{
//		if (i & 1 == 1)
//			ret[i] = ret[i - 1] + 1;
//		else
//			ret[i] = ret[i >> 1];
//	}
//	return ret;
//}


//�ⷨ�������ơ�countBits[i] = countBits[i >> 1] + (i & 1) ��
//vector<int> countBits(int num)
//{
//	vector<int> ret(num + 1);
//	for (int i = 1; i <= num; i++)
//	{
//		ret[i] = ret[i >> 1] + (i & 1);
//	}
//	return ret;
//}


//�ⷨ�������ơ�countBits[i] = countBits[i & (i - 1)] + 1 ��
vector<int> countBits(int num)
{
	vector<int> ret(num + 1);
	for (int i = 1; i <= num; i++)
	{
		ret[i] = ret[i & (i - 1)] + 1;
	}
	return ret;
}

int main338()
{
	vector<int> ret = countBits(5);
	cout << "main��ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}