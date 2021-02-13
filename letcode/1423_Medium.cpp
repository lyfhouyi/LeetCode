#include<iostream>
#include<vector>

using namespace std;

//���ſ��� �ų�һ�У�ÿ�ſ��ƶ���һ����Ӧ�ĵ������������������� cardPoints ������
//
//ÿ���ж�������Դ��еĿ�ͷ����ĩβ��һ�ſ��ƣ���������������� k �ſ��ơ�
//
//��ĵ����������õ����е����п��Ƶĵ���֮�͡�
//
//����һ���������� cardPoints ������ k�����㷵�ؿ��Ի�õ���������
//
//
//��ʾ��
//
//	1 <= cardPoints.length <= 10 ^ 5
//	1 <= cardPoints[i] <= 10 ^ 4
//	1 <= k <= cardPoints.length
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//˫ָ�빹�컬�����ڡ�����ָ�� itA �� itB �����ɵĻ�������Ϊ [begin,itA) �� [itB,end) ��ʹ�����������������飬����Ԫ�غ͵����ֵ��Ϊ����
int maxScore(vector<int>& cardPoints, int k)
{
	int n = cardPoints.size();
	int currentSum = 0;
	//��һ����������itA = k , itB = n
	for (int i = 0; i < k; i++)
	{
		currentSum += cardPoints[i];
	}
	int maxSum = currentSum;

	if (n == k) //����ʱ�������ƶ�
		return maxSum;

	//�ӵڶ���λ�ÿ�ʼ�ƶ�����������������Ϊ [begin,itA) �� [itB,end)
	int itB;
	for (int itA = k - 1; itA >= 0; itA--)
	{
		//���Ƴ���Ԫ��λ�� itA �����������Ԫ��λ�� itB ��
		itB = n - k + itA;
		currentSum = currentSum - cardPoints[itA] + cardPoints[itB];
		maxSum = maxSum > currentSum ? maxSum : currentSum;
	}
	return maxSum;
}


int main1423()
{
	vector<int> test = { 1, 79, 80, 1, 1, 1, 200, 1 };
	//vector<int> test = { 1,1000,1 };
	//vector<int> test = { 9,7,7,9,7,7,9 };
	//vector<int> test = { 2,2,2 };
	//vector<int> test = { 1,2,3,4,5,6,1 };
	int ret = maxScore(test, 3);
	cout << "main��ret = " << ret << endl;
	return 0;
}