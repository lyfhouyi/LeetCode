#include<iostream>
#include<vector>

using namespace std;

//给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
//
//水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
//
//反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。
//
//
//提示：
//
//	1 <= A.length = A[0].length <= 20
//	0 <= A[i][j] <= 1
//	通过次数58, 215提交次数74, 161
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/flipping-an-image
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力解法。将 A[i][j] 替换为 !A[i][n - 1 - j] 。替换时，注意防止原值丢失。
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
{
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n / 2)
			{
				swap(A[i][j], A[i][n - 1 - j]);
			}
			A[i][j] = !A[i][j];
		}
	}
	return A;
}


int main832()
{
	//vector<vector<int>> test = { {1} };
	//vector<vector<int>> test = { {1,1,0},{1,0,1},{0,0,0} };
	vector<vector<int>> test = { {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
	vector<vector<int>> ret = flipAndInvertImage(test);
	cout << "main：ret =" << endl;
	for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << " ";
		cout << endl;
	}
	return 0;
}