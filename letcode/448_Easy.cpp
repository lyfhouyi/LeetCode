#include<iostream>
#include<vector>

using namespace std;

//给定一个范围在  1 ≤ a[i] ≤ n(n = 数组大小) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
//
//找到所有在[1, n] 范围之间没有出现在数组中的数字。
//
//您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗 ? 你可以假定返回的数组不算在额外空间内。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：就地哈希。将 1 至 n 中出现的值 val 所对应的位置标记为负，通过查看标记后的数组各位置的正负性判断缺失的值。
//vector<int> findDisappearedNumbers(vector<int>& nums)
//{
//	int n = nums.size();
//	for (int i = 0; i < n; i++)
//	{
//		nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
//	}
//	vector<int> ret;
//	for (int i = 0; i < n; i++)
//	{
//		if (nums[i] > 0)
//			ret.push_back(i + 1);
//	}
//	return ret;
//}


//解法二：即时归位。不断将 1 至 n 中出现的值 val 归位至其应该对应的位置，将全部 val 都归位后，通过查看 val 与其位置的不相符情况判断缺失的值。
vector<int> findDisappearedNumbers(vector<int>& nums)
{
	int n = nums.size();
	int currentValue;
	for (int i = 0; i < n; i++)
	{
		currentValue = nums[i];
		while (nums[currentValue - 1] != currentValue)
		{
			swap(currentValue, nums[currentValue - 1]);
		}
	}
	vector<int> ret;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != i + 1)
			ret.push_back(i + 1);
	}
	return ret;
}

int main448()
{
	vector<int> test = { 4,3,2,7,8,2,3,1 };
	vector<int> ret = findDisappearedNumbers(test);
	cout << "main：ret = ";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}