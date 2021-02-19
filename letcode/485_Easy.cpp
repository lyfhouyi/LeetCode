#include<iostream>
#include<vector>

using namespace std;

//给定一个二进制数组， 计算其中最大连续1的个数。
//
//
//注意：
//
//	输入的数组只包含 0 和1。
//	输入数组的长度是正整数，且不超过 10, 000。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/max-consecutive-ones
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针遍历数组。不断找到更长的连续 1 的子数组。
int findMaxConsecutiveOnes(vector<int>& nums) {
	int n = nums.size();
	int j = 0;
	int i = 0;
	int maxLength = 0;
	while (j < n)
	{
		//计算当前连续 1 的子数组的最大长度
		if (1 == nums[j])
		{
			j++;
			continue;
		}
		maxLength = maxLength > j - i ? maxLength : j - i;

		//找到下一个连续 1 的子数组的起始位置
		while (j < n && nums[j] != 1)
		{
			j++;
		}
		i = j;
	}
	maxLength = maxLength > j - i ? maxLength : j - i;
	return maxLength;
}

int main485()
{
	vector<int> test = { 0 };
	int ret = findMaxConsecutiveOnes(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}