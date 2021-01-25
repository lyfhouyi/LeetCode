#include<iostream>
#include<vector>

using namespace std;

//给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
//
//连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
//
//
//提示：
//
//	0 <= nums.length <= 10^4
//	- 10^9 <= nums[i] <= 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历数组
int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int maxLength = 1;
	int currentLength = 1;
	for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++)
	{
		if (*it > *(it - 1))
			currentLength++;
		else
			currentLength = 1;
		maxLength = maxLength > currentLength ? maxLength : currentLength;
	}
	return maxLength;
}


int main674()
{
	//vector<int> test = { -10 ,8,6,5,1,3,38,6,7,2 };
	//vector<int> test = { 1,3,5,4,7 };
	vector<int> test = {  };
	int ret = findLengthOfLCIS(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}