#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//����һ���������� nums �������й��� n ��������132 ģʽ�������� ���������� nums[i]��nums[j] �� nums[k] ��ɣ���ͬʱ���㣺i < j < k �� nums[i] < nums[k] < nums[j] ��
//
//��� nums �д��� 132 ģʽ�������� ������ true �����򣬷��� false ��
//
//
//���ף��������뵽ʱ�临�Ӷ�Ϊ O(n ^ 2) �Ľ����������������һ��ʱ�临�Ӷ�Ϊ O(n logn) �� O(n) �Ľ��������
//
//
//��ʾ��
//
//	n == nums.length
//	1 <= n <= 10^4
//	- 10^9 <= nums[i] <= 10^9
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/132-pattern
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����ⷨ��Ԥ���������Сֵ���� minLeft ���Ҳ��������ֵ���� maxRight �����ʹ�õ�ָ�����ԭʼ���飬���������Сֵ���� minLeft ���Ҳ��������ֵ���� maxRight �жϵ�ǰָ��������ܷ�Ϊ 132 ģʽ�����е��м�ֵ(j)���� minLeft[x] < nums[x] && maxRight[x] > minLeft[x] �� x ����Ҫ��
bool find132pattern(vector<int>& nums)
{
	int n = nums.size();
	if (n < 3)
		return false;
	vector<int> minLeft(n, INT_MAX); //�����Сֵ���飨��¼��ǰλ������Ԫ�ص���Сֵ��
	vector<int> maxRight(n, INT_MIN); //�Ҳ��������ֵ���飨��¼��ǰλ���Ҳ��С�ڵ�ǰԪ�ص�Ԫ�ص����ֵ��
	for (int i = 1; i < n; i++) //Ԥ���������Сֵ����
	{
		minLeft[i] = minLeft[i - 1] < nums[i - 1] ? minLeft[i - 1] : nums[i - 1];
	}
	for (int i = 1; i < n; i++) //Ԥ�����Ҳ��������ֵ����
	{
		minLeft[i] = minLeft[i - 1] < nums[i - 1] ? minLeft[i - 1] : nums[i - 1];
	}
	return false;
}


int main()
{
	vector<int> test = { -1,3,2,0 };
	bool ret = find132pattern(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}