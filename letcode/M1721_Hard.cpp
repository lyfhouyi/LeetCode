#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量 ? 直方图的宽度为 1。
//
//
//上面是由数组[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/volume-of-histogram-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单调栈。使用一个单调不增栈存储尚可能成为左臂的方柱。当指针正序遍历数组，若当前方柱不高于栈顶方柱，则将当前方柱压栈，并将局部已计算水位置零；若当前方柱高于栈顶方柱，则持续弹栈，并计算栈顶至当前方柱的容积（），并更新局部已计算水位，直到当前方柱不高于栈顶方柱时停止弹栈；循环弹栈结束后需使用当前栈顶再次计算当前方柱成为右臂时仍可容纳的水量，随后将当前方柱压栈，并将局部已计算水位置零；遍历完毕后，盛水容积总和即为所求。
int trapM1721(vector<int>& height)
{
	stack<int> leftIndexStack; //尚可能成为左臂的方柱的索引
	int n = height.size();
	int sumVolume = 0;
	int sumLevel; //局部已计算水位
	for (int i = 0; i < n; i++)
	{
		sumLevel = 0;
		while (!leftIndexStack.empty() && height[i] > height[leftIndexStack.top()])
		{
			sumVolume += (i - leftIndexStack.top() - 1)*(height[leftIndexStack.top()] - sumLevel); //累加当前栈顶作为左臂，当前方柱作为右臂时的容积
			sumLevel = height[leftIndexStack.top()]; //更新局部已计算水位
			leftIndexStack.pop();
		}
		if (!leftIndexStack.empty())
			sumVolume += (i - leftIndexStack.top() - 1)*(height[i] - sumLevel); //累加当前方柱最后一次成为右臂时的容积
		leftIndexStack.push(i);
	}
	return sumVolume;
}


int mainM1721()
{
	vector<int> test = { 0,1,0,2,1,0,1,3,2,1,2,1,1,1,2,3,1,1,3 };
	int ret = trapM1721(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}