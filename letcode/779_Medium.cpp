#include<iostream>

using namespace std;

//在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
//
//给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）
//
//
//注意：
//
//	N 的范围 [1, 30].
//	K 的范围 [1, 2 ^ (N - 1)].
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/k-th-symbol-in-grammar
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递归。(N,K) = (N-1,K) ,当 K <= 2^(N - 2) 时， !(N-1,K - 2^(N - 2)) ,当 K > 2^(N - 2) 时。递归基：(1,1) = 0 。
int kthGrammar(int N, int K)
{
	if (N == 1)
		return 0;
	if (K <= pow(2, N - 2))
		return kthGrammar(N - 1, K);
	else
		return !kthGrammar(N - 1, K - pow(2, N - 2));
}


int main779()
{
	int ret = kthGrammar(30, 999999999);
	cout << "main：ret = " << ret << endl;
	return 0;
}