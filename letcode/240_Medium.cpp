#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
//
//
//提示：
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= n, m <= 300
//	- 10^9 <= matix[i][j] <= 10^9
//	每行的所有元素从左到右升序排列
//	每列的所有元素从上到下升序排列
//	- 10^9 <= target <= 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/search-a-2d-matrix-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：贪心算法。基于贪心的思路，每次查找都可排除矩阵的一行或一列，直到找到目标值；若查找完毕时仍未发现目标值，则目标值必不存在。
//bool searchMatrix(vector<vector<int>>& matrix, int target)
//{
//	int m = matrix.size();
//	int n = matrix[0].size();
//	int i = 0;
//	int j = n - 1;
//	while (i < m && j >= 0)
//	{
//		if (matrix[i][j] < target)
//			i++;
//		else if (matrix[i][j] > target)
//			j--;
//		else
//			return true;
//	}
//	return false;
//}


//解法二：二分查找。遍历矩阵各行，利用各行元素的有序性，使用二分查找法判断当前行中是否包含目标值。
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	for (int i = 0; i < m; i++)
	{
		if (binary_search(matrix[i].begin(), matrix[i].end(), target))
			return true;
	}
	return false;
}


int main240()
{
	vector<vector<int>> test = { {1, 4, 7, 11, 15} ,{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
	bool ret = searchMatrix(test, 30);
	cout << "main：ret = " << ret << endl;
	return 0;
}