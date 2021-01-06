#include<iostream>

using namespace std;


//斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
//
//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//给你 n ，请计算 F(n) 。
//
//提示：
//
//	0 <= n <= 30
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/fibonacci-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//迭代。不断求出下一个 F(n)
int fib(int n)
{
	if (2 == n || 1 == n)
		return 1;
	int f1 = 0;
	int f2 = 1;
	int fi = 0;
	int i = 2;
	while (i <= n)
	{
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
		i++;
	}
	return fi;
}


int main509()
{
	int ret = fib(30);
	cout << "main：ret = " << ret << endl;
	return 0;
}