#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
//
//进阶：
//
//	一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//	一个简单的改进方案是使用 O(m  + n) 的额外空间，但这仍然不是最好的解决方案。
//	你能想出一个仅使用常量空间的解决方案吗？
//
//
//提示：
//
//	m == matrix.length
//	n == matrix[0].length
//	1 <= m, n <= 200
//	- 2^31 <= matrix[i][j] <= 2^31 - 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/set-matrix-zeroes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：使用栈记录需置零的行和列。首先遍历原始矩阵，记录需置零的行和列；随后将需置零的行和列置零。
//void setZeroes(vector<vector<int>>& matrix)
//{
//	stack<int> rowStack;
//	stack<int> colStack;
//	int m = matrix.size();
//	int n = matrix[0].size();
//	for (int i = 0; i < m; i++) //记录需置零的行和列
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (matrix[i][j] == 0)
//			{
//				rowStack.push(i);
//				colStack.push(j);
//			}
//		}
//	}
//
//	int tmp;
//	while (!rowStack.empty()) //将需置零的行置零
//	{
//		tmp = rowStack.top();
//		rowStack.pop();
//		for (int j = 0; j < n; j++)
//		{
//			matrix[tmp][j] = 0;
//		}
//	}
//	while (!colStack.empty()) //将需置零的列置零
//	{
//		tmp = colStack.top();
//		colStack.pop();
//		for (int i = 0; i < m; i++)
//		{
//			matrix[i][tmp] = 0;
//		}
//	}
//}


//解法二：使用原始矩阵的第一行和第一列记录需置零的行和列，使用两个辅助变量记录原始矩阵的第一行和第一列是否已包含零。首先遍历原矩阵的第一行和第一列，记录其是否已包含零，随后遍历原始矩阵，使用原矩阵的第一行和第一列记录需置零的行和列；最后将需置零的行和列（包括第一行和第一列）置零。
void setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	bool rowZero = false;
	bool colZero = false;
	for (int j = 0; j < n; j++) //记录原始矩阵的第一行是否已包含零
	{
		if (matrix[0][j] == 0)
		{
			rowZero = true;
			break;
		}
	}
	for (int i = 0; i < m; i++) //记录原始矩阵的第一列是否已包含零
	{
		if (matrix[i][0] == 0)
		{
			colZero = true;
			break;
		}
	}
	for (int i = 0; i < m; i++) //记录需置零的行和列
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < m; i++) //将需置零的行和列置零
	{
		for (int j = 1; j < n; j++)
		{
			if (matrix[0][j] == 0 || matrix[i][0] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}
	if (rowZero)
	{
		for (int j = 0; j < n; j++) //将原始矩阵的第一行置零
		{
			matrix[0][j] = 0;
		}
	}
	if (colZero)
	{
		for (int i = 0; i < m; i++) //将原始矩阵的第一列置零
		{
			matrix[i][0] = 0;
		}
	}
}


int main73()
{
	vector<vector<int>> test = { {0, 1, 2, 0},{3, 4, 5, 2}, {1, 3, 1, 5} };
	setZeroes(test);
	cout << "main：ret = " << endl;
	for (vector<vector<int>>::iterator it1 = test.begin(); it1 != test.end(); it1++)
	{
		for (vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << *it2 << "  ";
		}
		cout << endl;
	}
	return 0;
}