﻿#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-product-subarray
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//动态规划。计算数组：dp[i][j] 表示区间 [i,j] 的子数组的乘积值。
//状态转移函数：dp[i][j] = dp[i][j - 1] * nums[j] 。
//边界条件：dp[i][i] = nums[i] 。
//最优解：dp[:][:] 的最大值。
int maxProduct(vector<int>& nums)
{
	const int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	int maxValue = INT_MIN;
	int currentMax = INT_MIN;
	int currentMin = INT_MAX;
	int tmp1;
	int tmp2;
	bool skip = false;
	//行优先遍历
	for (int i = 0; i < n; i++)
	{
		skip = false;
		if ((nums[i] == 1 || nums[i] == -1) && (i != 0) && (nums[i - 1] != 0) && (currentMax != 0) && (currentMin != 0))
		{
			tmp1 = currentMax / nums[i - 1];
			tmp2 = currentMin / nums[i - 1];
			currentMax = tmp1 > tmp2 ? tmp1 : tmp2;
			currentMin = tmp1 < tmp2 ? tmp1 : tmp2;
			skip = true;
		}
		if (!skip)
		{
			currentMax = INT_MIN;
			currentMin = INT_MAX;
			for (int j = i; j < n; j++)
			{
				if (i == j)
					dp[i][j] = nums[i];
				else
					dp[i][j] = dp[i][j - 1] * nums[j];
				currentMax = (currentMax > dp[i][j] ? currentMax : dp[i][j]);
				currentMin = (currentMin < dp[i][j] ? currentMin : dp[i][j]);
			}
		}
		maxValue = (maxValue > currentMax ? maxValue : currentMax);
	}
	return maxValue;
}


////双指针遍历数组
//int maxProduct(vector<int>& nums)
//{
//	vector<int>::iterator it1 = nums.begin();
//	vector<int>::iterator it2 = nums.begin();
//	int maxValue = INT_MIN;
//	int currentMax= INT_MIN;
//	int currentValue=1;
//	while (it2 != nums.end())
//	{
//		if (0 == *it2) //区间 [it1,it2] 以 0 开头时，为特殊情况。
//		{
//			maxValue = (maxValue > 0 ? maxValue : 0);
//			it2++;
//			continue;
//		}
//		currentMax = INT_MIN;
//		currentValue = 1;
//		it1 = it2;
//		while (it2 != nums.end())
//		{
//			currentValue *= *it2;
//			if (currentValue >= currentMax)
//				currentMax = currentValue;
//			else
//				break;
//			it2++;
//		}
//		maxValue = (maxValue > currentMax ? maxValue : currentMax);
//	}
//	return maxValue;
//}


int main()
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
	vector<int> test = { -2,-1,-3,3 };
	int ret = maxProduct(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}