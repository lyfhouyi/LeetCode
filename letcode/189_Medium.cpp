#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//
//说明 :
//
//	尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//	要求使用空间复杂度为 O(1) 的 原地 算法。


//迭代。每次循环将数组整体右移 1 个位置，一共右移 k 次。
//算法正确，时间超时。时间复杂度 O(k*n)，其中k = k % size，时间复杂度 O(1)。
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	if (size <= 1)
//		return;
//	k = k % size;
//	int tmp;
//	int i;
//	while (k > 0)
//	{
//		tmp = nums[size - 1];
//		for (i = size - 2; i >= 0; i--)
//			nums[i + 1] = nums[i];
//		nums[0] = tmp;
//		k--;
//	}
//}


//迭代。瞄准起始时数组尾部的 k 个元素，每次循环将其左移 1 个位置，一共左移 n-k 次。
//算法正确，时间超时。时间复杂度 O(k*(n-k))，其中k = k % size，时间复杂度 O(1)。
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	if (size < 1)
//		return;
//	k = k % size;
//	int tmp;
//	int i;
//	vector<int>::iterator it = nums.end();
//	while (it != nums.begin() + k)
//	{
//		it = it - k;
//		tmp = *(it - 1);
//		for (i = 0; i < k; i++)
//		{
//			*(it - 1) = *it;
//			it++;
//		}
//		it--;
//		*it = tmp;
//	}
//}


//迭代。瞄准起始时数组尾部的 k 个元素作为“目标段”，每次循环将其与左侧的 k 个元素交换位置，一共循环 (n-1)/k 次。
//算法正确，时间超时。时间复杂度 O(n)，时间复杂度 O(1)。
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	if (size <= 1)
//		return;
//	k = k % size;
//	if (0 == k)
//		return;
//	int i;
//	int j;
//	int sour=size+k;
//	int dist = 0;
//
//	//前 (n-1)/k-1 次正常循环
//	for (i = 0; i < (size - 1) / k-1;i++)
//	{
//		sour -= 2*k;
//		dist = sour - k;
//		for (j = 0; j < k; j++)
//		{
//			swap(nums[sour], nums[dist]);
//			sour++;
//			dist = sour - k;
//		}
//	}
//	//最后一次循环只需在 [begin,目标段尾] 间循环
//	sour -= 2*k;
//	size = sour + k;
//	int tmp;
//	vector<int>::iterator it = nums.begin()+size;
//	while (it != nums.begin() + k)
//	{
//		it = it - k;
//		tmp = *(it - 1);
//		for (i = 0; i < k; i++)
//		{
//			*(it - 1) = *it;
//			it++;
//		}
//		it--;
//		*it = tmp;
//	}
//}


//使用额外的空间
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	k = k % size;
//	for (int i = 0; i < size - k; i++)
//		nums.push_back(nums[i]);
//	nums.assign(nums.begin() + size - k, nums.end());
//}


//数组翻转
void rotate(vector<int>& nums, int k)
{
	k = k % nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

int main()
{
	vector<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << "  ";
	cout << endl;
	rotate(test, 0);
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}