#include<iostream>
#include<vector>

using namespace std;

//���죬����ϰ���һ�ҵ������Ӫҵ customers.length ���ӡ�ÿ���Ӷ���һЩ�˿ͣ�customers[i]���������꣬������Щ�˿Ͷ�������һ���ӽ������뿪��
//
//��ĳЩʱ������ϰ�������� �������ϰ��ڵ� i ������������ô grumpy[i] = 1������ grumpy[i] = 0�� ������ϰ�����ʱ����һ���ӵĹ˿;ͻ᲻���⣬������������������ġ�
//
//����ϰ�֪��һ�����ܼ��ɣ��������Լ����������������Լ����� X ���Ӳ���������ȴֻ��ʹ��һ�Ρ�
//
//���㷵����һ��Ӫҵ����������ж��ٿͻ��ܹ��е������������
//
//
//��ʾ��
//
//	1 <= X <= customers.length == grumpy.length <= 20000
//	0 <= customers[i] <= 1000
//	0 <= grumpy[i] <= 1
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/grumpy-bookstore-owner
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����������ȼ����ʼ״̬������Ŀ����������飻����ڸ��������ƶ�����Ϊ X �Ļ������ڣ������ڻ���һ����ҵ����ڲ�����������������ֵ����������������������Ǹ�������Ϊ�������������ڣ������������ȥʣ�಻�����������Ϊ����
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
	int n = customers.size();
	int customerCnt = 0; //��������
	int currentDiscontentCnt = 0; //��ǰ���ڲ�����Ŀ�������
	for (int i = 0; i < X; i++) //��һ������
	{
		customerCnt += customers[i];
		currentDiscontentCnt += customers[i] * grumpy[i];
	}

	int discontentCnt = currentDiscontentCnt; //������Ŀ�������
	int maxDiscontentCnt = currentDiscontentCnt; //���д����в�����Ŀ������������ֵ
	for (int i = 1; i < n - X + 1; i++) //���ڻ���
	{
		customerCnt += customers[i + X - 1];
		discontentCnt += customers[i + X - 1] * grumpy[i + X - 1];
		currentDiscontentCnt = currentDiscontentCnt + customers[i + X - 1] * grumpy[i + X - 1] - customers[i - 1] * grumpy[i - 1];
		maxDiscontentCnt = maxDiscontentCnt > currentDiscontentCnt ? maxDiscontentCnt : currentDiscontentCnt;
	}
	return customerCnt - discontentCnt + maxDiscontentCnt;
}


int main1052()
{
	//vector<int> customers = { 1, 0, 1, 2, 1, 1, 7, 5 };
	//vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
	vector<int> customers = { 10 };
	vector<int> grumpy = { 0 };
	int ret = maxSatisfied(customers, grumpy, 1);
	cout << "main��ret = " << ret << endl;
	return 0;
}