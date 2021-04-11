#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>

using namespace std;

//编写一个程序，找出第 n 个丑数。
//
//丑数就是质因数只包含 2, 3, 5 的正整数。
//
//
//说明 :
//
//	1 是丑数。
//	n 不超过1690。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ugly-number-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//迭代。逐项判断当前数值 tryNo 是否为丑数。若当前数值 tryNo 无法被 2,3,5 整除，则不是丑数；否则，若当前数值 tryNo 可被 x 整除，则当前数值 tryNo 的丑数与否和 tryNo / x 相同。
//算法正确，但时间超时。
//int nthUglyNumber(int n)
//{
//	vector<bool> isUgly(2, false);
//	isUgly[1] = true;
//	int uglyCnt = 1; //已找到的丑数个数
//	int tryNo = 2;
//	while (uglyCnt < n) //找到第 n 个丑数
//	{
//		if (tryNo % 2 == 0)
//			isUgly.push_back(isUgly[tryNo / 2]);
//		else if (tryNo % 3 == 0)
//			isUgly.push_back(isUgly[tryNo / 3]);
//		else if (tryNo % 5 == 0)
//			isUgly.push_back(isUgly[tryNo / 5]);
//		else
//			isUgly.push_back(false);
//		tryNo++;
//		if (isUgly[isUgly.size() - 1] == true) //找到了一个丑数
//		{
//			uglyCnt++;
//			cout << "nthUglyNumber：第" << uglyCnt << "个丑数：" << isUgly.size() - 1 << endl;
//		}
//	}
//	return isUgly.size() - 1;
//}


//解法一，迭代。持续使用当前丑数集合中未使用过的最小的丑数生成新的丑数，直到新生成的最小丑数已大于满足要求数量的丑数的最大值。当已生成的丑数已达到要求的数量时，记录当前丑数集合的最大值；随后再生成的丑数可能比该最大值小，则返回值不是该最大值；继续生成丑数，直到新生成的丑数全部大于该最大值，则返回值不再更改，此时可停止生成丑数；最终返回值为停止生成丑数时，丑数集合中第 n 小的丑数。
//int nthUglyNumber(int n)
//{
//	set<int> uglySet;
//	uglySet.insert(1);
//	int uglyMax = INT_MAX;
//	set<int>::iterator it = uglySet.begin(); //丑数生成基（基于该值生成新的丑数）
//	while (it != uglySet.end() && *it <= uglyMax / 2)
//	{
//		//生成新的丑数（避免数值溢出）
//		if (*it <= INT_MAX / 2)
//			uglySet.insert(*it * 2);
//		if (*it <= INT_MAX / 3)
//			uglySet.insert(*it * 3);
//		if (*it <= INT_MAX / 5)
//			uglySet.insert(*it * 5);
//		it++; //调整丑数生成基
//		if (uglyMax == INT_MAX && uglySet.size() >= n) //当已生成的丑数已达到要求的数量时，记录当前丑数集合的最大值
//			uglyMax = *uglySet.rbegin();
//	}
//
//	//找到丑数集合中第 n 小的丑数
//	it = uglySet.begin();
//	for (int i = 0; i < n - 1; i++)
//		it++;
//	return *it;
//}


//解法一，优化版。迭代。优化方式：循环使用当前丑数集合中未使用过的最小的丑数生成新的丑数 n - 1 次。生成 n - 1 次后，当前丑数集合中未使用过的最小的丑数即为所求。优化理论：新生成的丑数一定严格大于当前的丑数，因此当前丑数在全局中的排名一定不变。
//int nthUglyNumber(int n)
//{
//	set<int> uglySet;
//	uglySet.insert(1);
//	set<int>::iterator it = uglySet.begin(); //丑数生成基（基于该值生成新的丑数）
//	for (int i = 0; i < n - 1; i++)
//	{
//		//生成新的丑数（避免数值溢出）
//		if (*it <= INT_MAX / 2)
//			uglySet.insert(*it * 2);
//		if (*it <= INT_MAX / 3)
//			uglySet.insert(*it * 3);
//		if (*it <= INT_MAX / 5)
//			uglySet.insert(*it * 5);
//		it++;
//	}
//	return *it;
//}


//解法二：一维动态规划。计算数组：dp[i] 表示第 i 个丑数。
//状态转移函数：dp[i] = max(dp[p2] * p2, dp[p3] * p3, dp[p5] * p5) ，取到最大值后，将相应的 px++ 。
//边界条件：dp[1] = 1 ，p2 = p3 = p5 = 1 。
//最优解：dp[n] 。
int nthUglyNumber(int n)
{
	vector<int> dp(n + 1, 1);
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5); //生成当前丑数集下最小的丑数
		if (dp[i] == dp[p2] * 2)
			p2++;
		if (dp[i] == dp[p3] * 3)
			p3++;
		if (dp[i] == dp[p5] * 5)
			p5++;
	}
	return dp[n];
}


int main264()
{
	int ret = nthUglyNumber(10);
	cout << "main：ret = " << ret << endl;
	return 0;
}