#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//提示：
//
//	0 <= s.length <= 5 * 104
//	s 由英文字母、数字、符号和空格组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法二的时间复杂度为 O(n) ，解法一的时间复杂度为 O(n^2) ，以空间换时间

//解法一：依次判断无重复字符的字串长度，通过 find() 判断字符是否有重复
//int lengthOfLongestSubstring(string s)
//{
//	if (s.length() <= 1)
//		return s.length();
//	int cnt = 1;
//	int maxLength = 0;
//	string::iterator it1 = s.begin();
//	string::iterator it2 = s.begin() + 1;
//	string::iterator itSame;
//	while (it2 != s.end())
//	{
//		if (it2 == (itSame = find(it1, it2, *it2)))
//			cnt++;
//		else
//		{
//			it1 = itSame+1;
//			cnt = it2 - itSame;
//		}
//		maxLength = cnt > maxLength ? cnt : maxLength;
//		it2++;
//	}
//	return maxLength;
//}






//解法二：依次判断无重复字符的字串长度，通过 flag 数组中各字符的标志位判断字符是否有重复（节省了 find() 的时间开销，以空间换时间）
int lengthOfLongestSubstring(string s)
{
	int flag[128]; //存储当前判断区间中，各字符是否已出现及出现的位置，即 flag 数组
	for (int i = 0; i < 128; i++)
		flag[i] = -1;

	int indexSame = -1;
	int cnt = 0;
	int maxLength = 0;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		if (-1 == (indexSame = flag[*it]))
			cnt++;
		else
		{
			for (int i = 0; i < 128; i++)
			{
				if(flag[i]<= indexSame)
					flag[i] = -1;
			}
			cnt = it- s.begin() - indexSame;
		}
		flag[*it] = it - s.begin();
		maxLength = cnt > maxLength ? cnt : maxLength;
		it++;
	}
	return maxLength;
}





int main3()
{
	string test = "asdfasd";
	int ret = lengthOfLongestSubstring(test);
	cout << "main：ret=" << ret << endl;
	return 0;
}