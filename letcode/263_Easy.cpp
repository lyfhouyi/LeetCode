#include<iostream>

using namespace std;

//给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
//
//丑数 就是只包含质因数 2、3 和 / 或 5 的正整数。
//
//
//提示：
//
//	- 2^31 <= n <= 2^31 - 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ugly-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//迭代。将 n 不断地除以 2、3、5 质因数，检查剩余的质因数。
bool isUgly(int n)
{
	if (n == 0)
		return false;
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else if (n % 3 == 0)
			n /= 3;
		else if (n % 5 == 0)
			n /= 5;
		else
			return false;
	}
	return true;
}


int main263()
{
	bool ret = isUgly(0);
	cout << "main：ret = " << ret << endl;
	return 0;
}