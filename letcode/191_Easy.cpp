#include<iostream>

using namespace std;

//编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
//
//
//提示：
//
//	请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
//	在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 - 3。
//
//
//提示：
//
//	输入必须是长度为 32 的 二进制串 。
//
//
//进阶：
//
//	如果多次调用这个函数，你将如何优化你的算法？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-1-bits
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：逐个比较末位是否为 1 。
int hammingWeight(uint32_t n)
{
	int cnt = 0;
	while (n != 0)
	{
		cnt += (n & 1);
		n >>= 1;
	}
	return cnt;
}


//解法二：直接检查 n 的最后一个 1 位。
int hammingWeight(uint32_t n)
{
	int cnt = 0;
	while (n != 0)
	{
		cnt++;
		n = n & (n - 1);
	}
	return cnt;
}


int main191()
{
	uint32_t test = 5;
	int ret = hammingWeight(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}