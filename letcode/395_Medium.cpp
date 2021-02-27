#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
//
//
//提示：
//
//	1 <= s.length <= 10^4
//	s 仅由小写英文字母组成
//	1 <= k <= 10^5
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//计算字符串 s 在区间 [begin,end) 上的最长子串，要求该子串中的每一字符出现次数都不少于 k 。
//递归。首先遍历区间一次，找到所有的“坏字符”，进而划分出若干各候选区间；随后，对每一个候选区间，递归调用 longestSubstringSlice 求各候选区间的满足要求的子串长度的最大值。递归基：若当前区间满足要求，返回当前区间长度。
int longestSubstringSlice(string& s, int k, int begin, int end)
{
	vector<int> charCntBucket(26); //统计各字符出现的次数
	for (int i = begin; i < end; i++)
		charCntBucket[s[i] - 'a']++;

	//递归基：若当前区间满足要求，返回当前区间长度。
	bool isValid = true;
	for (int i = 0; i < 26; i++)
	{
		if (charCntBucket[i] > 0 && charCntBucket[i] < k)
			isValid = false;
	}
	if (isValid)
		return end - begin;

	//计算各候选区间的满足要求的子串长度的最大值
	int maxLength = 0;
	int subBegin = -1;
	for (int i = begin; i < end; i++)
	{
		if (charCntBucket[s[i] - 'a'] >= k && -1 == subBegin) //找到了候选区间的起点
		{
			subBegin = i;
		}
		else
		{
			if (charCntBucket[s[i] - 'a'] < k && -1 != subBegin) //找到了候选区间的终点
			{
				if (i - subBegin >= k)
				{
					int tmp = longestSubstringSlice(s, k, subBegin, i);
					maxLength = maxLength > tmp ? maxLength : tmp;
				}
				subBegin = -1;
			}
		}
	}
	if (subBegin != -1 && end - subBegin >= k) //处理最后一个候选区间
	{
		int tmp = longestSubstringSlice(s, k, subBegin, end);
		maxLength = maxLength > tmp ? maxLength : tmp;
	}
	return maxLength;
}


//分而治之。递归实现。
int longestSubstring(string s, int k)
{
	return longestSubstringSlice(s, k, 0, s.size());
}


int main395()
{
	string s = "bbaaacbd";
	int ret = longestSubstring(s, 3);
	cout << "main：ret = " << ret << endl;
	return 0;
}