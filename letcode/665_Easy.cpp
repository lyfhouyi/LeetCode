#include<iostream>
#include<vector>

using namespace std;


//给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
//
//我们是这样定义一个非递减数列的： 对于数组中所有的 i(0 <= i <= n - 2)，总满足 nums[i] <= nums[i + 1]。
//
//
//说明：
//
//	1 <= n <= 10 ^ 4
//	- 10 ^ 5 <= nums[i] <= 10 ^ 5
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/non-decreasing-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力枚举。使用三个指针为一个检查组，滑动考察，步幅 1 个元素，同时检查 3 个元素；特殊情况下，需检查第四个元素。边检查边矫正。
bool checkPossibility(vector<int>& nums)
{
	if (nums.size() <= 2)
		return true;

	bool changed = false; //是否已矫正了一个元素

	vector<int>::iterator it1 = nums.begin();
	vector<int>::iterator it2 = nums.begin() + 1;
	vector<int>::iterator it3 = nums.begin() + 2;
	//it1、it2、it3 为一个检查组，滑动考察，步幅 1 个元素，同时检查 3 个元素;边检查边矫正；当 it3 离开时，数组已矫正为非递减数列
	while (it3 != nums.end())
	{
		if (it1 == nums.begin())
		{
			//第一轮
			if ((*it3 < *it1) && (*it3 < *it2))
			{
				if (*it1 > *it2)
				{
					// cout << "无法矫正" << endl;
					return false;
				}
				if ((it3 == nums.end() - 1) || (*(it3 + 1) >= *it2))
				{
					// cout << "矫正元素 case1 ：index = " << it3 - nums.begin() << endl;
					changed = true;
					*it3 = *it2;
				}
				else
				{
					// cout << "无法矫正" << endl;
					return false;
				}
			}
			else
			{
				if (*it3 < *it2)
				{
					// cout << "矫正元素 case2 ：index = " << it2 - nums.begin() << endl;
					changed = true;
					*it2 = *it3;
				}
				else
				{
					if (*it1 > *it2)
					{
						// cout << "矫正元素 case3 ：index = " << it1 - nums.begin() << endl;
						changed = true;
						*it1 = *it2;
					}
				}
			}
		}
		else
		{
			// *it1 <= *it2 必然成立
			if (*it3 < *it2)
			{
				if (changed)
				{
					// cout << "需要更多的矫正" << endl;
					return false;
				}
				else
				{
					if (*it3 >= *it1)
					{
						// cout << "矫正元素 case1 ：index = " << it2 - nums.begin() << endl;
						changed = true;
						*it2 = *it3;
					}
					else
					{
						if ((it3 == nums.end() - 1) || (*(it3 + 1) >= *it2))
						{
							// cout << "矫正元素 case1 ：index = " << it3 - nums.begin() << endl;
							changed = true;
							*it3 = *it2;
						}
						else
						{
							// cout << "无法矫正" << endl;
							return false;
						}
					}
				}
			}
		}
		it1++;
		it2++;
		it3++;
	}
	return true;
}


int main665()
{
	vector<int> test = { 4,2,3 };
	bool ret = checkPossibility(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}