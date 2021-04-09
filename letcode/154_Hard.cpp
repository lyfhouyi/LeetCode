#include<iostream>
#include<vector>

using namespace std;

//已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0, 1, 4, 4, 5, 6, 7] 在变化后可能得到：
//	若旋转 4 次，则可以得到[4, 5, 6, 7, 0, 1, 4]
//	若旋转 7 次，则可以得到[0, 1, 4, 4, 5, 6, 7]
//注意，数组[a[0], a[1], a[2], ..., a[n - 1]] 旋转一次 的结果为数组[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] 。
//
//给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
//
//
//提示：
//
//	n == nums.length
//	1 <= n <= 5000
//	- 5000 <= nums[i] <= 5000
//	nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
//
//
//进阶：
//
//	这道题是 寻找旋转排序数组中的最小值 的延伸题目。
//	允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：二分查找。根据中点 mid 处的值与区间左端点的值的大小可确定区间最小值应出现在左侧或右侧；当中点 mid 处的值与区间左端点的值相等时，无法判断最小值应出现在左侧或右侧，此时可将区间左端点右移一位，重新判断。
int findMin154(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid;
	while (left < right) //二分查找：查找区域 [left,right]
	{
		mid = (left + right) / 2;
		if (nums[right] > nums[left]) //区间 [left,right] 已按升序排列
			return nums[left];
		if (nums[left] > nums[mid]) //最小值只能位于 [left,mid] 中
		{
			right = mid;
		}
		else if (nums[left] == nums[mid]) //无法判断最小值出现的区间
		{
			left = left + 1;
		}
		else //最小值只能位于 (mid,right] 中
		{
			left = mid + 1;
		}
	}
	return nums[left];
}


//解法二：二分查找。首先使用循环调整二分查找时 left 的初始值，随后在使用二分查找判断最小值位于左或右侧时，根据中点 mid 处的值与区间左端点的值的大小可确定区间最小值应出现在左侧或右侧。
//int findMin154(vector<int>& nums)
//{
//	int left = 0;
//	int right = nums.size() - 1;
//	while (left < nums.size() && nums[left] == nums[right])
//		left++;
//	int mid;
//	while (left < right) //二分查找：查找区域 [left,right]
//	{
//		mid = (left + right) / 2;
//		if (nums[right] > nums[left]) //区间 [left,right] 已按升序排列
//			return nums[left];
//		if (nums[left] > nums[mid]) //最小值只能位于 [left,mid] 中
//		{
//			right = mid;
//		}
//		else //最小值只能位于 (mid,right] 中
//		{
//			left = mid + 1;
//		}
//	}
//	return (left == nums.size() ? nums[0] : nums[left]);
//}


int main154()
{
	//vector<int> test = { 3,4,5,1,2 };
	//vector<int> test = { 2,2,2,0,1 };
	//vector<int> test = { 1 };
	//vector<int> test = { 3,2,2,2,2,2,3,3,3,3 };
	vector<int> test = { 1,2 };
	//vector<int> test = { 4,4,4,2,2,3 };
	//vector<int> test = { 4,5,6,7,0,1,2 };
	int ret = findMin154(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}