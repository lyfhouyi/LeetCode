#include<iostream>
#include<vector>

using namespace std;

//给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。
//
//矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
//
//
//提示：
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	- 109 <= matrix[i][j] <= 109
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/transpose-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力解法。遍历原矩阵一次，A_ij = AT_ji 。
vector<vector<int>> transpose(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> ret(n, vector<int>(m));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			ret[j][i] = matrix[i][j];
	}
	return ret;
}


int main867()
{
	//vector<vector<int>> test = { {3} };
	//vector<vector<int>> test = { {1,2,3},{4,5,6} };
	vector<vector<int>> test = { {1,3,1},{1,5,1},{4,2,1} };
	vector<vector<int>> ret = transpose(test);
	cout << "main：ret =" << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << " ";
		cout << endl;
	}
	return 0;
}