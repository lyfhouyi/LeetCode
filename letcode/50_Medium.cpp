#include<iostream>

using namespace std;

//实现 pow(x, n) ，即计算 x 的 n 次幂函数
//
//说明:
//
//	-100.0 < x < 100.0
//	n 是 32 位有符号整数，其数值范围是[−231, 231 − 1] 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/powx-n
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//快速幂算法。时间复杂度 O(log n)
double myPow(double x, int n)
{
	if (0 == x)
		return 1;

	bool neg = false;
	long posN = n;
	if (posN < 0)
	{
		posN = -posN;
		neg = true;
	}
	double ret = 1;
	while (posN > 0)
	{
		if (1 == (posN & 1))
			ret *= x;
		x *= x;
		posN >>= 1;
	}
	ret = neg ? (1 / ret) : (ret);
	return ret;
}


int main50()
{
	double ret = myPow(1, -218);
	cout << "main：ret = " << ret << endl;
	return 0;
}