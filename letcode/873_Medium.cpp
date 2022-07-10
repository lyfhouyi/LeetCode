#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：
//
//     n >= 3
//     对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
//
// 给定一个严格递增的正整数数组形成序列 arr ，找到 arr 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。
//
// （回想一下，子序列是从原序列 arr 中派生出来的，它从 arr 中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列）
//
//
// 提示：
//
//     3 <= arr.length <= 1000
//
//     1 <= arr[i] < arr[i + 1] <= 10^9
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//一维动态规划。维护一个一维数组：dp[i] 维护一个斐波那契式候选队列（递增队列）；队列中各元素第一个值为欲形成更长的斐波那契式子序列需要的下一元素值；队列中各元素第二个值为当前已形成的斐波那契式队列的长度。
//状态转移函数：弹出所有当前元素 i 不满足斐波那契要求且之后的数组元素均不可能满足斐波那契要求的候选元素；如果当前元素 i 满足斐波那契要求，则将当前元素 i 入队、弹出候选队列队首；如果当前元素 i 不满足斐波那契要求但之后的数组元素有可能满足斐波那契要求，则将当前元素 i 入队。
//边界条件：dp[:] 为空队列。
//最优解：dp[:] 队列中各元素第二个值的最大值。
int lenLongestFibSubseq(vector<int> &arr)
{
    vector<queue<pair<int, int>>> dp(arr.size(), queue<pair<int, int>>());
    int maxLength = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            while (!dp[j].empty() && dp[j].front().first < arr[i])
            {
                //不满足斐波那契要求且之后的数组元素均不可能满足斐波那契要求
                dp[j].pop();
            }
            if (!dp[j].empty() && dp[j].front().first == arr[i])
            {
                //满足斐波那契要求
                dp[i].push(pair<int, int>(arr[j] + arr[i], dp[j].front().second + 1)); //找到一个更长的斐波那契式子序列
                maxLength = max(maxLength, dp[j].front().second + 1);
                dp[j].pop();
            }
            else
            {
                //当前元素 i 可能成为候选斐波那契式子序列的第二项，元素 j 可能成为候选斐波那契式子序列的第一项
                dp[i].push(pair<int, int>(arr[j] + arr[i], 2));
            }
        }
    }
    return maxLength;
}

int main()
{
    // vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> test = {1, 3, 7, 11, 12, 14, 18};
    // vector<int> test = {2, 4, 7, 8, 9, 10, 14, 15, 18, 23, 32, 50};
    int ret = lenLongestFibSubseq(test);
    cout << "main：ret = " << ret << endl;
    return 0;
}