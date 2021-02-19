#include<iostream>
#include<vector>

using namespace std;

//�ڽ����� 0 �� 1 ������ A �У�һ�� K λ��ת����ѡ��һ������Ϊ K �ģ������������飬ͬʱ���������е�ÿ�� 0 ����Ϊ 1����ÿ�� 1 ����Ϊ 0��
//
//��������� K λ��ת����С�������Ա�����û��ֵΪ 0 ��Ԫ�ء���������ܣ����� - 1��
//
//
//��ʾ��
//
//	1 <= A.length <= 30000
//	1 <= K <= A.length
//	ͨ������6, 749�ύ����13, 850
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//
////̰���㷨�������档ʹ�û��������ӹ�ԭʼ���顣�����ڵ����ָ��ֵΪ 0 ʱ����ת�����ڵ�ֵ������˽���������βʱ����󴰿���Ԫ�ز�ȫΪ 1 �����Ϊ�����ܣ����򷵻ط�ת������
////�㷨��ȷ����ʱ�䳬ʱ��
//int minKBitFlips(vector<int>& A, int K)
//{
//	int n = A.size();
//	int flipCnt = 0;
//	int i;
//	int j;
//
//	//�ƶ�����������ת����Ԫ��ʹ��������
//	for (i = 0; i < n - K + 1; i++)
//	{
//		if (0 == A[i]) //��ת�������ڵ�ֵ
//		{
//			flipCnt++;
//			for (j = 0; j < K; j++)
//			{
//				A[i + j] = !A[i + j];
//			}
//		}
//	}
//
//	//������һ�������Ƿ���������
//	while (i < n)
//	{
//		if (0 == A[i])
//			return -1;
//		i++;
//	}
//	return flipCnt;
//}


//̰���㷨����������Ż��档ʹ�õ�ָ�����ԭʼ���顣��ָ����ָʵ��ֵΪ 0 ʱ��ֵ��ͨ����ʼֵ�͵�ǰλ�÷�ת��������õ��������µ�ǰλ�÷�ת��������Ӧλ�õĲ�����飻��˽���������β��ʱ������ǰָ���ѽ������һ����ת���ڵ����跭ת�����Ϊ�����ܣ����򷵻ط�ת������
int minKBitFlips(vector<int>& A, int K)
{
	int n = A.size();
	int flipCnt = 0;
	vector<int> diff(n); //������顣������� diff[i] ��ʾλ�� i �����λ�� i - 1 ����Ҫ��ת�Ĵ���
	int currentFlipCnt = 0; //��ǰλ�õ�ʵ�ʷ�ת����

	//�ƶ�ָ�룬���㵱ǰλ��Ԫ���Ƿ���Ҫ��ת
	for (int i = 0; i < n; i++)
	{
		currentFlipCnt += diff[i];
		if (0 == (currentFlipCnt + A[i]) % 2) //��ǰλ���跭ת
		{
			flipCnt++;
			currentFlipCnt++;
			if (i + K > n)
				return -1;
			if (i + K != n)
				diff[i + K]--;
		}
	}
	return flipCnt;
}


int main995()
{
	//vector<int> test = { 0,1,0 };
	//vector<int> test = { 1,1,0 };
	vector<int> test = { 0,0,0,1,0,1,1,0 };
	int ret = minKBitFlips(test, 3);
	cout << "main��ret = " << ret << endl;
	return 0;
}