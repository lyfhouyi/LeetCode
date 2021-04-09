#include<iostream>

using namespace std;

//����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B��
//
//
//��ʾ :
//
//	1.A��B��Χ��[-2147483648, 2147483647]֮��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/convert-integer-lcci
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ�������������ؽ� A��B ����һλ�����ж�ĩλ�Ƿ���ͬ��
//int convertInteger(int A, int B)
//{
//	int ret = 0;
//	unsigned uA = A;
//	unsigned uB = B;
//	while (uA != 0 || uB != 0) //����ĩλ
//	{
//		ret += ((uA & 1) ^ (uB & 1));
//		uA >>= 1;
//		uB >>= 1;
//	}
//	return ret;
//}


//�ⷨ�����������ȼ��� A �� B �����ֵ��������ֵ�� 1 �ĸ�����Ϊ����
int convertInteger(int A, int B)
{
	unsigned eor = A^B;
	int ret = 0;
	while (eor != 0) //�������һ�� 1 λ
	{
		ret++;
		eor &= eor - 1;
	}
	return ret;
}


int mainM0506()
{
	int ret = convertInteger(826966453, -729934991);
	cout << "main��ret = " << ret << endl;
	return 0;
}