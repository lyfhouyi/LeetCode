#include<iostream>
#include<vector>

using namespace std;

//���� n ���������ҳ�ƽ��������ҳ���Ϊ k �����������飬����������ƽ������
//
//
//��ʾ��
//
//	1 <= k <= n <= 30, 000��
//	�������ݷ�Χ[-10, 000��10, 000]��
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/maximum-average-subarray-i
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//������������������ں͵����ֵ��
double findMaxAverage(vector<int>& nums, int k)
{
	int n = nums.size();
	double currentSum = 0;
	//��һ����������
	for (int i = 0; i < k; i++)
	{
		currentSum += nums[i];
	}
	double maxSum = currentSum;

	//�ӵڶ����������ڿ�ʼ������ [currentRight - k + 1,currentRight] Ϊ��ǰ������
	for (int currentRight = k; currentRight < n; currentRight++)
	{
		//�¼����Ԫ��λ���� currentRight �����Ƴ���Ԫ��λ���� currentRight - k 
		currentSum = currentSum + nums[currentRight] - nums[currentRight - k];
		maxSum = maxSum > currentSum ? maxSum : currentSum;
	}
	return maxSum / k;
}


int main643()
{
	vector<int> test = { 1,12,-5,-6,50,3 };
	//vector<int> test = { 0, 4, 0, 3, 2 };
	double ret = findMaxAverage(test, 4);
	cout << "main��ret = " << ret << endl;
	return 0;
}