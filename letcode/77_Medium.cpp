#include<iostream>
#include<vector>

using namespace std;

//������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/combinations
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����㷨�����ݵ�ǰ���ѡ���Ƿ񽫵�ǰԪ�ؼ��뵽��ǰ����С��������Ƿ񽫵�ǰԪ�ؼ��뵽��ǰ����У�Ϊʹ�⼯�е���ϲ������ظ�Ԫ������ϸ�����ͬ����ÿ��ݹ��У���ǰ���Լ����Ԫ��ֻ�����ϴμ���Ԫ��֮���Ԫ�أ��ݹ������ǰ���Ԫ����������Ҫ��ʱ������ǰ��ϼ���⼯�С�
void findCombination(int n, int beginValue, vector<int>& currentCombination, int k, vector<vector<int>>& ret)
{
	if (currentCombination.size() == k)
	{
		ret.push_back(currentCombination);
		return;
	}
	for (int i = beginValue; i <= n; i++)
	{
		if (currentCombination.size() + n - i + 1 < k) //��֦��ʣ��Ԫ�ؼ�ʹȫ��ѡȡҲ�����ܴﵽ����Ҫ���Ԫ������ʱ��������ǰ�˳�ѭ��
			break;
		currentCombination.push_back(i);
		findCombination(n, i + 1, currentCombination, k, ret);
		currentCombination.pop_back();
	}
	return;
}


//�ݹ顣�ݹ���� findCombination() �������ж�Ӧ�ڵ�ǰ����м����ĸ�Ԫ�ء�
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ret;
	vector<int> currentCombination;
	findCombination(n, 1, currentCombination, k, ret);
	return ret;
}


int main77()
{
	vector<vector<int>> ret = combine(4, 2);
	cout << "main��ret = " << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[";
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}