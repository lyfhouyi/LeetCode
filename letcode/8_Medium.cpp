#include<iostream>
#include<string>

using namespace std;

//请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C / C++ 中的 atoi 函数）。
//
//函数 myAtoi(string s) 的算法如下：
//
//读入字符串并丢弃无用的前导空格
//检查第一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
//将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
//返回整数作为最终结果。
//
//
//注意：
//
//	本题中的空白字符只包括空格字符 ' ' 。
//	除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
//
//
//提示：
//
//	0 <= s.length <= 200
//	s 由英文字母（大写和小写）、数字（0 - 9）、' '、'+'、'-' 和 '.' 组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/string-to-integer-atoi
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历字符串。
int myAtoi(string s)
{
	string::iterator it = s.begin();
	bool positive = true;

	//丢弃前导空格
	while (it != s.end() && *it == ' ')
		it++;

	//判断正负，true ：正，false ：负
	if ((it != s.end()) && (*it == '-' || *it == '+'))
	{
		if (*it == '-')
			positive = false;
		it++;
	}

	//读入数字
	long long ret = 0;
	bool valid = false;
	while (it != s.end())
	{
		if (*it<'0' || *it>'9' || ret > 2147483648)
			break;
		ret = ret * 10 + *it - '0';
		it++;
	}

	cout << "myAtoi：" << ret << endl;
	//判定返回值
	if (positive) //正
	{
		if (ret > 2147483647)
			return 2147483647;
		return ret;
	}
	else //负
	{
		if (ret > 2147483648)
			return -2147483647 - 1;
		return -ret;
	}
}


int main8()
{
	//string test = "+4193 with words";
	//string test = "-91283472332";
	//string test = "words and 987";
	//string test = "     -42";
	//string test = "42";
	string test = "20000000000000000000";
	int ret = myAtoi(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}