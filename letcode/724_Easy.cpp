#include<iostream>
#include<vector>

using namespace std;

//给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
//
//我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果数组不存在中心索引，那么我们应该返回 - 1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
//
//
//说明：
//
//	nums 的长度范围为 [0, 10000]。
//	任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/find-pivot-index
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历数组。记录左侧和。
int pivotIndex(vector<int>& nums)
{
	int n = nums.size();
	if (0 == n)
		return -1;
	vector<int> sumLeft(n, 0);
	for (int i = 1; i < n; i++)
	{
		sumLeft[i] = sumLeft[i - 1] + nums[i - 1];
	}
	int sumAll = sumLeft[n - 1] + nums[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (2 * sumLeft[i] == sumAll - nums[i])
			return i;
	}
	return -1;
}


int main724()
{
	vector<int> test = { -1,-1,-1,-1,-1,-1 };
	int ret = pivotIndex(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}