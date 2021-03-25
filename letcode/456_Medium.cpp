#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<stack>

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


//�ⷨһ�����򼯺ϡ�Ԥ���������Сֵ���� minLeft ���Ҳ��������ֵ���� maxRight �����ʹ�õ�ָ�����ԭʼ���飬���������Сֵ���� minLeft ���Ҳ��������ֵ���� maxRight �жϵ�ǰָ��������ܷ�Ϊ 132 ģʽ�����е��м�ֵ(j)���� minLeft[x] < nums[x] && maxRight[x] > minLeft[x] �� x ����Ҫ��
bool find132pattern(vector<int>& nums)
{
	int n = nums.size();
	vector<int> minLeft(n, INT_MAX); //�����Сֵ���飨��¼��ǰλ������Ԫ�ص���Сֵ��
	vector<int> maxRight(n, INT_MIN); //�Ҳ��������ֵ���飨��¼��ǰλ���Ҳ��С�ڵ�ǰԪ�ص�Ԫ�ص����ֵ��

	for (int i = 1; i < n; i++) //Ԥ���������Сֵ����
	{
		minLeft[i] = minLeft[i - 1] < nums[i - 1] ? minLeft[i - 1] : nums[i - 1];
	}

	set<int, greater<int>> valueRight; //�Ҳ���ֵ����
	valueRight.insert(INT_MIN);
	set<int>::iterator it;
	for (int i = n - 1; i >= 0; i--) //Ԥ�����Ҳ��������ֵ����
	{
		it = valueRight.upper_bound(nums[i]);
		maxRight[i] = *it;
		valueRight.insert(nums[i]);
	}

	for (int i = 1; i < n; i++) //�������� 132 ģʽ�����е��м�ֵ
	{
		if (minLeft[i] < nums[i] && maxRight[i] > minLeft[i])
			return true;
	}
	return false;
}


//�ⷨ��������ջ��ʹ���ϸ�ݼ�ջ�洢�п��ܳ�Ϊ 132 ģʽ�����е�����ֵ(k)��Ԫ��ֵ����ָ���������ԭʼ���飬�жϵ�ǰָ��������ܷ�Ϊ 132 ģʽ�����е�����ֵ(i)������ǰԪ�ش���ջ��Ԫ�أ���ջ��Ԫ���ѿ��Գ�Ϊ 132 ģʽ�����е�����ֵ(k)��������Щջ��Ԫ�أ�������ǰԪ��ѹջ���Ż���ֻ���ڵ�ǰԪ�ش��� maxK ʱ�Ž���ѹջ����Ϊ maxK �Ǹ��ŵ�ѡ�񣩣�ʹ�� maxK ��¼���Գ�Ϊ 132 ģʽ�����е�����ֵ(k)��Ԫ�ص����ֵ������ǰָ���Ԫ��ֵС�� maxK �����ҵ���һ�� 132 ģʽ�����С�
//bool find132pattern(vector<int>& nums)
//{
//	int n = nums.size();
//	stack<int> probKStack;
//	int maxK = INT_MIN;
//	for (int i = n - 1; i >= 0; i--)
//	{
//		if (nums[i] < maxK)
//			return true;
//		while (!probKStack.empty() && nums[i] > probKStack.top())
//		{
//			maxK = probKStack.top();
//			probKStack.pop();
//		}
//		if (nums[i] > maxK)
//			probKStack.push(nums[i]);
//	}
//	return false;
//}


int main456()
{
	//vector<int> test = { 5,3,3,4,1,3,2,7,1,1 };
	//vector<int> test = { 3,1,4,2 };
	vector<int> test = { 4,1 };
	//vector<int> test = { -1,3,2,0 };
	bool ret = find132pattern(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}