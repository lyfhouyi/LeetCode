#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
//
//进阶：你能设计一个时间复杂度为 O(log(m + n)) 的算法解决此问题吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/median-of-two-sorted-arrays
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：解题思路类似于归并算法的合并阶段，从小到大依次找到各元素值，直到第 ( m + n ) / 2 个。时间复杂度 O(m + n)
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//{
//	bool isOdd = (nums1.size() + nums2.size()) % 2;
//	int midCnt= (nums1.size() + nums2.size() +1 ) / 2; //中位数为第 midCnt 或 midCnt 及 midCnt + 1 个数
//	vector<int>::iterator it1 = nums1.begin();
//	vector<int>::iterator it2 = nums2.begin();
//	int i = 1;
//	double lastValue = 0;
//	while (i <= midCnt)
//	{
//		if (it1 == nums1.end())
//		{
//			lastValue = *it2;
//			it2++;
//			i++;
//			continue;
//		}
//		if (it2 == nums2.end())
//		{
//			lastValue = *it1;
//			it1++;
//			i++;
//			continue;
//		}
//		if (*it1 < *it2)
//		{
//			lastValue = *it1;
//			it1++;
//		}
//		else
//		{
//			lastValue = *it2;
//			it2++;
//		}
//		i++;
//	}
//	if (isOdd)
//		return lastValue;
//	if (it1 == nums1.end())
//		return (lastValue + *it2)/2;
//	if (it2 == nums2.end())
//		return (lastValue + *it1) / 2;
//	if (*it1 < *it2)
//		return (lastValue + *it1) / 2;
//	else
//		return (lastValue + *it2) / 2;
//}



//解法二：暴力排序。时间复杂度 O((m + n)log (m + n))
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//{
//	bool isOdd = (nums1.size() + nums2.size()) % 2;
//	int midCnt = (nums1.size() + nums2.size() + 1) / 2; //中位数为第 midCnt 或 midCnt 及 midCnt + 1 个数
//	nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//	sort(nums1.begin(), nums1.end());
//	double midValue = 0;
//	if (isOdd)
//		midValue = nums1[midCnt - 1];
//	else
//		midValue = (double(nums1[midCnt - 1] + nums1[midCnt])) / 2;
//	return midValue;
//}


//解法三：划分数组 + 二分查找法。对 shortNums 的任一划分可唯一确定 longNums 的划分，进而可唯一判断该划分的对错及改进方向；使用二分法不断缩小“划分可行解”区间，最终可得到唯一正确的划分。时间复杂度 O(log (min (m + n)))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int>& shortNums = nums1.size() <= nums2.size() ? nums1 : nums2;
	vector<int>& longNums = nums1.size() <= nums2.size() ? nums2 : nums1;

	// [leftIndex,rightIndex] 为“划分可行解”区间：index 为划分的位置，n 个元素，n + 1 个划分。
	int leftIndex_short = 0;
	int rightIndex_short = shortNums.size();
	int dividIndex_short;
	int dividIndex_long;
	int sumCnt = nums1.size() + nums2.size();
	int shortLeft;
	int shortRight;
	int longLeft;
	int longRight;
	while (leftIndex_short < rightIndex_short) //找到满足中位数条件的划分。中位数条件：1.划分左右总数相等或差一；2.划分左元素 <= 划分右元素(即，shortLeft <= longRight && longLeft <= shortRight ，两个子条件不可能同时不满足)。
	{
		dividIndex_short = (leftIndex_short + rightIndex_short + 1) / 2; // shortNums[0 ~ dividIndex_short - 1] 在划分左边；shortNums[dividIndex_short ~ shortNums.size() - 1] 在划分右边；
		dividIndex_long = (sumCnt + 1) / 2 - dividIndex_short; // longNums[0 ~ dividIndex_long - 1] 在划分左边；longNums[dividIndex_long ~ longNums.size() - 1] 在划分右边；
		shortLeft = dividIndex_short == 0 ? INT_MIN : shortNums[dividIndex_short - 1];
		longRight = dividIndex_long == longNums.size() ? INT_MAX : longNums[dividIndex_long];
		if (shortLeft > longRight) //只需判断这一个子条件（或只判断 longLeft > shortRight ，找到满足该子条件的最极限的划分，则此时两个子条件均满足）
		{
			//划分左侧为新的“划分可行解”区间
			rightIndex_short = (dividIndex_short == 1 + leftIndex_short) ? leftIndex_short : dividIndex_short;
		}
		else
			//划分右侧为新的“划分可行解”区间
			leftIndex_short = dividIndex_short;
	}
	//此时 leftIndex_short( = rightIndex_short )为中位数划分
	//cout << "findMedianSortedArrays：中位数划分为：shortNums[0," << leftIndex_short - 1 << "] ，longNums[0," << (sumCnt + 1) / 2 - leftIndex_short - 1 << "]" << endl;
	dividIndex_long = (sumCnt + 1) / 2 - leftIndex_short;
	shortLeft = leftIndex_short == 0 ? INT_MIN : shortNums[leftIndex_short - 1];
	longRight = dividIndex_long == longNums.size() ? INT_MAX : longNums[dividIndex_long];
	shortRight= leftIndex_short == shortNums.size() ? INT_MAX : shortNums[leftIndex_short];
	longLeft = dividIndex_long == 0 ? INT_MIN : longNums[dividIndex_long - 1];
	if (sumCnt % 2)
		return max(longLeft, shortLeft);
	else
		return (double(max(longLeft, shortLeft) + min(longRight, shortRight))) / 2;
}


int main4()
{
	vector<int>test1 = {2 };
	vector<int>test2 = { };
	double ret = findMedianSortedArrays(test1, test2);
	cout << "main：ret = " << ret << endl;
	return 0;
}