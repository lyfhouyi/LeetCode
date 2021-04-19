#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums[i] = nums[j]，并且 i 和 j 的差的 绝对值 至多为 k。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/contains-duplicate-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//滑动窗口。使用双指针构造滑动窗口，使用无序集合维护窗口内的元素；在窗口滑动的过程中判断窗口外右侧元素是否与集合中某元素相等。
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_set<int> valueSet;
	int n = nums.size();
	int indexLeft = 0;
	int indexRight = 0;
	while (indexRight < n) //移动滑动窗
	{
		if (indexRight - indexLeft > k) //为窗口外右侧元素腾出空位
		{
			valueSet.erase(nums[indexLeft]);
			indexLeft++;
		}
		//当前窗口为[indexLeft, indexRight) 判定元素为 nums[indexRight]
		if (valueSet.count(nums[indexRight]) == 1)
			return true;
		valueSet.insert(nums[indexRight]);
		indexRight++;
	}
	return false;
}


int main219()
{
	//vector<int> test = { 1,2,3,1 };
	vector<int> test = { 1,2,3,1,2,3 };
	bool ret = containsNearbyDuplicate(test, 2);
	cout << "main：ret = " << ret << endl;
	return 0;
}
