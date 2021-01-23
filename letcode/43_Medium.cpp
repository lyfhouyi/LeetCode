#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//
//说明：
//
//	num1 和 num2 的长度小于110。
//	num1 和 num2 只包含数字 0 - 9。
//	num1 和 num2 均不以零开头，除非是数字 0 本身。
//	不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/multiply-strings
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//提取字符串 num 的第 n 低位
int getBit(int n, string& num)
{
	int m = num.length();
	if (n > num.length())
		return 0;
	return num[m - n] - 48;
}


//反向遍历字符串。第 n 位 = Σ(i=1,2,...,n) 第二串的第 i 低位 × 第二串的第 (n - i + 1) 低位 + 第 n - 1 位的进位；n 最大等于两串长度之和。
string multiply(string num1, string num2)
{
	int carryBit = 0;
	string ret;
	int tmp;
	int carrayBit = 0;
	int n = num1.length() + num2.length();

	//计算返回字符串的第 i 低位
	for (int i = 1; i <= n; i++)
	{
		tmp = 0;
		for (int j = 1; j <= i; j++)
			tmp += getBit(j, num2)*getBit(i - j + 1, num1);
		tmp += carryBit;
		ret.push_back(48 + tmp % 10);
		carryBit = tmp / 10;
	}

	//清空尾部的 0
	while (48 == ret[ret.length() - 1] && ret.length() != 1)
		ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}

int main43()
{
	string num1 = "123";
	string num2 = "0";
	string ret = multiply(num1, num2);
	cout << "main：ret = " << ret << endl;
	return 0;
}