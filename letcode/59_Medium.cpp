#include<iostream>
#include<vector>

using namespace std;

//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//
//提示：
//
//	1 <= n <= 20
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/spiral-matrix-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//填充最外圈的元素
void fillOutside(int beginI, int beginJ, int rows, int cols, vector<vector<int>>& matrix, int& beginValue)
{
	if (rows == 1)
	{
		for (int j = 0; j < cols; j++)
			matrix[beginI][beginJ + j] = beginValue++;
		return;
	}
	else if (cols == 1)
	{
		for (int i = 0; i < rows; i++)
			matrix[beginI + i][beginJ + cols - 1] = beginValue++;
		return;
	}
	for (int j = 0; j < cols - 1; j++) //输出上行
		matrix[beginI][beginJ + j] = beginValue++;
	for (int i = 0; i < rows - 1; i++) //输出右列
		matrix[beginI + i][beginJ + cols - 1] = beginValue++;
	for (int j = 0; j < cols - 1; j++) //输出下行
		matrix[beginI + rows - 1][beginJ + cols - 1 - j] = beginValue++;
	for (int i = 0; i < rows - 1; i++) //输出左列
		matrix[beginI + rows - 1 - i][beginJ] = beginValue++;
}


//暴力解法。逐层填充最外圈的元素。
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> ret(n, vector<int>(n, 0));
	int beginValue = 1;
	int beginPos = 0;
	while (n > 0)
	{
		fillOutside(beginPos, beginPos, n, n, ret, beginValue);
		beginPos++;
		n -= 2;
	}
	return ret;
}


int main59()
{
	int test = 10;
	vector<vector<int>> ret = generateMatrix(test);
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << "[";
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << ",";
		}
		cout << "]" << endl;
	}
	return 0;
}