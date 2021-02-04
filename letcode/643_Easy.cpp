#include<iostream>
#include<vector>

using namespace std;

//给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
//
//
//提示：
//
//	1 <= k <= n <= 30, 000。
//	所给数据范围[-10, 000，10, 000]。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/maximum-average-subarray-i
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//遍历滑动窗。求各窗口和的最大值。
double findMaxAverage(vector<int>& nums, int k)
{
	int n = nums.size();
	double currentSum = 0;
	//第一个滑动窗口
	for (int i = 0; i < k; i++)
	{
		currentSum += nums[i];
	}
	double maxSum = currentSum;

	//从第二个滑动窗口开始遍历。 [currentRight - k + 1,currentRight] 为当前滑动窗
	for (int currentRight = k; currentRight < n; currentRight++)
	{
		//新加入的元素位置在 currentRight ，新移出的元素位置在 currentRight - k 
		currentSum = currentSum + nums[currentRight] - nums[currentRight - k];
		maxSum = maxSum > currentSum ? maxSum : currentSum;
	}
	return maxSum / k;
}


int main643()
{
	vector<int> test = { 1,12,-5,-6,50,3 };
	//vector<int> test = { 0, 4, 0, 3, 2 };
	double ret = findMaxAverage(test, 4);
	cout << "main：ret = " << ret << endl;
	return 0;
}