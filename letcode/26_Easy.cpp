#include<iostream>
#include<vector>

using namespace std;

//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//
//
//说明 :
//
//为什么返回数值是整数，但输出的答案是数组呢 ?
//
//请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
//
//你可以想象内部操作如下 :
//
//	// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
//	int len = removeDuplicates(nums);
//
//	// 在函数里修改输入数组对于调用者是可见的。
//	// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
//	for (int i = 0; i < len; i++) {
//		print(nums[i]);
//	}
//
//
//
//提示：
//
//	0 <= nums.length <= 3 * 10^4
//	- 10^4 <= nums[i] <= 10^4
//	nums 已按升序排列
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针。双指针正序遍历数组。使用 itOld 遍历原始数组，若其指向的数组元素未出现过，则将其赋值于 itNew 处，并将 itNew 右移一位。最后 itNew 索引的位置即为新数组的元素个数。
int removeDuplicates26(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return n;
	int itNew = 1; //指向“新数组”的指针
	int itOld = 1; //指向“旧数组”的指针
	int lastValue = nums[0];
	while (itOld < n) //正序遍历“旧数组”
	{
		if (nums[itOld] != lastValue)
		{
			nums[itNew] = nums[itOld];
			lastValue = nums[itOld];
			itNew++;
		}
		itOld++;
	}
	return itNew;
}


int main26()
{
	//vector<int> test = { 1,1,2};
	//vector<int> test = { 1,1,1,2,2,3 };
	vector<int> test = { 0,0,1,1,1,2,2,3,3,4 };
	int ret = removeDuplicates26(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}