#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
//
//我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
//
//所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
//
//请你返回「表现良好时间段」的最大长度。
//
//
//提示：
//
//	1 <= hours.length <= 10000
//	0 <= hours[i] <= 16
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-well-performing-interval
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：二维动态规划。计算一个数组：dp[i][j] 表示子串[i, j] 上“劳累的天数”与“不劳累的天数”的差值。
//状态转移函数：j != i + 1 时，hours[j] 为“劳累的一天”时，dp[i][j] = dp[i][j - 1] + 1 ，hours[j] 为“不劳累的一天”时，dp[i][j] = dp[i][j - 1] - 1 。
//边界条件：dp[i][i] = (hours[i] 为“劳累的一天” ? 1 : 0) 。
//最优解：dp[:][:] 的最大值。
//使用滚动数组进行优化。
//int longestWPI(vector<int>& hours)
//{
//	int n = hours.size();
//	int maxLength=0;
//	int diff;
//	for (int i = 0; i < n; i++)
//	{
//		if (i != 0 && hours[i - 1] > 8)
//			continue;
//		diff =0;
//		for (int j = i; j < n; j++)
//		{
//			diff += (hours[j] > 8 ? 1 : -1);
//			if (diff > 0)
//				maxLength =( maxLength > (j - i + 1) ? maxLength : (j - i + 1));
//		}
//	}
//	return maxLength;
//}


//解法二：递减栈。使用前缀和数组 sumArray[i] 记录从开始至第 i 天时，“劳累的天数”与“不劳累的天数”的差值；则第 i 天到第 j 天的“劳累的天数”与“不劳累的天数”的差值等于 sumArry[j] - sumArray[i] ；则题目所求为满足 sumArry[j] - sumArray[i] > 0 的最大跨度 [i,j] ；使用递减栈求解该最大跨度问题。
int longestWPI(vector<int>& hours)
{
	int n = hours.size();
	vector<int> sumArray(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		sumArray[i] = sumArray[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
	}

	//使用递减栈求出满足 sumArry[j] > sumArray[i] 的最大跨度 [i,j]
	stack<int> decreaseStack;
	decreaseStack.push(0);
	//从 sumArry 首元素开始，将比栈顶小的元素索引压栈。
	for (int i = 1; i < n + 1; i++)
	{
		if (sumArray[i] < sumArray[decreaseStack.top()])
			decreaseStack.push(i);
	}

	//从 sumArry 尾元素开始移动 j ，若 sumArray[j] > sumArray[decreaseStack.top()] 则将 decreaseStack.top() 弹出（因为 decreaseStack.top() 成为跨度左界的情况的跨度最大值已计算完毕），否则将 j 向左移动一位（因为 j 成为跨度右界的情况的跨度最大值已计算完毕）
	int maxLength = 0;
	int lastTop;
	int j = n;
	while (j > 0)
	{
		if (decreaseStack.empty())
			break;
		if (sumArray[j] > sumArray[decreaseStack.top()])
		{
			lastTop = decreaseStack.top();
			decreaseStack.pop();
			maxLength = (maxLength > j - lastTop ? maxLength : j - lastTop);
		}
		else
			j--;
	}
	return maxLength;
}


int main1124()
{
	//vector<int> test = { 9,9,6,0,6,6,9 };
	vector<int> test = { 6,9,6 };
	int ret = longestWPI(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}