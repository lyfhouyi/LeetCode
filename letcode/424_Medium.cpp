#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
//
//注意：字符串长度 和 k 不会超过 104。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-repeating-character-replacement
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//使用双指针构造滑动窗口。计算窗口内需要更换的字母数量，若该数量大于 k 则将窗口左端右移一位，否则将窗口右端右移一位；需要更换的字母数量 = 窗口内字母总数 - 窗口内最大的重复字母数 。
int characterReplacement(string s, int k)
{
	int n = s.size();
	int windowRight = 0;
	int windowLeft = 0;
	int maxCount;
	int currentLength;
	int maxLength = 0;
	vector<int> charBucket(26, 0);
	
	//以 [windowLeft,windowRight] 作为滑动窗口
	while (windowRight < n)
	{
		charBucket[s[windowRight] - 'A']++;
		currentLength = windowRight - windowLeft + 1;
		maxCount = *max_element(charBucket.begin(), charBucket.end());
		while (currentLength - maxCount > k)
		{
			charBucket[s[windowLeft] - 'A']--;
			windowLeft++;
			currentLength = windowRight - windowLeft + 1;
			maxCount = *max_element(charBucket.begin(), charBucket.end());
		}
		maxLength = maxLength > currentLength ? maxLength : currentLength;
		windowRight++;
	}
	return maxLength;
}


int main424()
{
	//string test = "AABABBA";
	//string test = "ABAB";
	//string test = "EEEEAEEMNEEEEEQU";
	string test = "";
	int ret = characterReplacement(test, 0);
	cout << "main：ret = " << ret << endl;
	return 0;
}