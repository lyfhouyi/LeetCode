#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

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


//解法一：双指针遍历数组。计算每个“碗”中可以盛放的雨水量。
//int trap(vector<int>& height)
//{
//	int n = height.size();
//	int columnSum = 0; //当前“碗”中障碍物的体积之和
//	int bowlSum = 0; //所有“碗”中雨水量之和
//
//	//“碗”的右壁正向遍历数组，计算（多个柱同时最高时，最后一个）最高柱之前的盛水量
//	int bowlLeft = 0;
//	int bowlRight = 1;
//	while (true)
//	{
//		while (bowlRight < n && height[bowlRight] < height[bowlLeft])
//		{
//			columnSum += height[bowlRight];
//			bowlRight++;
//		}
//
//		if (bowlRight >= n)
//			break;
//		//此时 [bowlLeft,bowlRight] 为一个局部最大“碗”
//		bowlSum += height[bowlLeft] * (bowlRight - bowlLeft - 1) - columnSum;
//		columnSum = 0;
//		bowlLeft = bowlRight;
//		bowlRight++;
//	}
//
//	//此时 bowlLeft 为（多个柱同时最高时，最后一个）最高柱的索引
//	//“碗”的左壁反向遍历数组至（多个柱同时最高时，最后一个）最高柱，计算（多个柱同时最高时，最后一个）最高柱之后的盛水量
//	int bowlLeft_reverse = n - 2;
//	bowlRight = n - 1;
//	columnSum = 0;
//	while (true)
//	{
//		while (bowlLeft_reverse > bowlLeft - 1 && height[bowlLeft_reverse] < height[bowlRight])
//		{
//			columnSum += height[bowlLeft_reverse];
//			bowlLeft_reverse--;
//		}
//
//		if (bowlLeft_reverse <= bowlLeft - 1)
//			break;
//
//		//此时 [bowlLeft_reverse,bowlRight] 为一个局部最大“碗”
//		bowlSum += height[bowlRight] * (bowlRight - bowlLeft_reverse - 1) - columnSum;
//		columnSum = 0;
//		bowlRight = bowlLeft_reverse;
//		bowlLeft_reverse--;
//	}
//	return bowlSum;
//}


//解法二：双指针遍历数组。计算当前指针位置可以接到的最大水量。当左壁最大值小于右壁最大值时，左侧指针可以计算，因为其水量限制于其左壁最大值，且其左壁最大值已不可能更大；同理，当右壁最大值小于左壁最大值时，右侧指针可以计算，因为其水量限制于其右壁最大值，且其右壁最大值已不可能更大；两个指针中，必有且仅有一个指针可以计算，则计算该指针，并移动该指针，直到该指针不能计算时，计算另一个指针。
//int trap(vector<int>& height)
//{
//	int n = height.size();
//	int sumWater = 0;
//	int maxLeft = 0; //左壁最大值
//	int maxRight = 0; //右壁最大值
//	int indexLeft = 0; //左侧指针
//	int indexRight = n-1; //右侧指针
//	while (indexLeft <= indexRight)
//	{
//		if (height[indexLeft] >= maxLeft) //左侧指针无法盛水
//		{
//			maxLeft = height[indexLeft];
//			indexLeft++;
//			continue;			
//		}
//		if(height[indexRight] >= maxRight) //右侧指针无法盛水
//		{
//			maxRight = height[indexRight];
//			indexRight--;
//			continue;
//		}
//		if (maxLeft < maxRight) //左侧指针可以计算
//		{
//			sumWater += maxLeft - height[indexLeft];
//			indexLeft++;
//		}
//		else //右侧指针可以计算
//		{
//			sumWater += maxRight - height[indexRight];
//			indexRight--;
//		}
//	}
//	return sumWater;
//}


//解法三：递减栈。单指针遍历数组，计算以当前指针为全局右壁时的最大盛水量，则当该指针移动至数组尾部时，所得即为数组的盛水量。当当前指针（作为右壁）的高度小于栈顶时，将当前指针处的高度压栈，否则逐个计算栈顶位置的盛水量，直到栈顶高度高于当前指针处的高度。
int trap(vector<int>& height)
{
	int n = height.size();
	int sumWater = 0; //以当前指针为右壁时，容器的盛水量
	stack<int> wallStack;
	//遍历数组。以 i 位置为右壁
	int topIndex;
	for (int i = 0; i < n; i++)
	{
		while (!wallStack.empty() && height[wallStack.top()] < height[i])
		{
			topIndex = wallStack.top();
			wallStack.pop();
			if (wallStack.empty())
				break;
			sumWater += (i - wallStack.top() - 1)*(min(height[i], height[wallStack.top()]) - height[topIndex]);
		}
		wallStack.push(i);
	}

	return sumWater;
}

int main42()
{
	vector<int> test = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	//vector<int> test = { 4, 2, 0, 3, 2, 5 };
	//vector<int> test = { 8,5,2,4,3,6,1};
	//vector<int> test = { 5,4,3,2,1 };
	//vector<int> test = { 1,2,3,4,5 };
	int ret = trap(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}