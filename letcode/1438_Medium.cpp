#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

//给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
//
//如果不存在满足条件的子数组，则返回 0 。
//
//
//提示：
//
//	1 <= nums.length <= 10 ^ 5
//	1 <= nums[i] <= 10 ^ 9
//	0 <= limit <= 10 ^ 9
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：使用双指针构造滑动窗口。使用有序集合计算窗口内任意两元素的绝对差的最大值，若该最大值大于 limit 则将窗口左端右移一位，否则将窗口右端右移一位；满足要求的滑动窗口的最大长度即为所求。
//int longestSubarray(vector<int>& nums, int limit)
//{
//	multiset<int> windowConclude;
//	int n = nums.size();
//	int windowRight = 0;
//	int windowLeft = 0;
//	int maxLength = 0;
//	int currentLength;
//
//	//以 [windowLeft,windowRight] 为滑动窗口
//	while (windowRight < n)
//	{
//		windowConclude.insert(nums[windowRight]);
//
//		//找到以 windowRight 为右端点的满足要求的最长子数组
//		while (*windowConclude.rbegin() - *windowConclude.begin() > limit) //不断移出子数组左端的元素
//		{
//			windowConclude.erase(windowConclude.find(nums[windowLeft]));
//			windowLeft++;
//		}
//		currentLength = windowRight - windowLeft + 1;
//		maxLength = maxLength > currentLength ? maxLength : currentLength;
//		windowRight++;
//	}
//	return maxLength;
//}


//解法二：使用双指针构造滑动窗口。使用单调队列计算窗口内任意两元素的绝对差的最大值，若该最大值大于 limit 则将窗口左端右移一位，否则将窗口右端右移一位；满足要求的滑动窗口的最大长度即为所求。
int longestSubarray(vector<int>& nums, int limit)
{
	deque<int> maxQueue; //最大值队列。存储可能成为滑动窗最大值的元素值。单调减
	deque<int> minQueue; //最小值队列。存储可能成为滑动窗最小值的元素值。单调增
	int n = nums.size();
	int windowRight = 0;
	int windowLeft = 0;
	int maxLength = 0;
	int currentLength;

	//以 [windowLeft,windowRight] 为滑动窗口
	while (windowRight < n)
	{
		while (!maxQueue.empty() && nums[windowRight] > maxQueue.back())
			maxQueue.pop_back(); //这些元素值已不可能成为滑动窗口的最大值
		while (!minQueue.empty() && nums[windowRight] < minQueue.back())
			minQueue.pop_back(); //这些元素值已不可能成为滑动窗口的最小值

		maxQueue.push_back(nums[windowRight]);
		minQueue.push_back(nums[windowRight]);

		//找到以 windowRight 为右端点的满足要求的最长子数组
		while (maxQueue.front()- minQueue.front() > limit) //不断移出子数组左端的元素
		{
			if (nums[windowLeft] == maxQueue.front()) //移出的是原窗口的最大值
				maxQueue.pop_front();
			if (nums[windowLeft] == minQueue.front()) //移出的是原窗口的最小值
				minQueue.pop_front();
			windowLeft++;
		}
		currentLength = windowRight - windowLeft + 1;
		maxLength = maxLength > currentLength ? maxLength : currentLength;
		windowRight++;
	}
	return maxLength;
}


int main1438()
{
	//vector<int> test = { 10,1,2,4,7,2 };
	//vector<int> test = { 0,3,6,0,14,10,12,9,17 };
	vector<int> test = { 4,2,2,2,4,4,2,2 };
	//vector<int> test = { 8,2,4,7 };
	int ret = longestSubarray(test, 0);
	cout << "main：ret = " << ret << endl;
	return 0;
}