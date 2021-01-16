#include<iostream>
#include<vector>

using namespace std;

//给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。
//
//返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。
//
//
//提示：
//
//	1 <= A.length <= 30000
//	A[i] 为 0 或 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-prefix-divisible-by-5
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历数组。思路：当前最新看到数一定位于最低有效位，则令一个（假想的）指针指向截至目前为止，更高的有效位为 5 的整数倍的位置，那么只需考虑两个指针之间的二进制数是否为 5 的整数倍即可。
//算法细节：为防止 between 溢出，每次循环令 between = between % 5 。可以证明，此操作不会改变 between 是否是 5 的整数倍这一事实。
//上述算法细节的理论依据：(a * b) % p = (a % p * b % p) % p ；(a + b) % p = (a % p + b % p) % p 
vector<bool> prefixesDivBy5(vector<int>& A) 
{
	int n = A.size();
	int between = 0;
	vector<bool> ret(n);
	for (int i = 0; i < n; i++)
	{
		//if (between > 5)
		//	between -= 5; //等价于 between %= 5;
		between %= 5;
		between= A[i]+(between<<1); //加法运算的优先级高于移位运算
		if (0 == between % 5)
		{
			between = 0;
			ret[i] = true;
		}
		else
			ret[i] = false;
	}
	return ret;
}


int main1018()
{
	vector<int> test = { 0,1,1,1,1,1,1 };
	vector<bool> ret = prefixesDivBy5(test);
	cout << "main：ret = ";
	for (vector<bool>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << "  ";

	return 0;
}