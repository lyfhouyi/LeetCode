#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<climits>

using namespace std;

//给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
//
//如果存在则返回 true，不存在返回 false。
//
//
//提示：
//
//	0 <= nums.length <= 2 * 10^4
//	- 2^31 <= nums[i] <= 2^31 - 1
//	0 <= k <= 10^4
//	0 <= t <= 2^31 - 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/contains-duplicate-iii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：滑动窗口。使用双指针构造滑动窗口，使用有序集合维护窗口内的元素；在窗口滑动的过程中判断窗口外右侧元素加入时能否满足题意。
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	multiset<long> increaseSet;
	multiset<long, greater<long>> decreaseSet;
	int n = nums.size();
	int indexLeft = 0;
	int indexRight = 0;
	multiset<long>::iterator tmpIt;
	while (indexRight < n) //移动滑动窗
	{
		if (indexRight - indexLeft > k) //为窗口外右侧元素腾出空位
		{
			increaseSet.erase(increaseSet.find(nums[indexLeft]));
			decreaseSet.erase(decreaseSet.find(nums[indexLeft]));
			indexLeft++;
		}
		//当前窗口为[indexLeft, indexRight) 判定元素为 nums[indexRight]
		if (((tmpIt = increaseSet.lower_bound(nums[indexRight])) != increaseSet.end() && *tmpIt - nums[indexRight] <= t) || ((tmpIt = decreaseSet.lower_bound(nums[indexRight])) != decreaseSet.end() && nums[indexRight] - *tmpIt <= t))
			return true;
		increaseSet.insert(nums[indexRight]);
		decreaseSet.insert(nums[indexRight]);
		indexRight++;
	}
	return false;
}


//解法一，优化版：滑动窗口。使用双指针构造滑动窗口，使用有序集合维护窗口内的元素；在窗口滑动的过程中判断窗口外右侧元素加入时能否满足题意。
//bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
//{
//	set<long> valueSet;
//	int n = nums.size();
//	int indexLeft = 0;
//	int indexRight = 0;
//	set<long>::iterator tmpIt;
//	while (indexRight < n) //移动滑动窗
//	{
//		if (indexRight - indexLeft > k) //为窗口外右侧元素腾出空位
//		{
//			valueSet.erase(nums[indexLeft]);
//			indexLeft++;
//		}
//		//当前窗口为[indexLeft, indexRight) 判定元素为 nums[indexRight]
//		if ((tmpIt = valueSet.lower_bound(max(nums[indexRight], INT_MIN + t) - t)) != valueSet.end() && *tmpIt <= min(nums[indexRight], INT_MAX - t) + t)
//			return true;
//		valueSet.insert(nums[indexRight]);
//		indexRight++;
//	}
//	return false;
//}


//解法二：滑动窗口。使用双指针构造滑动窗口，使用桶维护窗口内的元素；在窗口滑动的过程中判断窗口外右侧元素加入时能否满足题意。
//bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
//{
//	unordered_map<int, long> ValueBucket; //使用无序哈希表作为桶，将桶编号映射到桶内存储元素的值
//	int n = nums.size();
//	int indexLeft = 0;
//	int indexRight = 0;
//	int bucketNo;
//	while (indexRight < n) //移动滑动窗
//	{
//		if (indexRight - indexLeft > k) //为窗口外右侧元素腾出空位
//		{
//			bucketNo = nums[indexLeft] < 0 ? (nums[indexLeft] + 1) / (t + 1L) - 1 : nums[indexLeft] / (t + 1L); //计算当前元素的桶号（向下取整）
//			ValueBucket.erase(bucketNo);
//			indexLeft++;
//		}
//		//当前窗口为[indexLeft, indexRight) 判定元素为 nums[indexRight]
//		bucketNo = nums[indexRight] < 0 ? (nums[indexRight] + 1) / (t + 1L) - 1 : nums[indexRight] / (t + 1L); //计算当前元素的桶号（向下取整）
//		if (ValueBucket.count(bucketNo) || (ValueBucket.count(bucketNo + 1) && ValueBucket.at(bucketNo + 1) - nums[indexRight] <= t) || (ValueBucket.count(bucketNo - 1) && nums[indexRight] - ValueBucket.at(bucketNo - 1) <= t))
//			return true;
//		ValueBucket.insert(make_pair(bucketNo, nums[indexRight]));
//		indexRight++;
//	}
//	return false;
//}


int main220()
{
	//vector<int> test = { 1,2,3,1 };
	vector<int> test = { 1,5,9,1,5,9 };
	bool ret = containsNearbyAlmostDuplicate(test, 2, 3);
	cout << "main：ret = " << ret << endl;
	return 0;
}