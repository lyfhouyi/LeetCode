#include<iostream>
#include<vector>
#include<string>
#include<deque>

using namespace std;

//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//
//
//提示：
//
//	1 <= S.length <= 20000
//	S 仅由小写英文字母组成。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//找到字符串中的全部回文子串并删除。首先使用二维动态规划找到全部的回文子串；随后使用双指针正序遍历原始字符串，贪心地找到最长的回文子串并删除。
string removePlalindrome(string& s, bool& isRemoved)
{
	//计算 dp 数组，基于二维动态规划。dp[i][j] 表示区间 [i,j] 是否为回文子串
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, true));
	for (int j = 1; j < n; j++) //列优先遍历
	{
		for (int i = j - 1; i >= 0; i--)
		{
			dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
		}
	}
	string ret;
	int i = 0;
	int maxJ;
	isRemoved = false;
	while (i < n)
	{
		maxJ = i;
		for (int j = i + 1; j < n; j++)
		{
			if (dp[i][j] && (j - i) % 2) //只有偶数长的回文子串才可以被删除
				maxJ = maxJ > j ? maxJ : j;
		}
		if (maxJ == i)
			ret.push_back(s[i]); //未找到以 s[i] 为起始的偶数长的回文子串
		else
			isRemoved = true; //找到以 s[i] 为起始的偶数长的回文子串
		i = maxJ + 1;
	}
	return ret;
}


//不断消除字符串中的回文子串，直到字符串中无回文子串。
//string removeDuplicates(string S)
//{
//	bool isRemoved;
//	string ret(S);
//	do
//	{
//		ret = removePlalindrome(ret, isRemoved);
//	} while (isRemoved);
//	return ret;
//}


//双端队列。使用双端队列模拟栈储存尚未被删除的字符。单指针遍历字符串，若当前元素与队尾元素相同，则将队尾元素弹出，否则将当前元素压入队列；遍历完毕后，队列中的元素即为重复项删除操作后的所求字符串，顺序为从队首至队尾。
//string removeDuplicates(string S)
//{
//	int n = S.length();
//	deque<char> charQueue;
//	for (int i = 0; i < n; i++)
//	{
//		if (!charQueue.empty() && S[i] == charQueue.back())
//			charQueue.pop_back();
//		else
//			charQueue.push_back(S[i]);
//	}
//	string ret(charQueue.begin(), charQueue.end());
//	return ret;
//}


//优化版。使用字符串模拟栈储存尚未被删除的字符。单指针遍历字符串，若当前元素与返回串串尾元素相同，则将返回串串尾元素弹出，否则将当前元素压入返回串。
string removeDuplicates(string S)
{
	int n = S.length();
	string ret;
	for (int i = 0; i < n; i++)
	{
		if (!ret.empty() && S[i] == ret.back())
			ret.pop_back();
		else
			ret.push_back(S[i]);
	}
	return ret;
}


int main1047()
{
	string test = "aababaab";
	//string test = "x";
	//string test = "xcadbbdcabbaca";
	string ret = removeDuplicates(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}