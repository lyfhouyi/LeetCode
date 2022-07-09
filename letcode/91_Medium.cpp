#include <iostream>
#include <vector>
#include <string>

using namespace std;

//一条包含字母 A - Z 的消息通过以下映射进行了 编码 ：
//
//	'A' -> 1
//	'B' -> 2
//	...
//	'Z' -> 26
//要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//
//	"AAJF" ，将消息分组为(1 1 10 6)
//	"KJF" ，将消息分组为(11 10 6)
//注意，消息不能分组为 (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
//
//给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
//
//题目数据保证答案肯定是一个 32 位 的整数。
//
//
//提示：
//
//	1 <= s.length <= 100
//	s 只包含数字，并且可能包含前导零。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/decode-ways
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//回溯算法。根据当前待解码串 encodedS 的前两个字符的情况判断下一步可以解码哪个字符。回溯于 encodedS 下一步解码的字符是 1-9 或 10-26 ；递归基：待解码串为空时，即找到一个解码方案。
void decode(string encodedS, int &currentCnt)
{
	if (encodedS.length() == 0)
	{
		currentCnt++;
		return;
	}
	if (encodedS[0] == '0')
		return;
	decode(encodedS.substr(1), currentCnt);
	int tmp = stoi(encodedS.substr(0, 2));
	if (tmp >= 10 && tmp <= 26)
		decode(encodedS.substr(2), currentCnt);
}

//递归。递归调用 decode() 函数，解码下一个的字符。
//算法正确，但时间超时。
// int numDecodings(string s)
//{
//	int ret = 0;
//	decode(s, ret);
//	return ret;
//}

//一维动态规划。维护一个一维数组：dp[i] 表示 [0,i] 区间的原字符串的解码方案数。
//状态转移函数：dp[i] = ([i-1,i] 区间的原字符串可以解码 ? dp[i - 2] : 0) + ([i,i] 区间的原字符串可以解码 ? dp[i - 1] : 0) 。
//边界条件：dp[0] = [0,0] 区间的原字符串可以解码 ? 1 : 0 ；dp[1] = ([0,1] 区间的原字符串可以解码 ? 1 : 0) + ([1,1] 区间的原字符串可以解码 ? dp[0] : 0) 。
//最优解：dp[n - 1] 。
int numDecodings(string s)
{
	int n = s.length();
	vector<int> dp(n, s[0] != '0');
	int tmp;

	//遍历计算 dp 数组
	for (int i = 1; i < n; i++)
	{
		tmp = stoi(s.substr(i - 1, 2));
		if (i == 1)
			dp[i] = (tmp >= 10 && tmp <= 26 ? 1 : 0) + (s[i] != '0' ? dp[0] : 0);
		else
			dp[i] = (tmp >= 10 && tmp <= 26 ? dp[i - 2] : 0) + (s[i] != '0' ? dp[i - 1] : 0);
	}
	return dp[n - 1];
}

int main91()
{
	string test = "0";
	int ret = numDecodings(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}