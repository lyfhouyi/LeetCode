#include<iostream>
#include<string>
#include<vector>

using namespace std;

//给你两个长度相同的字符串，s 和 t。
//
//将 s 中的第 i 个字符变到 t 中的第 i 个字符需要  | s[i] - t[i] | 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。
//
//用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。
//
//如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化（使对应相等）的最大（子串）长度。
//
//如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。
//
//
//提示：
//
//	1 <= s.length, t.length <= 10 ^ 5
//	0 <= maxCost <= 10 ^ 6
//	s 和 t 都只含小写英文字母。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/get-equal-substrings-within-budget
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针构造滑动窗。首先构造“转化花费数组”；随后利用滑动窗在“转化花费数组”上的移动计算可以转化最多的窗口长度；该最大窗口长度即为返回值。
//int equalSubstring(string s, string t, int maxCost) 
//{
//	int n = s.size();
//	vector<int> costArray(n);
//
//	//构造“转化花费数组”
//	for (int i = 0; i < n; i++)
//	{
//		costArray[i] = abs(s[i] - t[i]);
//	}
//
//	int maxLength = 0;
//	int currentLength;
//	int indexRight = 0;
//	int indexLeft = 0;
//	int currentSum = 0;
//
//	//在“转化花费数组”上移动滑动窗，计算满足题意的窗口长度的最大值。本题实际求的是在预算允许范围内，转化后满足 s 的子串与相应 t 的子串相等的最大子串长度。
//	while (indexRight < n)
//	{
//		currentSum += costArray[indexRight];
//		while (currentSum > maxCost)
//		{
//			currentSum-= costArray[indexLeft];
//			indexLeft++;
//		}
//		currentLength = indexRight - indexLeft + 1;
//		maxLength = maxLength > currentLength ? maxLength : currentLength;
//		indexRight++;
//	}
//
//	return maxLength;
//}


//双指针构造滑动窗。优化版，无需构造“转化花费数组”。
int equalSubstring(string s, string t, int maxCost)
{
	int n = s.size();
	int maxLength = 0;
	int currentLength;
	int indexRight = 0;
	int indexLeft = 0;
	int currentSum = 0;

	//移动滑动窗，计算满足题意的窗口长度的最大值。本题实际求的是在预算允许范围内，转化后满足 s 的子串与相应 t 的子串相等的最大子串长度。
	while (indexRight < n)
	{
		currentSum += abs(s[indexRight] - t[indexRight]);
		while (currentSum > maxCost)
		{
			currentSum -= abs(s[indexLeft] - t[indexLeft]);
			indexLeft++;
		}
		currentLength = indexRight - indexLeft + 1;
		maxLength = maxLength > currentLength ? maxLength : currentLength;
		indexRight++;
	}
	return maxLength;
}


int main1208()
{
	string s = "abcd";
	string t = "cdef";
	int ret = equalSubstring(s, t, 3);
	cout << "main：ret = " << ret << endl;
	return 0;
}