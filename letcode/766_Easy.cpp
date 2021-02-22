#include<iostream>
#include<vector>

using namespace std;

//给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。
//
//如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
//
//
//提示：
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 20
//	0 <= matrix[i][j] <= 99
//
//
//进阶：
//
//	如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
//	如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/toeplitz-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：暴击解法。依次遍历首列各行及首行各列，分别检查对角线元素是否相等。
//bool isToeplitzMatrix(vector<vector<int>>& matrix)
//{
//	int m = matrix.size();
//	int n = matrix[0].size();
//	int j;
//	int comp;
//
//	for (int i = 0; i < m; i++) //遍历首列各行，检查对角线
//	{
//		comp = matrix[i][0];
//		j = 1;
//		while (i + j < m && j < n)
//		{
//			if (matrix[i + j][j] == comp)
//				j++;
//			else
//				return false;
//		}
//	}
//
//	for (int i = 1; i < n; i++) //遍历首行各列，检查对角线
//	{
//		comp = matrix[0][i];
//		j = 1;
//		while (j < m && i + j < n)
//		{
//			if (matrix[j][i + j] == comp)
//				j++;
//			else
//				return false;
//		}
//	}
//	return true;
//}


//解法二：暴击解法。顺序遍历各行各列，判断各元素是否和其右下角的元素（如果有）相等。
//bool isToeplitzMatrix(vector<vector<int>>& matrix)
//{
//	int m = matrix.size();
//	int n = matrix[0].size();
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i + 1 < m && j + 1 < n && matrix[i + 1][j + 1] != matrix[i][j])
//				return false;
//		}
//	}
//	return true;
//}


//解法三：暴击解法。顺序遍历各行各列，判断各元素是否和其左上角的元素（如果有）相等。
bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (matrix[i - 1][j - 1] != matrix[i][j])
				return false;
		}
	}
	return true;
}


int main766()
{
	//vector<vector<int>> test = { {1,2,3,4},{5,1,2,3},{9,5,1,2} };
	vector<vector<int>> test = { {1,2},{2,2} };
	bool ret = isToeplitzMatrix(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}