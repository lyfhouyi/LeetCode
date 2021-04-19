#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//
//�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/contains-duplicate
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ�����򼯺ϡ�����ԭʼ�������飬����Ԫ������������򼯺ϣ����������Ѵ��ڵ�ǰԪ����ֱ�ӷ��� true ��
//bool containsDuplicate(vector<int>& nums)
//{
//	unordered_set<int> valueSet;
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		if (valueSet.count(*it) == 1)
//			return true;
//		valueSet.insert(*it);
//	}
//	return false;
//}


//�ⷨ�����������Ƚ�ԭʼ�������������������������������飬����ǰԪ����ǰһԪ����ȣ���ֱ�ӷ��� true ��
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}
	return false;
}


int main217()
{
	//vector<int> test = { 1,2,3,4 };
	vector<int> test = { };
	//vector<int> test = { 1,1,1,3,3,4,3,2,4,2 };
	bool ret = containsDuplicate(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}