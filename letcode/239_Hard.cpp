#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;


//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//
//返回滑动窗口中的最大值。
//
//提示：
//
//	1 <= nums.length <= 105
//	- 104 <= nums[i] <= 104
//	1 <= k <= nums.length
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sliding-window-maximum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//滑动窗：每次确定窗口内的最大值并记录最大值位置（以减少窗口内遍历的可能性）
//算法正确，但时间超时
//vector<int> maxSlidingWindow(vector<int>& nums, int k) 
//{
//	vector<int>::iterator windowBegin = nums.begin();
//	vector<int>::iterator windowLast = nums.begin()+k-1;
//	vector<int>::iterator windowMax = max_element(windowBegin, windowLast+1);
//	vector<int> maxValueInWindow;
//	while (windowLast !=nums.end())
//	{
//		if (windowMax < windowBegin)
//			windowMax = max_element(windowBegin, windowLast+1);
//		else
//		{
//			if (*windowLast >= *windowMax)
//				windowMax = windowLast;
//		}
//		maxValueInWindow.push_back(*windowMax);
//		windowBegin++;
//		windowLast++;
//	}
//	return maxValueInWindow;
//}


//滑动窗：使用一个双向队列记录窗内最大值的可能解，每次移动窗口都要更新这个双向队列，队列的队首元素即当前滑动窗内的最大元素；双向队列的长度可能（可以）小于窗宽
//双向队列的各元素为：pair<int,int>(index,value)
//vector<int> maxSlidingWindow(vector<int>& nums, int k)
//{
//	if (1 == k)
//		return nums;
//	int windowNew = 0;
//	vector<int> maxValueInWindow;
//	deque<pair<int,int>> candidate;
//	int size = nums.size();
//
//	while (windowNew < size) //窗口滑动
//	{
//		//双向队列尾部加入新的元素
//		while ((!candidate.empty())&&(nums[windowNew] >= (candidate.end() - 1)->second)) //弹出双向队列尾部的“无效”元素（“无效”指已不可能称为窗口最大值的元素）
//			candidate.pop_back();
//		candidate.push_back(pair<int,int>(windowNew, nums[windowNew])); //新加入的元素有可能称为窗口的最大值元素
//		
//		//输出窗口的最大值（双向队列的队首元素）
//		if (windowNew >=  k - 1)
//			maxValueInWindow.push_back(candidate[0].second); //初始化填充滑动窗时不输出最大值
//
//		//双向队列头部弹出“过期”元素（“过期”指窗口已滑过该元素），弹出后，剩下的首元素即为当前滑动窗内的最大元素
//		while (candidate[0].first <= windowNew-k+1)
//			candidate.pop_front();
//		
//		windowNew++;
//	}
//	return maxValueInWindow;
//}


//滑动窗：使用一个双向队列记录窗内最大值的可能解，每次移动窗口都要更新这个双向队列，队列的队首元素即当前滑动窗内的最大元素；双向队列的长度可能（可以）小于窗宽
//双向队列的各元素为：元素的索引
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	if (1 == k)
		return nums;
	int windowNew = 0;
	vector<int> maxValueInWindow;
	deque<int> candidate;
	int size = nums.size();

	while (windowNew < size) //窗口滑动
	{
		//双向队列尾部加入新的元素
		while ((!candidate.empty())&&(nums[windowNew] >= nums[*(candidate.end() - 1)])) //弹出双向队列尾部的“无效”元素（“无效”指已不可能称为窗口最大值的元素）
			candidate.pop_back();
		candidate.push_back(windowNew); //新加入的元素有可能称为窗口的最大值元素
		
		//输出窗口的最大值（双向队列的队首元素）
		if (windowNew >=  k - 1)
			maxValueInWindow.push_back(nums[candidate[0]]); //初始化填充滑动窗时不输出最大值

		//双向队列头部弹出“过期”元素（“过期”指窗口已滑过该元素），弹出后，剩下的首元素即为当前滑动窗内的最大元素
		while (candidate[0] <= windowNew-k+1)
			candidate.pop_front();
		
		windowNew++;
	}
	return maxValueInWindow;
}

int main239()
{
	vector<int>test = {  6,6,6,6,6,6,6,6,-2 };
	vector<int> ret = maxSlidingWindow(test,3);
	cout << "main：ret = ";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
		cout << *it << "  ";
	return 0;
}