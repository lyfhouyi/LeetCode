#include<iostream>
#include<vector>

using namespace std;

//����һ�����������飬 ���������������1�ĸ�����
//
//
//ע�⣺
//
//	���������ֻ���� 0 ��1��
//	��������ĳ��������������Ҳ����� 10, 000��
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/max-consecutive-ones
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//˫ָ��������顣�����ҵ����������� 1 �������顣
int findMaxConsecutiveOnes(vector<int>& nums) {
	int n = nums.size();
	int j = 0;
	int i = 0;
	int maxLength = 0;
	while (j < n)
	{
		//���㵱ǰ���� 1 �����������󳤶�
		if (1 == nums[j])
		{
			j++;
			continue;
		}
		maxLength = maxLength > j - i ? maxLength : j - i;

		//�ҵ���һ������ 1 �����������ʼλ��
		while (j < n && nums[j] != 1)
		{
			j++;
		}
		i = j;
	}
	maxLength = maxLength > j - i ? maxLength : j - i;
	return maxLength;
}

int main485()
{
	vector<int> test = { 0 };
	int ret = findMaxConsecutiveOnes(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}