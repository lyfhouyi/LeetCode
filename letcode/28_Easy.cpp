﻿#include<iostream>
#include<string>

using namespace std;

//实现 strStr() 函数。
//
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  - 1 。
//
//
//说明：
//
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
//
//
//提示：
//
//	0 <= haystack.length, needle.length <= 5 * 10^4
//	haystack 和 needle 仅由小写英文字符组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-strstr
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力遍历。在 haystack 中逐位置取出与 needle 等长的子串，比较二者是否相等。
int strStr(string haystack, string needle)
{
	int n = haystack.length();
	int m = needle.length();
	if (m == 0)
		return 0;
	for (int i = 0; i < n; i++)
	{
		if (haystack.substr(i, m) == needle)
			return i;
	}
	return -1;
}


int main28()
{
	string haystack = "";
	string needle = "";
	int ret = strStr(haystack, needle);
	cout << "main：ret = " << ret << endl;
	return 0;
}