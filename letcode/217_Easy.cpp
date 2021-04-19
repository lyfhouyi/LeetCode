#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

//给定一个整数数组，判断是否存在重复元素。
//
//如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/contains-duplicate
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：无序集合。遍历原始整数数组，将各元素逐个插入无序集合，若集合中已存在当前元素则直接返回 true 。
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


//解法二：排序。首先将原始整数数组排序，随后遍历排序后的整数数组，若当前元素与前一元素相等，则直接返回 true 。
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
	cout << "main：ret = " << ret << endl;
	return 0;
}