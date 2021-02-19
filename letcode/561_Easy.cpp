#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
//
//返回该 最大总和 。
//
//
//提示：
//
//	1 <= n <= 10^4
//	nums.length == 2 * n
//	- 10^4 <= nums[i] <= 10^4
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/array-partition-i
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//排序，间隔取值。
int arrayPairSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int ret = 0;
	int n = nums.size();
	for (int i = 0; i < n; i += 2)
	{
		ret += nums[i];
	}
	return ret;
}


int main561()
{
	//vector<int> test = { 6,2,6,5,1,2 };
	vector<int> test = { 1,4,3,2 };
	int ret = arrayPairSum(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}