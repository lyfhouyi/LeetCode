#include<iostream>
#include<vector>

using namespace std;

//����һ������ nums ��������������ѯ������һ���ѯҪ����������±��Ӧ��ֵ����һ���ѯҪ�󷵻�������ĳ����Χ��Ԫ�ص��ܺ͡�
//
//ʵ�� NumArray �ࣺ
//
//	NumArray(int[] nums) ���������� nums ��ʼ������
//	void update(int index, int val) �� nums[index] ��ֵ����Ϊ val
//	int sumRange(int left, int right) ���������� nums[left, right] ���ܺͣ�����nums[left] + nums[left + 1], ..., nums[right]��
//
//
//��ʾ��
//
//	1 <= nums.length <= 3 * 10^4
//	- 100 <= nums[i] <= 100
//	0 <= index < nums.length
//	- 100 <= val <= 100
//	0 <= left <= right < nums.length
//	������ 3 * 10^4 �� update �� sumRange ����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/range-sum-query-mutable
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����ⷨ��ÿ�η�Χ��;���һ�α�����
//�㷨��ȷ����ʱ�䳬ʱ��
//class NumArray307 {
//public:
//	NumArray307(vector<int>& nums):numVec(nums)
//	{
//
//	}
//
//	void update(int index, int val) 
//	{
//		numVec[index] = val;
//	}
//
//	int sumRange(int left, int right)
//	{
//		int ret = 0;
//		while (left <= right)
//		{
//			ret += numVec[left];
//			left++;
//		}
//		return ret;
//	}
//private:
//	vector<int> numVec;
//};


//��״���顣
class NumArray307 {
public:
	NumArray307(vector<int>& nums) :t(vector<int>(nums.size() + 1, 0))
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			add(i + 1, nums[i]);
		}
	}

	void update(int index, int val)
	{
		int orign = sumRange(index, index); //����ԭ�����ֵ�������ѯ��
		add(index + 1, val - orign); //�����޸�
	}

	int sumRange(int left, int right) //�����ѯ
	{
		return ask(right + 1) - ask(left);
	}
private:
	vector<int> t;
	int lowbit(int x)
	{
		return x & (-x);
	}
	void add(int tIndex, int value) //ԭ����ĵ� tIndex ��Ԫ��ֵ�� value �������޸ģ�
	{
		int n = t.size();
		while (tIndex < n)
		{
			t[tIndex] += value;
			tIndex += lowbit(tIndex);
		}
	}
	int ask(int tIndex) //����ԭ�����ǰ tIndex ��ͣ���ѯǰ׺�ͣ�
	{
		int ret = 0;
		while (tIndex > 0)
		{
			ret += t[tIndex];
			tIndex -= lowbit(tIndex);
		}
		return ret;
	}
};


int main307()
{
	vector<int> nums = { 1,3,5 };
	NumArray307* obj = new NumArray307(nums);
	obj->update(1, 2);
	int ret = obj->sumRange(0, 2);
	cout << "main��ret = " << ret << endl;
	return 0;
}