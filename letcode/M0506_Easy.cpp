#include<iostream>

using namespace std;

//整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
//
//
//提示 :
//
//	1.A，B范围在[-2147483648, 2147483647]之间
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/convert-integer-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：迭代。迭代地将 A、B 右移一位，并判断末位是否相同。
//int convertInteger(int A, int B)
//{
//	int ret = 0;
//	unsigned uA = A;
//	unsigned uB = B;
//	while (uA != 0 || uB != 0) //遍历末位
//	{
//		ret += ((uA & 1) ^ (uB & 1));
//		uA >>= 1;
//		uB >>= 1;
//	}
//	return ret;
//}


//解法二：迭代。先计算 A 与 B 的异或值，则该异或值中 1 的个数即为所求。
int convertInteger(int A, int B)
{
	unsigned eor = A^B;
	int ret = 0;
	while (eor != 0) //遍历最后一个 1 位
	{
		ret++;
		eor &= eor - 1;
	}
	return ret;
}


int mainM0506()
{
	int ret = convertInteger(826966453, -729934991);
	cout << "main：ret = " << ret << endl;
	return 0;
}