#include<iostream>
#include<vector>

using namespace std;

//在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。
//
//给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。
//
//重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
//
//如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
//
//
//注意：
//
//	给定矩阵的宽和高范围在[1, 100]。
//	给定的 r 和 c 都是正数。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reshape-the-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//遍历原数组，将各元素位置映射至新数组位置。
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	int rowsOld = nums.size();
	int colsOld = nums[0].size();
	if (r*c != rowsOld * colsOld)
		return nums;

	vector<vector<int>> ret(r, vector<int>(c));
	for (int i = 0; i < rowsOld; i++)
	{
		for (int j = 0; j < colsOld; j++)
		{
			ret[(i*colsOld + j) / c][(i*colsOld + j) % c] = nums[i][j];
		}
	}
	return ret;
}


int main566()
{
	vector<vector<int>> test = { {1,2},{3,4} };
	vector<vector<int>> ret = matrixReshape(test, 4, 1);
	cout << "main：ret = " << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << *it2 << "  ";
		}
		cout << endl;
	}
	return 0;
}