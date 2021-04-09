#include<iostream>
#include<vector>

using namespace std;

//给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。
//
//实现 NumArray 类：
//
//	NumArray(int[] nums) 用整数数组 nums 初始化对象
//	void update(int index, int val) 将 nums[index] 的值更新为 val
//	int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + nums[left + 1], ..., nums[right]）
//
//
//提示：
//
//	1 <= nums.length <= 3 * 10^4
//	- 100 <= nums[i] <= 100
//	0 <= index < nums.length
//	- 100 <= val <= 100
//	0 <= left <= right < nums.length
//	最多调用 3 * 10^4 次 update 和 sumRange 方法
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/range-sum-query-mutable
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力解法。每次范围求和均需一次遍历。
//算法正确，但时间超时。
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


//树状数组。
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
		int orign = sumRange(index, index); //计算原数组的值（单点查询）
		add(index + 1, val - orign); //单点修改
	}

	int sumRange(int left, int right) //区间查询
	{
		return ask(right + 1) - ask(left);
	}
private:
	vector<int> t;
	int lowbit(int x)
	{
		return x & (-x);
	}
	void add(int tIndex, int value) //原数组的第 tIndex 个元素值加 value （单点修改）
	{
		int n = t.size();
		while (tIndex < n)
		{
			t[tIndex] += value;
			tIndex += lowbit(tIndex);
		}
	}
	int ask(int tIndex) //计算原数组的前 tIndex 项和（查询前缀和）
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
	cout << "main：ret = " << ret << endl;
	return 0;
}