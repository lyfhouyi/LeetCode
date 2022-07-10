#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

//有台奇怪的打印机有以下两个特殊要求：
//
//	打印机每次只能打印同一个字符序列。
//	每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
//给定一个只包含小写英文字母的字符串，你的任务是计算这个打印机打印它需要的最少次数。
//
//
//提示 : 输入字符串的长度不会超过 100。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/strange-printer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//错误的解法：栈。使用栈存储等待打印的字母块，出栈的字母块被打印成为较上层的字母块；最终先打印的字母块在上层，后打印的字母块在下层，上层的字母块会遮蔽下层的字母块；使用数组 inStackVec 标记某字母块是否在栈中。正序遍历原始字符串，若当前字母块未在栈中，则将当前字母块压栈；否则持续弹栈直到已压栈的当前字母块（已压栈的当前字母块不出栈），出栈的字母块全部打印，成为上层的字母块（越早出栈越靠上层）；遍历结束后，打印栈中剩余的字母块，越早出栈越靠上层。
//int strangePrinter(string s)
//{
//	vector<bool> inStackVec(26, false);
//	stack<char> charStack;
//	char lastChar = '\0';
//	int printCnt = 0;
//	for (string::iterator it = s.begin(); it != s.end(); it++)
//	{
//		if (*it == lastChar)
//			continue;
//		//遍历至新的字母块
//		lastChar = *it;
//		if (inStackVec[*it - 'a'] == false) //当前字母块未在栈中
//		{
//			charStack.push(*it);
//			inStackVec[*it - 'a'] = true;
//		}
//		else //当前字母块已在栈中
//		{
//			while (charStack.top() != *it) //持续弹出可以打印的字母块
//			{
//				inStackVec[charStack.top() - 'a'] = false;
//				charStack.pop();
//				printCnt++; //更新打印次数
//			}
//		}
//	}
//	while (!charStack.empty()) //打印栈中剩余的字母块（越靠近栈底，越处于下层）
//	{
//		printCnt++;
//		charStack.pop();
//	}
//	return printCnt;
//}


//二维动态规划。维护一个二维数组：dp[i][j] 表示打印 [i,j] 区间上的字符串所需的最少打印次数。
//状态转移函数：dp[i][j] = min(dp[i][k - 1] + dp[k + 1][j], 1 + dp[i + 1][j]) ，其中 k ∈(i,j] 且 s[k] == s[i] 。
//边界条件：dp[:][:] = 0 。
//最优解：dp[0][n - 1] 。
int strangePrinter(string s)
{
	int n = s.length();
	if (n == 0)
		return 0;
	vector<vector<int>> dp(n + 1, vector<int>(n, 0));

	//右下斜行优先遍历计算 dp 数组
	for (int len = 1; len <= n; len++)
	{
		for (int i = 0; i + len - 1 < n; i++)
		{
			int j = i + len - 1;

			//当前计算区间为 [i,j]
			dp[i][j] = 1 + dp[i + 1][j];
			for (int k = i + 1; k <= j; k++)
			{
				if (s[k] == s[i])
					dp[i][j] = dp[i][k - 1] + dp[k + 1][j] < dp[i][j] ? dp[i][k - 1] + dp[k + 1][j] : dp[i][j];
			}
		}
	}
	return dp[0][n - 1];
}


int main664()
{
	//string test = "aabbcdabcbd";
	//string test = "aabbaa";
	string test = "tbgtgb";
	//string test="aabbcbbaadeda";
	//string test = "";
	//string test = "xaxaxbbxa";
	int ret = strangePrinter(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}