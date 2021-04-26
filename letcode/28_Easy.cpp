#include<iostream>
#include<string>
#include<vector>

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


//解法一：暴力遍历。在 haystack 中逐位置取出与 needle 等长的子串，比较二者是否相等。
//int strStr(string haystack, string needle)
//{
//	int n = haystack.length();
//	int m = needle.length();
//	if (m == 0)
//		return 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (haystack.substr(i, m) == needle)
//			return i;
//	}
//	return -1;
//}


//解法二：KMP 算法。首先计算模式串 needle 的部分匹配表；随后使用 next 数组辅助匹配。
int strStr(string haystack, string needle)
{
	//计算模式串 needle 的部分匹配表，next[i] 表示子串 needle[0:i] 的最长相等前后缀长度
	int m = needle.length();
	vector<int> next(m, 0);
	int j = 0; //每次迭代计算 next[i] 时，j 的初始值均表示子串 needle[0:i - 1] 的最长相等前后缀长度，即初始状态 j == next[i - 1]
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && needle[i] != needle[j])
		{
			j = next[j - 1];
		}
		if (needle[i] == needle[j])
			j++;
		next[i] = j;
	}

	if (m == 0)
		return 0;
	//匹配模式串
	int n = haystack.length();
	int i = 0;
	j = 0;
	while (i < n)
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (j == m) //匹配完成，找到模式串
				return i - m;
		}
		else
		{
			if (j > 0)
				j = next[j - 1];
			else
				i++;
		}
	}
	return -1;
}


int main28()
{
	string haystack = "aabaabaaf";
	string needle = "aabaaf";
	int ret = strStr(haystack, needle);
	cout << "main：ret = " << ret << endl;
	return 0;
}