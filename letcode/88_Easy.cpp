#include<iostream>
#include<vector>
#include<climits>


using namespace std;

//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//
//
//说明：
//
//		初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//		你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//提示：
//
//		-10 ^ 9 <= nums1[i], nums2[i] <= 10 ^ 9
//		nums1.length == m + n
//		nums2.length == n
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：双指针/从前往后排序。时间复杂度 O(m+n)，空间复杂度 O(m)
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
//{
//	vector<int>mergeVec(m + n);
//	vector<int>::iterator it1 = nums1.begin();
//	vector<int>::iterator it2 = nums2.begin();
//	vector<int>::iterator itMerge = mergeVec.begin();
//	int value1;
//	int value2;
//	while ((it1 != nums1.begin() + m) || (it2 != nums2.begin() + n))
//	{
//		value1 = (it1 == nums1.begin() + m) ? INT_MAX : *it1;
//		value2 = (it2 == nums2.begin() + n) ? INT_MAX : *it2;
//		if (value1 <= value2)
//		{
//			*itMerge = value1;
//			it1++;
//		}
//		else
//		{
//			*itMerge = value2;
//			it2++;
//		}
//		itMerge++;
//	}
//	nums1.assign(mergeVec.begin(), mergeVec.end());
//}


//解法二：双指针/从后往前排序。时间复杂度 O(m+n)，空间复杂度 O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int>::iterator it1 = nums1.begin()+m;
	vector<int>::iterator it2 = nums2.begin()+n;
	vector<int>::iterator itMerge = nums1.end();
	int value1;
	int value2;
	while ((it1 != nums1.begin()) || (it2 != nums2.begin()))
	{
		value1 = (it1 == nums1.begin()) ? INT_MIN : *(it1-1);
		value2 = (it2 == nums2.begin()) ? INT_MIN : *(it2-1);
		if (value1 > value2)
		{
			*(itMerge-1) = value1;
			it1--;
		}
		else
		{
			*(itMerge - 1) = value2;
			it2--;
		}
		itMerge--;
	}
}

int main88()
{
	vector<int> test1 = { };
	vector<int> test2 = {};
	merge(test1,0,test2,0);
	cout << "main：";
	for (vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
		cout << *it << "  ";
	return 0;
}