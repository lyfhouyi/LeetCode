#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

//有效数字（按顺序）可以分成以下几个部分：
//
//	1.一个 小数 或者 整数
//	2.（可选）一个 'e' 或 'E' ，后面跟着一个 整数
//
//小数（按顺序）可以分成以下几个部分：
//
//	1.（可选）一个符号字符（'+' 或 '-'）
//	2.下述格式之一：
//		1.至少一位数字，后面跟着一个点 '.'
//		2.至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
//		3.一个点 '.' ，后面跟着至少一位数字
//
//整数（按顺序）可以分成以下几个部分：
//
//	1.（可选）一个符号字符（'+' 或 '-'）
//	2.至少一位数字
//
//
//提示：
//
//	1 <= s.length <= 20
//	s 仅含英文字母（大写和小写），数字（0 - 9），加号 '+' ，减号 '-' ，或者点 '.' 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/valid-number
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力解法，使用 strtof() 库函数。
bool isNumber(string s)
{
	char *pEnd;
	float f = strtof(s.c_str(), &pEnd);

	//处理特殊字符输入
	if (isnan(f))
		return false;
	if (isinf(f))
	{
		if (s[0] == '+' || s[0] == '-')
		{
			if ((s[1]<'0' || s[1]>'9') && (s[1] != '.'))
				return false;
		}
		else if ((s[0]<'0' || s[0]>'9') && (s[0] != '.'))
			return false;
	}

	if (*pEnd != '\0')
		return false;
	return true;
}


int main65()
{
	string test = "+Inf";
	bool ret = isNumber(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}

