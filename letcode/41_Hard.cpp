#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
//
//
//进阶：你可以实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案吗？
//
//
//提示：
//
//	0 <= nums.length <= 300
//	- 2^31 <= nums[i] <= 2^31 - 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/first-missing-positive
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：遍历数组。更新“当前没有出现的最小的正整数”。
//int firstMissingPositive(vector<int>& nums)
//{
//	int nowMinimum = 0; //当前没有出现的最小的正整数为 nowMinimum + 1
//	sort(nums.begin(), nums.end());
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		if (*it <= nowMinimum)
//			continue;
//		if (*it != nowMinimum + 1)
//			return nowMinimum + 1;
//		nowMinimum++;
//	}
//	return nowMinimum + 1;
//}


//解法二：哈希表。凡是数值不在 [1,nums.size()] 区间内的值都是无意义的。将数值在 [1,nums.size() + 1] 区间内的值 x 映射到哈希数组的 x - 1 位置的标记，则通过哈希数组各位置的标记判断输出值。
//int firstMissingPositive(vector<int>& nums)
//{
//	int n = nums.size();
//	vector<bool> hashVec(n,false);
//	for (int i = 0; i < n; i++)
//	{
//		if (1 <= nums[i] && nums[i] <= n)
//			hashVec[nums[i]-1] = true;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (hashVec[i] != true)
//			return i + 1;
//	}
//	return n + 1;
//}


//解法三：哈希表优化版。凡是数值不在 [1,nums.size()] 区间内的值都是无意义的。将数值在 [1,nums.size() + 1] 区间内的值 x 映射到数组 x - 1 位置的标记，则通过数组各位置的标记判断输出值。
//int firstMissingPositive(vector<int>& nums)
//{
//	int n = nums.size();
//
//	//将负值作为标记，因此需要先清除原数组中的非正值，非正值被“清除”后，其依旧是无效的，即对返回结果无影响。
//	for (int i = 0; i < n; i++)
//	{
//		if (nums[i] <= 0)
//			nums[i] = n + 1;
//	}
//
//	int tmp;
//	//对数组打标记，本质为哈希表
//	for (int i = 0; i < n; i++)
//	{
//		tmp = abs(nums[i]);
//		if (tmp <= n && nums[tmp - 1] > 0)
//			nums[tmp - 1] = -nums[tmp - 1];
//	}
//
//	int nowMinimum = 0;
//	//检查各位置标记，确定返回值
//	while (nowMinimum < n && nums[nowMinimum] < 0)
//		nowMinimum++;
//	return nowMinimum + 1;
//}


//解法四：遍历数组，持续交换。凡是数值不在 [1,nums.size()] 区间内的值都是无意义的。将数值在 [1,nums.size() + 1] 区间内的值 x 交换到数组 x - 1 位置上，则通过数组各位置的数值是否与位置对应判断输出值。
int firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		while(nums[i]>=1 && nums[i]<=n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
			swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return n+1;
}

int main41()
{
	vector<int> test = { -10 ,8,6,5,1,3,38,6,7,2 };
	int ret = firstMissingPositive(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}