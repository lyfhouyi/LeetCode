#include<iostream>
#include<vector>

using namespace std;

//已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
//
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。例如，[0, 1, 2, 4, 4, 4, 5, 6, 6, 7] 在下标 5 处经旋转后可能变为[4, 5, 6, 6, 7, 0, 1, 2, 4, 4] 。
//
//给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。
//
//
//提示：
//
//	1 <= nums.length <= 5000
//	- 10^4 <= nums[i] <= 10^4
//	题目数据保证 nums 在预先未知的某个下标上进行了旋转
//	- 10^4 <= target <= 10^4
//
//
//进阶：
//
//	这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
//	这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二分查找。首先使用循环调整二分查找时 left 的值，随后在使用二分查找判断目标值位于左或右侧时，需按中点 mid 在其旋转中心左或者右分类讨论。
bool search(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left < nums.size() && nums[left] == nums[right])
		left++;
	int mid;
	while (left < right) //二分查找：查找区域 [left,right]
	{
		mid = (left + right) / 2;
		if (nums[left] <= nums[mid] && target <= nums[mid] && target >= nums[left]) //目标值只能位于 [left,mid] 中
		{
			right = mid;
		}
		else if (nums[mid] < nums[left] && (target >= nums[left] || target <= nums[mid])) //目标值只能位于 [left,mid] 中
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return ((left == nums.size() && nums[right] == target) || (left != nums.size() && nums[left] == target));
}


int main81()
{

	vector<int> test = { 1,0,1,1,1 };
	//vector<int> test = { 2,5,6,0,0,1,2 };
	bool ret = search(test, 0);
	cout << "main：ret = " << ret << endl;
	return 0;
}