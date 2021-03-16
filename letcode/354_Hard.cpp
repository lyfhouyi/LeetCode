#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

//给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
//
//请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
//
//说明 :
//不允许旋转信封。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/russian-doll-envelopes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：一维动态规划。将 envelopes 按长升序排序后，维护一个一维数组：dp[i] 表示以位置 i 的信封为最大信封的俄罗斯套娃”信封个数。
//状态转移函数：dp[i] = max(dp[j]) ，j < i && envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] 。
//边界条件：max(dp[j]) = 0 ，当没有 j 满足条件时。
//最优解：dp[:] 的最大值。
//int maxEnvelopes(vector<vector<int>>& envelopes)
//{
//	int n = envelopes.size();
//	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& A, const vector<int>& B) {return (A[0] < B[0]); });
//	vector<int> dp(n, 1);
//	int currentMaxCnt;
//	int envelopesCnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		currentMaxCnt = 0;
//		for (int j = 0; j < i; j++)
//		{
//			if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
//				currentMaxCnt = currentMaxCnt > dp[j] ? currentMaxCnt : dp[j];
//		}
//		dp[i] = currentMaxCnt + 1;
//		envelopesCnt = envelopesCnt > dp[i] ? envelopesCnt : dp[i];
//	}
//	return envelopesCnt;
//}


//解法二：一维动态规划，优化版。将 envelopes 按长升序、按宽降序排序后，维护一个一维数组：dp[i] 表示以位置 i 的信封为最大信封的俄罗斯套娃”信封个数。
//状态转移函数：dp[i] = max(dp[j]) ，j < i && envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] 。
//边界条件：max(dp[j]) = 0 ，当没有 j 满足条件时。
//最优解：dp[:] 的最大值。
//int maxEnvelopes(vector<vector<int>>& envelopes)
//{
//	int n = envelopes.size();
//	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& A, const vector<int>& B) {return (A[0] < B[0]) || (A[0] == B[0] && A[1] > B[1]); });
//	vector<int> dp(n, 1);
//	int currentMaxCnt;
//	int envelopesCnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		currentMaxCnt = 0;
//		for (int j = 0; j < i; j++)
//		{
//			if (envelopes[j][1] < envelopes[i][1])
//				currentMaxCnt = currentMaxCnt > dp[j] ? currentMaxCnt : dp[j];
//		}
//		dp[i] = currentMaxCnt + 1;
//		envelopesCnt = envelopesCnt > dp[i] ? envelopesCnt : dp[i];
//	}
//	return envelopesCnt;
//}


//解法三：贪心算法。令嵌套的外层信封的变大趋势尽可能慢，即令一组“套娃”信封的最外层信封尽可能小。将 envelopes 按长升序、按宽降序排序后，维护数组 d[i] 表示嵌套层数为 i 的一组“套娃”信封的最外层信封的宽可取到的最小值。
int maxEnvelopes(vector<vector<int>>& envelopes)
{
	int n = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& A, const vector<int>& B) {return (A[0] < B[0]) || (A[0] == B[0] && A[1] > B[1]); });
	vector<int> d(1, INT_MIN);
	vector<int>::iterator it;
	for (int i = 0; i < n; i++)
	{
		if (envelopes[i][1] > d.back())
			d.push_back(envelopes[i][1]);
		else
		{
			it = lower_bound(d.begin(), d.end(), envelopes[i][1]);
			*it = envelopes[i][1];
		}
	}
	return d.size() - 1;
}


int main354()
{
	//vector<vector<int>> test = { {5,4} };
	//vector<vector<int>> test = {};
	//vector<vector<int>> test = { {4,5},{4,6},{6,7},{2,3},{1,1} };
	vector<vector<int>> test = { {17,15},{17,18},{2,8},{7,2},{17,2},{17,8},{6,15} };
	//vector<vector<int>> test = { {15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19} };
	//vector<vector<int>> test = { {5,4},{6,4},{2,3},{6,7},{3,3},{1,2},{4,4},{1,4} };
	//vector<vector<int>> test = { {5,4},{6,4},{6,7},{2,3} };
	//vector<vector<int>> test = { {30,50},{12,2},{3,4},{12,15} };
	int ret = maxEnvelopes(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}