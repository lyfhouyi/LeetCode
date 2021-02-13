#include<iostream>
#include<vector>

using namespace std;

//当 A 的子数组 A[i], A[i + 1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：
//
//若 i <= k < j，当 k 为奇数时， A[k] > A[k + 1]，且当 k 为偶数时，A[k] < A[k + 1]；
//	或 若 i <= k < j，当 k 为偶数时，A[k] > A[k + 1] ，且当 k 为奇数时， A[k] < A[k + 1]。
//	也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。
//
//	返回 A 的最大湍流子数组的长度。
//
//
//提示：
//
//	1 <= A.length <= 40000
//	0 <= A[i] <= 10 ^ 9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-turbulent-subarray
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针遍历数组。指针 j 作为区间尾遍历数组，找到当前区间首 i 下的最长湍流子数组；若尾部不满足条件，则下一个查找区间的区间首 i_1 置为上一次查找的区间尾 j_0 。
int maxTurbulenceSize(vector<int>& arr)
{
	bool isBigger = false;
	int n = arr.size();
	int j;

	//找到起始判断位置
	for (j = 1; j < n; j++)
	{
		if (arr[j] == arr[j - 1])
			continue;
		isBigger = arr[j] > arr[j - 1] ? true : false;
		break;
	}
	if (j == n)
		return 1;

	//指针 j 作为区间尾遍历数组
	int maxLength = 1;
	int i = j - 1;
	j = j + 1;
	while (j < n)
	{
		if (isBigger && arr[j] < arr[j - 1])
		{
			isBigger = !isBigger;
			j++;
			continue;
		}
		if (!isBigger && arr[j] > arr[j - 1])
		{
			isBigger = !isBigger;
			j++;
			continue;
		}
		maxLength = maxLength > j - i ? maxLength : j - i;

		//开启一个新区间
		i = j - 1;
		isBigger = arr[j] > arr[i] ? true : false;
		j++;
	}
	maxLength = maxLength > j - i ? maxLength : j - i;
	return maxLength;
}


int main978()
{
	//vector<int> test = { 4,8,12,16 };
	vector<int> test = { 100 };
	//vector<int> test = { 5,4,3,5};
	//vector<int> test = { 9,4,2,10,7,8,8,1,9 };
	int ret = maxTurbulenceSize(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}