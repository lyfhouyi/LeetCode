#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

//给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
//
//注意 :
//
//	给定的整型数组长度范围是[3, 104]，数组中所有的元素范围是[-1000, 1000]。
//	输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-product-of-three-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：将元素组拆分为正、负两个数组并排序，根据两数组元素的个数返回不同的值。
//int maximumProduct(vector<int>& nums)
//{
//	vector<int>posArray;
//	vector<int>negArray;
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		if (*it >= 0)
//			posArray.push_back(*it);
//		else
//			negArray.push_back(*it);
//	}
//	sort(posArray.begin(), posArray.end(), [=](int A, int B) {return A > B; });
//	sort(negArray.begin(), negArray.end());
//	switch (posArray.size())
//	{
//	case 0:return negArray[negArray.size() - 1] * negArray[negArray.size() - 2] * negArray[negArray.size() - 3];
//	case 1:return negArray[0] * negArray[1] * posArray[0];
//	case 2:return (negArray.size() == 1 ? (posArray[0] * posArray[1] * negArray[0]) : (posArray[0] * negArray[0] * negArray[1]));
//	default:return (negArray.size() > 1 ? (max(posArray[0] * posArray[1] * posArray[2], negArray[0] * negArray[1] * posArray[0])) : (posArray[0] * posArray[1] * posArray[2]));
//	}
//	return 0;
//}


//解法二：将原数组升序排序。则结果只能在“尾部三个数的乘积”或“首部两个数与尾部的乘积”中出现。
//int maximumProduct(vector<int>& nums)
//{
//	sort(nums.begin(), nums.end());
//	int n = nums.size();
//	return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
//}


//解法三：思路同解法二，只不过不使用排序，而是在单指针遍历数组时记录最小的两个数与最大的三个数。
int maximumProduct(vector<int>& nums)
{
	int min1 = INT_MAX;
	int min2 = INT_MAX;
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int max3 = INT_MIN;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		//更新最大的三个数（注意插队）
		if (*it > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = *it;
		}
		else
		{
			if (*it > max2)
			{
				max3 = max2;
				max2 = *it;
			}
			else
				if (*it > max3)
					max3 = *it;
		}

		//更新最小的两个数（注意插队）
		if (*it < min1)
		{
			min2 = min1;
			min1 = *it;
		}
		else
			if (*it < min2)
				min2 = *it;
	}
	return max(max1*max2*max3, max1*min1*min2);
}


int main628()
{
	vector<int> test = { 903, 606, 48, -474, 313, -672, 872, -833, 899, -629, 558, -368, 231, 621, 716, -41, -418, 204, -1, 883, 431, 810, 452, -801, 19, 978, 542, 930, 85, 544, -784, -346, 923, 224, -533, -473, 499, -439, -925, 171, -53, 247, 373, 898, 700, 406, -328, -468, 95, -110, -102, -719, -983, 776, 412, -317, 606, 33, -584, -261, 761, -351, -300, 825, 224, 382, -410, 335, 187, 880, -762, 503, 289, -690, 117, -742, 713, 280, -781, 447, 227, -579, -845, -526, -403, -714, -154, 960, -677, 805, 230, 591, 442, -458, -905, 832, -285, 511, 536, -86 };
	//vector<int> test = {7,3,1,0,0,6};
	int ret = maximumProduct(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}