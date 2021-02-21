#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<climits>

using namespace std;

//给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
//
//你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
//
//
//提示：
//
//	nums.length 在1到 50, 000 区间范围内。
//	nums[i] 是一个在 0 到 49, 999 范围内的整数。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/degree-of-an-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//找到 nums 数组中包含 val 值的最长子数组，返回该子数组的长度
int getSubArrayLongestLength(vector<int>& nums, int val)
{
	int n = nums.size();
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		if (nums[i] == val)
			break;
	}
	for (j = n - 1; j >= 0; j--)
	{
		if (nums[j] == val)
			break;
	}
	return j - i + 1;
}


//暴力解法。首先通过无重复集合和可重复集合构造各元素值频数数组；随后将该频数数组按频率降序排序；最后提取全部频数最大的元素值，找到包含全部该元素值的最长子数组长度，则各包含元素值的最长子数组长度的最小值即为所求。
//int findShortestSubArray(vector<int>& nums)
//{
//	unordered_multiset<int> countSet(nums.begin(), nums.end());
//	unordered_set<int> intSet(nums.begin(), nums.end());
//	int n = intSet.size();
//	vector<vector<int>> mapVector(n, vector<int>(2));
//
//	//构造频数数组
//	int i = 0;
//	for (unordered_set<int>::iterator it = intSet.begin(); it != intSet.end(); it++)
//	{
//		mapVector[i][0] = *it;
//		mapVector[i][1] = countSet.count(*it);
//		i++;
//	}
//	sort(mapVector.begin(), mapVector.end(), [](vector<int> A, vector<int> B) {return A[1] > B[1]; });
//
//	//找到度不变的最短子数组
//	int maxCnt = mapVector[0][1];
//	int currentLength;
//	int minLength = INT_MAX;
//	for (i = 0; i < n; i++)
//	{
//		if (maxCnt == mapVector[i][1])
//		{
//			currentLength = getSubArrayLongestLength(nums, mapVector[i][0]);
//			minLength = minLength < currentLength ? minLength : currentLength;
//		}
//		else
//			break;
//	}
//	return minLength;
//}


//优化版。思路同暴力解法，但是将挑选频数最大的元素值及查找该元素值出现的最长子数组的过程融合在一次遍历原数组的过程中。
int findShortestSubArray(vector<int>& nums)
{
	unordered_map<int, vector<int>> countMap; //字典：元素值-(频数,首次出现的位置,末次出现的位置)
	int n = nums.size();
	int maxCnt = 0;
	int minLength = INT_MAX;

	//单指针遍历数组。
	for (int i = 0; i < n; i++)
	{
		//将新的元素加入字典
		if (0 == countMap.count(nums[i]))
		{
			countMap[nums[i]] = vector<int>(3, i);
			countMap.at(nums[i])[0] = 1;
		}
		else
		{
			countMap.at(nums[i])[0]++;
			countMap.at(nums[i])[2] = i;
		}

		//维护字典中最大的频数及其元素值
		if (maxCnt < countMap.at(nums[i])[0] || (maxCnt == countMap.at(nums[i])[0] && countMap.at(nums[i])[2] - countMap.at(nums[i])[1] + 1 < minLength)) //更新挑选出的元素值信息
		{
			maxCnt = countMap.at(nums[i])[0];
			minLength = countMap.at(nums[i])[2] - countMap.at(nums[i])[1] + 1;
		}
	}
	return minLength;
}


int main697()
{
	//vector<int> test = { 1,2,2,3,1 };
	vector<int> test = { 1,2,2,3,1,4,2 };
	int ret = findShortestSubArray(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}