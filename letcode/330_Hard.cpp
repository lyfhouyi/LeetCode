#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/patching-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


unsigned lastI = 0;

int findPatching(vector<int>& vec)
{
	unsigned i = 0;
	unsigned size = vec.size();

	for (i = lastI; i < size; i++)
	{
		if (vec[i] != i)
		{
			lastI = i;
			return i;
		}
	}
	lastI = i;
	return i;
}



//贪心算法：不断扩充可达域直到可达域完全覆盖[1, n]。
//思路：不可达域中的最小的元素值为需填充的值，填充该值是必要且充分的（充分指效率最高），使用 findPatching 找到不可达域中的最小元素值
//算法正确，时间超时。官方解法的数学模型抽象地更好，思路更加清晰。
//1.0 版本无法应对 n=2147483647 的情况，因为“目标数组”过大，1.1版本不使用目标数组，只是用“和数组”，且通过 isBig 变量及时判断出“和数组”满覆盖的情况，避免了无意义的剩余计算，使算法计算时间大幅缩减。
//int minPatches(vector<int>& nums, int n)
//{
//	unsigned un = n;
//	vector<int>sumArray(1); //和数组，和数组为补充后元素的可达域
//	unsigned sumArray_size = 0;
//	int sum = 0;
//	int patching_new = 0;
//	vector<long>::iterator tmp;
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		sumArray_size = sumArray.size();
//		for (unsigned i = 0; i < sumArray_size; i++)
//		{
//			sum = sumArray[i] + *it;
//			if (sumArray.end() == find(sumArray.begin(), sumArray.end(), sum))
//			{
//				sumArray.push_back(sum); //更新和数组
//			}
//		}
//	}
//	//逐项添加修补数组
//	int c = 0;
//	bool isBig = false; // n 是不是太大了？
//	while (true)
//	{
//		sort(sumArray.begin() + lastI, sumArray.end());
//		patching_new = findPatching(sumArray);
//		if (patching_new >= un + 1)
//			break;
//		c++;
//		sumArray_size = sumArray.size();
//		cout << "补充元素：" << patching_new << " ： 累计补充个数：" << c << " : " << " ： 和数组规模：" << sumArray_size << " ： 和数组最大元素：" << sumArray[sumArray_size - 1] << endl;
//		if ((patching_new == sumArray_size))
//		{
//			isBig = true; //当和数组为“最大可达”时，说明 n 太大了，此时每次循环需补充的数为：2×(和数组中最大的元素+1)，下次循环中和数组规模翻倍
//			break;
//		}
//		for (unsigned i = 0; i < sumArray_size; i++)
//		{
//			sum = sumArray[i] + patching_new;
//			if (sumArray.end() == find(sumArray.begin(), sumArray.end(), sum))
//			{
//				sumArray.push_back(sum); //更新和数组
//			}
//		}
//	}
//	if (!isBig)
//		return c;
//	while ((sumArray_size < un + 1))
//	{
//		c++;
//		sumArray_size *= 2;
//	}
//	return c - 1;
//}



//贪心算法。不断扩充可达域直到可达域完全覆盖[1, n]。逐个补充最有效率的元素
int minPatches(vector<int>& nums, int n)
{
	unsigned un = n;
	int c = 0; //补充的元素个数
	unsigned x = 1; //任意时刻， x 为最优待补充的元素，x-1 为可达域上限
	vector<int>::iterator it = nums.begin();
	while (x - 1 < n)
	{
		if (it != nums.end() && *it <= x)
		{
			x += *it; //补充元素 *it
			it++;
			continue;
		}
		x *= 2; //补充元素 x
		c++;
		// cout << "补充元素：" << x/2 << " ， 累计补充个数：" << c <<  " ， 可达域：[1," << x-1 << "]"<< endl;
	}
	return c;
}



int main330()
{
	vector<int> test = { 1,5,10 };
	int ret = minPatches(test,20 );
	cout << "main：ret = " << ret << endl;
	return 0;
}