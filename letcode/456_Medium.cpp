#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<stack>

using namespace std;

//给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
//
//如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
//
//
//进阶：很容易想到时间复杂度为 O(n ^ 2) 的解决方案，你可以设计一个时间复杂度为 O(n logn) 或 O(n) 的解决方案吗？
//
//
//提示：
//
//	n == nums.length
//	1 <= n <= 10^4
//	- 10^9 <= nums[i] <= 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/132-pattern
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：有序集合。预计算左侧最小值数组 minLeft 及右侧受限最大值数组 maxRight ；随后使用单指针遍历原始数组，利用左侧最小值数组 minLeft 及右侧受限最大值数组 maxRight 判断当前指向的数字能否为 132 模式子序列的中间值(j)；若 minLeft[x] < nums[x] && maxRight[x] > minLeft[x] 则 x 满足要求。
bool find132pattern(vector<int>& nums)
{
	int n = nums.size();
	vector<int> minLeft(n, INT_MAX); //左侧最小值数组（记录当前位置左侧的元素的最小值）
	vector<int> maxRight(n, INT_MIN); //右侧受限最大值数组（记录当前位置右侧的小于当前元素的元素的最大值）

	for (int i = 1; i < n; i++) //预计算左侧最小值数组
	{
		minLeft[i] = minLeft[i - 1] < nums[i - 1] ? minLeft[i - 1] : nums[i - 1];
	}

	set<int, greater<int>> valueRight; //右侧数值集合
	valueRight.insert(INT_MIN);
	set<int>::iterator it;
	for (int i = n - 1; i >= 0; i--) //预计算右侧受限最大值数组
	{
		it = valueRight.upper_bound(nums[i]);
		maxRight[i] = *it;
		valueRight.insert(nums[i]);
	}

	for (int i = 1; i < n; i++) //查找满足 132 模式子序列的中间值
	{
		if (minLeft[i] < nums[i] && maxRight[i] > minLeft[i])
			return true;
	}
	return false;
}


//解法二：单调栈。使用严格递减栈存储有可能成为 132 模式子序列的最右值(k)的元素值；单指针逆向遍历原始数组，判断当前指向的数字能否为 132 模式子序列的最左值(i)，若当前元素大于栈中元素，则栈中元素已可以成为 132 模式子序列的最右值(k)，弹出这些栈中元素，并将当前元素压栈（优化：只有在当前元素大于 maxK 时才将其压栈，因为 maxK 是更优的选择）；使用 maxK 记录可以成为 132 模式子序列的最右值(k)的元素的最大值；若当前指向的元素值小于 maxK ，则找到了一个 132 模式子序列。
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
	cout << "main：ret = " << ret << endl;
	return 0;
}