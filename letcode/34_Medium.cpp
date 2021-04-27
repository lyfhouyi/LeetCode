#include<iostream>
#include<vector>

using namespace std;

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回 [-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//
//
//提示：
//
//	0 <= nums.length <= 10^5
//	- 10^9 <= nums[i] <= 10^9
//	nums 是一个非递减数组
//	- 10^9 <= target  <= 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：暴力解法。正序遍历 nums 数组，找到目标值出现的第一个及最后一个位置索引。
//vector<int> searchRange(vector<int>& nums, int target)
//{
//	vector<int> ret(2, -1);
//	int n = nums.size();
//	bool hasFind = false;
//	for (int i = 0; i < n; i++)
//	{
//		if (nums[i] == target && !hasFind) //找到目标值出现的起始位置
//		{
//			ret[0] = i;
//			hasFind = true;
//		}
//		if (nums[i] != target && hasFind) //找到目标值出现的结束位置
//		{
//			ret[1] = i - 1;
//			return ret;
//		}
//	}
//	if (ret[0] != -1 && ret[1] == -1) //处理 nums 数组最后一个元素是目标值的情况
//		ret[1] = n - 1;
//	return ret;
//}


//解法二：二分查找。分别使用二分查找法找到目标值出现的第一个及最后一个位置索引。
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> ret(2, -1);
	int n = nums.size();
	if (n == 0)
		return ret;

	//找到目标值出现的第一个位置
	int left = 0;
	int right = n - 1;
	int mid;
	while (left < right) //二分查找：查找区域 [left,right]
	{
		mid = (left + right) / 2;
		if (nums[mid] < target) //目标值只能位于 [mid + 1,right] 中
			left = mid + 1;
		else //目标值只能位于 [left,mid] 中
			right = mid;
	}

	if (nums[left] != target) //处理 nums 数组中不包含目标值的情况
		return ret;
	ret[0] = left;

	//找到目标值出现的最后一个位置
	left = 0;
	right = n - 1;
	while (left < right)
	{
		mid = (left + right + 1) / 2;
		if (nums[mid] <= target) //目标值只能位于 [mid,right] 中
			left = mid;
		else //目标值只能位于 [left,mid - 1] 中
			right = mid - 1;
	}
	ret[1] = left;
	return ret;
}


int main()
{
	//vector<int> test = { 8,8,8,8,8,8,9 };
	vector<int> test = { };
	vector<int> ret = searchRange(test, 10);
	cout << "main：ret = [" << ret[0] << "," << ret[1] << "]" << endl;
	return 0;
}