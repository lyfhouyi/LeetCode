#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//
//进阶 :
//
//	如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-subarray
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//二维动态规划。计算数组：dp[i][j] 表示区间 [i,j] 的子数组的和值。
//状态转移函数：dp[i][j] = dp[i][j - 1] + nums[j] 。
//边界条件：dp[i][i] = nums[i] 。
//最优解：dp[:][:] 的最大值。
//算法正确，但时间超时
//int maxSubArray(vector<int>& nums)
//{
//	const int n = nums.size();
//	vector<vector<int>> dp(n, vector<int>(n, 0));
//	int maxValue = INT_MIN;
//
//	//行优先遍历
//	for (int i = 0; i < n; i++)
//	{
//			for (int j = i; j < n; j++)
//			{
//				if (i == j)
//					dp[i][j] = nums[i];
//				else
//					dp[i][j] = dp[i][j - 1] + nums[j];
//				maxValue = (maxValue > dp[i][j] ? maxValue : dp[i][j]);
//			}
//	}
//	return maxValue;
//}


//解法一：一维动态规划。计算数组：dp[i] 任意一个以 i 为结尾的子区间 [x,i] 的和的最大值。
//状态转移函数：dp[i] = max(dp[i - 1] + nums[i], nums[i]) 。
//边界条件：dp[0] = nums[0] 。
//最优解：dp[:] 的最大值。
//int maxSubArray(vector<int>& nums)
//{
//	int n = nums.size();
//	vector<int> dp(n, 0);
//	int maxValue = INT_MIN;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (0 == i)
//			dp[i] = nums[i];
//		else
//			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//		maxValue = maxValue > dp[i] ? maxValue : dp[i];
//	}
//	return maxValue;
//}

//解法一的优化。使用滚动数组，降低空间复杂度，以时间换空间。
int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(2, 0);
	int maxValue = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (0 == i)
			dp[i%2] = nums[i];
		else
			dp[i%2] = max(dp[(i - 1)%2] + nums[i], nums[i]);
		maxValue = maxValue > dp[i%2] ? maxValue : dp[i%2];
	}
	return maxValue;
}


//解法二：贪心算法。单指针遍历数组，若当前指针之前的和为负，则其不可能对最大和有贡献，应舍弃之前的和，而保留当前的指针位置的值。
//int maxSubArray(vector<int>& nums)
//{
//	int maxValue = INT_MIN; //最大和
//	int beforeValue= INT_MIN; //之前的（连续的）和
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		if (beforeValue < 0)
//			beforeValue = *it;
//		else
//			beforeValue += *it;
//		maxValue = (maxValue > beforeValue ? maxValue : beforeValue);
//	}
//	return maxValue;
//}


int main53()
{
	//vector<int> test = { 2,3,-2,4 };
	//vector<int> test = { -2,0,-1 };
	//vector<int> test = {2,3,8,0,2,5};
	//vector<int> test = { -1,-1 };
	//vector<int> test = {-3,0,1,-2};
	//vector<int> test = { -2,0,-1 };
	//vector<int> test = {-3,0,-1,-2};
	//vector<int> test = { 0,-3 ,1,1 };
	//vector<int> test = {-2,1,0};
	vector<int> test = { -2,1,-3,4,-1,2,1,-5,4 };
	//vector<int> test = { 5,6,-3,4,-3 };
	int ret = maxSubArray(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}