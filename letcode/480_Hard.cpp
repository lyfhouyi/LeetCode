#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

//中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
//
//例如：
//
//	[2, 3, 4]，中位数是 3
//	[2, 3]，中位数是(2 + 3) / 2 = 2.5
//	给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
//
//
//提示：
//
//	你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
//	与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sliding-window-median
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//利用 multiset 求窗口中位数。若移进的元素与移出的元素均比上个窗口的中位数大（小），则中位数不变，只需更改大（小）侧的 multiset；否则需更改两侧的 multiset 后，方可求出当前窗口中位数。实际上，由于 multiset 的 begin() 方法时间复杂度为 O(1)，因而两种情况均可先更改 multiset ，再求中位数。
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
	int n = nums.size();
	vector<double> median(n - k + 1);
	multiset<double> bigSide; //大于中位数的 multiset（小顶堆）
	multiset<double,greater<double>> littleSide; //小于中位数的 multiset（大顶堆）
	int tmpValue;

	//第一个滑动窗口
	vector<int> tmp(nums.begin(), nums.begin() + k);
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < k; i++)
	{
		if (i < (k + 1) / 2)
			littleSide.insert(tmp[i]);
		else
			bigSide.insert(tmp[i]);
	}
	if (1 == k % 2) //窗口长度为奇
		median[0] = *littleSide.begin();
	else //窗口长度为偶
		median[0] = (*bigSide.begin()+ *littleSide.begin())/2.0;

	//从第二个滑动窗口开始遍历。 [currentRight - k + 1,currentRight] 为当前滑动窗
	for (int currentRight = k; currentRight < n; currentRight++)
	{
		//新加入的元素位置在 currentRight ，新移出的元素位置在 currentRight - k ，上一窗口的中位数存储在 median[currentRight - k] ，当前窗口的中位数存储于 median[currentRight - k + 1]
		
		//加入新元素
		if(nums[currentRight]>= median[currentRight - k])
			bigSide.insert(nums[currentRight]);
		else
			littleSide.insert(nums[currentRight]);
		
		//移出旧元素
		if (nums[currentRight - k] > median[currentRight - k])
			bigSide.erase(bigSide.find(nums[currentRight - k]));
		else
			littleSide.erase(littleSide.find(nums[currentRight - k])); //细节：littleSide.erase(5) 移除 littleSide 中等于 5 的全部元素， littleSide.erase(littleSide.find(5)) 移除 littleSide 中等于 5 的一个元素。
		
		//调整两侧的 multiset
		if (bigSide.size() > littleSide.size())
		{
			littleSide.insert(littleSide.begin(), *bigSide.begin());
			bigSide.erase(bigSide.begin());
		}
		else
			if (bigSide.size() < littleSide.size() - 1)
			{
				bigSide.insert(bigSide.begin(), *littleSide.begin());
				littleSide.erase(littleSide.begin());
			}

		//计算当前窗口的中位数
		if (1 == k % 2) //窗口长度为奇
			median[currentRight - k + 1] = *littleSide.begin();
		else //窗口长度为偶
			median[currentRight - k + 1] = (*bigSide.begin() + *littleSide.begin()) / 2.0;
	}
	return median;
}



int main480()
{
	vector<int> test = { 1, 3, -1, -3, 5, 3, 6, 7 };
	//vector<int> test = { 1, 2, 3, 4, 2, 3, 1, 4, 2 };
	//vector<int> test = { 1, 2};
	vector<double> ret = medianSlidingWindow(test,3);
	cout << "main：ret = " <<endl;
	for (vector<double>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}