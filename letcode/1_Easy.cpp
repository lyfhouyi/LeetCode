#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
//你可以按任意顺序返回答案。
//
//提示：
//
//	2 <= nums.length <= 103
//	- 109 <= nums[i] <= 109
//	- 109 <= target <= 109
//	只会存在一个有效答案
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/two-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：暴力遍历。双指针暴力遍历原始数组，直到找到满足要求的元素对。
//vector<int> twoSum(vector<int>& nums, int target)
//{
//	int i, j;
//	for (i = 0; i < nums.size(); i++)
//	{
//		for (j = i + 1; j < nums.size(); j++)
//		{
//			if (nums[i] + nums[j] == target)
//			{
//				return { i,j };
//			}
//
//		}
//	}
//	return { i,j };
//}


//解法二：无序哈希表。单指针遍历原始数组，将已遍历过的元素存入无序哈希表；对遍历到的任一元素，检查哈希表中是否包含满足要求的另一元素。
vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> valueMap;
	unordered_map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		if ((it = valueMap.find(target - nums[i])) != valueMap.end())
			return { i,it->second };
		valueMap.insert(make_pair(nums[i], i));
	}
	return { 0,0 };
}


int main1()
{
	vector<int> test1 = { 3,2,4 };
	vector<int> ret = twoSum(test1, 6);
	cout << "main：ret = [" << ret[0] << "," << ret[1] << "]" << endl;
	return 0;
}