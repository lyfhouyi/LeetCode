#include<iostream>

using namespace std;

//С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�
//
//����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�
//
//������� ��� �ܺȵ�����ƿ�ơ�
//
//
//��ʾ��
//
//	1 <= numBottles <= 100
//	2 <= numExchange <= 100
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/water-bottles
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ���������еĺȾͺȣ����껻��ƿ��
//int numWaterBottles(int numBottles, int numExchange)
//{
//	int ret = 0;
//	int emptyCnt = 0;
//	int fullCnt = numBottles;
//	while (fullCnt > 0) //�Ⱥȣ��ٻ���ƿ
//	{
//		ret += fullCnt; //��
//		emptyCnt += fullCnt; //����ʣ�¿�ƿ
//		fullCnt = emptyCnt / numExchange; //����ƿ
//		emptyCnt = emptyCnt % numExchange; //����ʣ�¿�ƿ
//	}
//	return ret;
//}


//�ⷨ������ѧ�����Ի�ƿ������ n = 1 + (numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) : -1) ��ÿ�ֻ� 1 ƿ��
int numWaterBottles(int numBottles, int numExchange)
{
	return numBottles + 1 + (numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) : -1);
}


int main1518()
{
	int ret = numWaterBottles(5, 5);
	cout << "main��ret = " << ret << endl;
	return 0;
}