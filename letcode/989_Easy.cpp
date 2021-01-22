#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。
//
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//
//
//提示：
//
//	1 <= A.length <= 10000
//	0 <= A[i] <= 9
//	0 <= K <= 10000
//	如果 A.length > 1，那么 A[0] != 0
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-to-array-form-of-integer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//反向遍历数组。
vector<int> addToArrayForm(vector<int>& A, int K)
{
	int carryBit = 0;
	int tmp;

	//处理 A 数组的各个数位
	for (vector<int>::reverse_iterator rit = A.rbegin(); rit != A.rend(); rit++)
	{
		tmp = K % 10 + carryBit + *rit;
		*rit = tmp % 10;
		carryBit = tmp / 10;
		K /= 10;
	}

	//处理剩下的 K
	vector<int> residue;
	K += carryBit;
	while (0 != K)
	{
		residue.push_back(K % 10);
		K /= 10;
	}

	if (residue.empty())
		return A;
	reverse(residue.begin(), residue.end());
	residue.insert(residue.end(), A.begin(), A.end());
	return residue;
}


int main989()
{
	vector<int> test = {  };
	vector<int> ret = addToArrayForm(test, 863);
	cout << "main：ret = ";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}