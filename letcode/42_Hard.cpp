#include<iostream>
#include<vector>

using namespace std;

//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//提示：
//
//	n == height.length
//	0 <= n <= 3 * 10^4
//	0 <= height[i] <= 10^5
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/trapping-rain-water
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针遍历数组。计算每个“碗”中可以盛放的雨水量。
int trap(vector<int>& height)
{
	int n = height.size();
	int columnSum = 0; //当前“碗”中障碍物的体积之和
	int bowlSum = 0; //所有“碗”中雨水量之和

	//“碗”的右壁正向遍历数组，计算（多个柱同时最高时，最后一个）最高柱之前的盛水量
	int bowlLeft = 0;
	int bowlRight = 1;
	while (true)
	{
		while (bowlRight < n && height[bowlRight] < height[bowlLeft])
		{
			columnSum += height[bowlRight];
			bowlRight++;
		}

		if (bowlRight >= n)
			break;
		//此时 [bowlLeft,bowlRight] 为一个局部最大“碗”
		bowlSum += height[bowlLeft] * (bowlRight - bowlLeft - 1) - columnSum;
		columnSum = 0;
		bowlLeft = bowlRight;
		bowlRight++;
	}

	//此时 bowlLeft 为（多个柱同时最高时，最后一个）最高柱的索引
	//“碗”的左壁反向遍历数组至（多个柱同时最高时，最后一个）最高柱，计算（多个柱同时最高时，最后一个）最高柱之后的盛水量
	int bowlLeft_reverse = n - 2;
	bowlRight = n - 1;
	columnSum = 0;
	while (true)
	{
		while (bowlLeft_reverse > bowlLeft - 1 && height[bowlLeft_reverse] < height[bowlRight])
		{
			columnSum += height[bowlLeft_reverse];
			bowlLeft_reverse--;
		}

		if (bowlLeft_reverse <= bowlLeft - 1)
			break;

		//此时 [bowlLeft_reverse,bowlRight] 为一个局部最大“碗”
		bowlSum += height[bowlRight] * (bowlRight - bowlLeft_reverse - 1) - columnSum;
		columnSum = 0;
		bowlRight = bowlLeft_reverse;
		bowlLeft_reverse--;
	}
	return bowlSum;
}


int main42()
{
	//vector<int> test = { 0,1,0,2,1,0,1,3,2,1,2,1,3,2,1,1,2,1 };
	//vector<int> test = { 4, 2, 0, 3, 2, 5 };
	//vector<int> test = { 4};
	vector<int> test = { 4,2,3 };
	int ret = trap(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}