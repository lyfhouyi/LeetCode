#include<iostream>
#include<vector>

using namespace std;

//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//
//提示：
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 10
//	- 100 <= matrix[i][j] <= 100
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/spiral-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//输出最外圈的元素
void pushOutside(int beginI, int beginJ, int rows, int cols, vector<vector<int>>& matrix, vector<int>& ret)
{
	if (rows == 1)
	{
		for (int j = 0; j < cols; j++)
			ret.push_back(matrix[beginI][beginJ + j]);
		return;
	}
	else if (cols == 1)
	{
		for (int i = 0; i < rows; i++)
			ret.push_back(matrix[beginI + i][beginJ + cols - 1]);
		return;
	}
	for (int j = 0; j < cols - 1; j++) //输出上行
		ret.push_back(matrix[beginI][beginJ + j]);
	for (int i = 0; i < rows - 1; i++) //输出右列
		ret.push_back(matrix[beginI + i][beginJ + cols - 1]);
	for (int j = 0; j < cols - 1; j++) //输出下行
		ret.push_back(matrix[beginI + rows - 1][beginJ + cols - 1 - j]);
	for (int i = 0; i < rows - 1; i++) //输出左列
		ret.push_back(matrix[beginI + rows - 1 - i][beginJ]);
}


//暴力解法。逐层输出最外圈的元素。
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ret;
	int beginI = 0;
	int beginJ = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	while (rows > 0 && cols > 0)
	{
		pushOutside(beginI, beginJ, rows, cols, matrix, ret);
		beginI++;
		beginJ++;
		rows -= 2;
		cols -= 2;
	}
	return ret;
}


int main54()
{
	//vector<vector<int>> test = { {1,2,3,4,-5,-6},{5,6,7,8,-9,-10},{9,10,11,12,-13,-14}/*,{13,14,15,16,-17,-18}*/ };
	//vector<vector<int>> test = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18} };
	vector<vector<int>> test = { {1,2,3},{4,5,6},{7,8,9} };
	vector<int> ret = spiralOrder(test);
	cout << "main：ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}