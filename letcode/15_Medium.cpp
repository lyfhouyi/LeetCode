#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//
//提示：
//
//	0 <= nums.length <= 3000
//	- 10^5 <= nums[i] <= 10^5
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/3sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：双指针。首先将原始数组升序排序；随后遍历数组中各元素作为元素 A ，使用双指针法判断剩下的数组元素中，能否找到两个元素，数值之和为当前元素的相反数；若当前两元素之和大于 nums[indexA] 的相反数，则令 C 指针左移，若当前两元素之和小于 nums[indexA] 的相反数，则令 B 指针右移；找到满足要求的 B、C 后，需继续查找，直到 B 指针与 C 指针重合时退出查找；每次查找可将当前元素 A 的满足要求的 B、C 组合全部找出。
//vector<vector<int>> threeSum(vector<int>& nums)
//{
//	sort(nums.begin(), nums.end());
//	int n = nums.size();
//	vector<vector<int>> ret;
//	int indexA = 0;
//	while (indexA < n)
//	{
//		int indexB = indexA + 1;
//		int indexC = n - 1;
//		while (indexB < indexC)
//		{
//			if (nums[indexB] + nums[indexC] < -nums[indexA])
//				indexB++;
//			else if (nums[indexB] + nums[indexC] > -nums[indexA])
//				indexC--;
//			else
//			{
//				ret.push_back({ nums[indexA], nums[indexB], nums[indexC] });
//				indexB++;
//				while (indexB < indexC && nums[indexB] == nums[indexB - 1]) //去重：在当前元素 A 下，防止出现重复的 B、C 组合
//					indexB++;
//			}
//		}
//		indexA++;
//		while (indexA < n && nums[indexA] == nums[indexA - 1]) //去重：防止出现重复的 A 再次查找
//			indexA++;
//	}
//	return ret;
//}


//解法二：无序哈希表。首先将原始数组升序排序；随后遍历数组中各元素作为元素 A ，使用无序哈希表判断剩下的数组元素中，能否找到两个元素，数值之和为当前元素的相反数；若 nums[indexBC] 作为 C 值对应的 B 值已出现在当前哈希表中且尚未加入答案数组，则将该 A、B、C 组合加入答案数组，并将 nums[indexBC] 作为 B 值插入到当前哈希表中，并标记为“已加入答案数组”；若 nums[indexBC] 作为 B 值未出现在当前哈希表中，则将其插入当前哈希表作为 B 值，并标记为“未加入答案数组”。
vector<vector<int>> threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();
	vector<vector<int>> ret;
	unordered_map<int, bool> valueMap;
	unordered_map<int, bool>::iterator it;
	int indexA = 0;
	while (indexA < n)
	{
		valueMap.clear();
		int indexBC = indexA + 1;
		while (indexBC < n)
		{
			if ((it = valueMap.find(-nums[indexA] - nums[indexBC])) != valueMap.end())
			{
				if (it->second == false)
				{
					ret.push_back({ nums[indexA], it->first, nums[indexBC] });
					valueMap.insert(make_pair(nums[indexBC], true));
				}
				it->second = true;
			}
			else
				valueMap.insert(make_pair(nums[indexBC], false));
			indexBC++;
		}
		indexA++;
		while (indexA < n && nums[indexA] == nums[indexA - 1]) //去重：防止出现重复的 A 再次查找
			indexA++;
	}
	return ret;
}


int main15()
{
	//vector<int> test = { 0 };
	//vector<int> test = { };
	vector<int> test = { 0,0,0,0,0 };
	//vector<int> test = { -2, 0, 1, 1, 2 };
	//vector<int> test = { -1,0,1,2,-1,-4 };
	vector<vector<int>> ret = threeSum(test);
	cout << "main：ret = " << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[";
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}
