#include<iostream>
#include<vector>

using namespace std;

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//说明：
//
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/single-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：位运算：按位异或。1.异或运算满足交换律和结合律；2.任何数与其自身异或运算结果的为 0；3.任何数与 0 的异或结果均为其本身。
int singleNumber(vector<int>& nums)
{
	int ret = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++)
		ret ^= nums[i];
	return ret;
}

//解法二：位运算：按位求余。答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 2 的余数。
//int singleNumber(vector<int>& nums)
//{
//	int ret = 0;
//	int n = nums.size();
//	int bitSum;
//	for (int i = 0; i < 32; i++)
//	{
//		bitSum = 0;
//		for (int j = 0; j < n; j++)
//		{
//			bitSum += (nums[j] >> i) & 1;
//		}
//		ret += ((bitSum % 2) & 1) << i;
//	}
//	return ret;
//}


int main()
{
	vector<int> test = { 4,1,2,1,2 };
	int ret = singleNumber(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}