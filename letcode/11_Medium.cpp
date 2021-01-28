#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//说明：你不能倾斜容器。
//
//
//提示：
//
//	n = height.length
//	2 <= n <= 3 * 104
//	0 <= height[i] <= 3 * 104
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/container-with-most-water
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针遍历数组。
int maxArea(vector<int>& height)
{
	bool hasChanged = true;
	int n = height.size();
	int left = 0;
	int right = n - 1;
	int maxContent =min(height[left], height[right]) *(right-left);
	while (left!= right)
	{
		if (height[left] < height[right]) //尝试移动左壁
			left++;
		else //尝试移动右壁
			right--;
		maxContent = max(maxContent, min(height[left], height[right]) *(right - left));
	}
	return maxContent;
}


//暴力解法：双指针遍历数组。
//int maxArea(vector<int>& height)
//{
//	int n = height.size();
//	int maxContent = 0;
//	int tmp;
//	for (int i = 0; i < n; i++)
//	{
//		if (0 == height[i])
//			continue;
//		if (height[i] * (n - i) < maxContent) // i 的取值优化：容积上限优化
//			continue;
//		for (int j = maxContent / height[i] + i+1; j < n; j++) // j 的初值优化：间隔下限优化
//		{
//			tmp = min(height[i], height[j])*(j - i);
//			maxContent = maxContent > tmp ? maxContent : tmp;
//		}
//	}
//	return maxContent;
//}


int main11()
{
	vector<int> test = { 2,3,4,5,18,17,6 };
	//vector<int> test = { 0,2 };
	int ret = maxArea(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}