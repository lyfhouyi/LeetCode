#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
//
//
//���ף������ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
//
//
//��ʾ��
//
//	0 <= nums.length <= 300
//	- 2^31 <= nums[i] <= 2^31 - 1
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/first-missing-positive
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ���������顣���¡���ǰû�г��ֵ���С������������
//int firstMissingPositive(vector<int>& nums)
//{
//	int nowMinimum = 0; //��ǰû�г��ֵ���С��������Ϊ nowMinimum + 1
//	sort(nums.begin(), nums.end());
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		if (*it <= nowMinimum)
//			continue;
//		if (*it != nowMinimum + 1)
//			return nowMinimum + 1;
//		nowMinimum++;
//	}
//	return nowMinimum + 1;
//}


//�ⷨ������ϣ��������ֵ���� [1,nums.size()] �����ڵ�ֵ����������ġ�����ֵ�� [1,nums.size() + 1] �����ڵ�ֵ x ӳ�䵽��ϣ����� x - 1 λ�õı�ǣ���ͨ����ϣ�����λ�õı���ж����ֵ��
//int firstMissingPositive(vector<int>& nums)
//{
//	int n = nums.size();
//	vector<bool> hashVec(n,false);
//	for (int i = 0; i < n; i++)
//	{
//		if (1 <= nums[i] && nums[i] <= n)
//			hashVec[nums[i]-1] = true;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (hashVec[i] != true)
//			return i + 1;
//	}
//	return n + 1;
//}


//�ⷨ������ϣ���Ż��档������ֵ���� [1,nums.size()] �����ڵ�ֵ����������ġ�����ֵ�� [1,nums.size() + 1] �����ڵ�ֵ x ӳ�䵽���� x - 1 λ�õı�ǣ���ͨ�������λ�õı���ж����ֵ��
//int firstMissingPositive(vector<int>& nums)
//{
//	int n = nums.size();
//
//	//����ֵ��Ϊ��ǣ������Ҫ�����ԭ�����еķ���ֵ������ֵ���������������������Ч�ģ����Է��ؽ����Ӱ�졣
//	for (int i = 0; i < n; i++)
//	{
//		if (nums[i] <= 0)
//			nums[i] = n + 1;
//	}
//
//	int tmp;
//	//��������ǣ�����Ϊ��ϣ��
//	for (int i = 0; i < n; i++)
//	{
//		tmp = abs(nums[i]);
//		if (tmp <= n && nums[tmp - 1] > 0)
//			nums[tmp - 1] = -nums[tmp - 1];
//	}
//
//	int nowMinimum = 0;
//	//����λ�ñ�ǣ�ȷ������ֵ
//	while (nowMinimum < n && nums[nowMinimum] < 0)
//		nowMinimum++;
//	return nowMinimum + 1;
//}


//�ⷨ�ģ��������飬����������������ֵ���� [1,nums.size()] �����ڵ�ֵ����������ġ�����ֵ�� [1,nums.size() + 1] �����ڵ�ֵ x ���������� x - 1 λ���ϣ���ͨ�������λ�õ���ֵ�Ƿ���λ�ö�Ӧ�ж����ֵ��
int firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		while(nums[i]>=1 && nums[i]<=n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
			swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return n+1;
}

int main41()
{
	vector<int> test = { -10 ,8,6,5,1,3,38,6,7,2 };
	int ret = firstMissingPositive(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}