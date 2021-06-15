#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//
//
//提示：
//
//	1 <= nums.length <= 3 * 10^4
//	- 2^31 <= nums[i] <= 2^31 - 1
//	nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
//
//
//进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/single-number-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：哈希表。需使用额外空间。
//int singleNumber137(vector<int>& nums)
//{
//	unordered_map<int, int> numMap;
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//		numMap[*it]++;
//	for (unordered_map<int, int>::iterator it = numMap.begin(); it != numMap.end(); it++)
//	{
//		if (it->second == 1)
//			return it->first;
//	}
//	return 0;
//}

//解法二：位运算。答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数。
int singleNumber137(vector<int>& nums)
{
	int ret = 0;
	int n = nums.size();
	int bitSum;
	for (int i = 0; i < 32; i++)
	{
		bitSum = 0;
		for (int j = 0; j < n; j++)
		{
			bitSum += (nums[j] >> i) & 1;
		}
		ret += ((bitSum % 3) & 1) << i;
	}
	return ret;
}


int main137()
{
	vector<int> test = { 0,1,0,1,0,1,99 };
	int ret = singleNumber137(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}