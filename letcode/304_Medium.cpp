#include<iostream>
#include<vector>

using namespace std;

//给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为(row1, col1) ，右下角为(row2, col2) 。
//
//
//提示：
//
//	你可以假设矩阵不可变。
//	会多次调用 sumRegion 方法。
//	你可以假设 row1 ≤ row2 且 col1 ≤ col2 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/range-sum-query-2d-immutable
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法二：单行前缀和矩阵。通过预计算的单行前缀和矩阵在 O(matrix.size()) 的时间复杂度内计算原矩阵的范围和。
//class NumMatrix {
//public:
//	NumMatrix(vector<vector<int>>& matrix)
//	{
//		int rows = matrix.size();
//		if (0 == rows)
//			return;
//		int cols = matrix[0].size();
//		for (int i = 0; i < rows; i++)
//		{
//			sumMatrix.push_back(vector<int>());
//			sumMatrix[i].push_back(0);
//			for (int j = 0; j < cols; j++)
//			{
//				sumMatrix[i].push_back(sumMatrix[i][j] + matrix[i][j]); //计算单行前缀和
//			}
//		}
//	}
//
//	int sumRegion(int row1, int col1, int row2, int col2)
//	{
//		int ret = 0;
//		for (int i = row1; i <= row2; i++)
//			ret += (sumMatrix[i][col2 + 1] - sumMatrix[i][col1]);
//		return ret;
//	}
//private:
//	vector<vector<int>> sumMatrix; //单行前缀和矩阵
//};


//解法一：左上前缀和矩阵。通过预计算的左上前缀和矩阵在 O(1) 的时间复杂度内计算原矩阵的范围和。
class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix)
	{
		int rows = matrix.size();
		if (0 == rows)
			return;
		int cols = matrix[0].size();
		sumMatrixLeftUp = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
		int sumLine;
		for (int i = 0; i < rows; i++)
		{
			sumLine = 0;
			for (int j = 0; j < cols; j++)
			{
				sumLine += matrix[i][j]; //计算单行前缀和
				sumMatrixLeftUp[i + 1][j + 1] = sumMatrixLeftUp[i][j + 1] + sumLine; //计算左上前缀和
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return (sumMatrixLeftUp[row2 + 1][col2 + 1] + sumMatrixLeftUp[row1][col1] - sumMatrixLeftUp[row1][col2 + 1] - sumMatrixLeftUp[row2 + 1][col1]);
	}
private:
	vector<vector<int>> sumMatrixLeftUp; //左上前缀和矩阵
};

int main304()
{
	//vector<vector<int>> test = { {} };
	vector<vector<int>> test = { {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1},{1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5} };
	NumMatrix* obj = new NumMatrix(test);
	int ret = obj->sumRegion(2, 1, 4, 3);
	cout << "main：ret = " << ret;
	return 0;
}