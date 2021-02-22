#include<iostream>
#include<vector>

using namespace std;

//����һ�� m x n �ľ��� matrix ���������������������ľ��󣬷��� true �����򣬷��� false ��
//
//���������ÿһ�������ϵ����µĶԽ����ϵ�Ԫ�ض���ͬ����ô��������� �������ľ��� ��
//
//
//��ʾ��
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 20
//	0 <= matrix[i][j] <= 99
//
//
//���ף�
//
//	�������洢�ڴ����ϣ������ڴ����ޣ�������һ�����ֻ�ܽ������һ�м��ص��ڴ��У�����ô�죿
//	�������̫��������һ��ֻ�ܽ���������һ�м��ص��ڴ��У�����ô�죿
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/toeplitz-matrix
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ�������ⷨ�����α������и��м����и��У��ֱ���Խ���Ԫ���Ƿ���ȡ�
//bool isToeplitzMatrix(vector<vector<int>>& matrix)
//{
//	int m = matrix.size();
//	int n = matrix[0].size();
//	int j;
//	int comp;
//
//	for (int i = 0; i < m; i++) //�������и��У����Խ���
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
//	for (int i = 1; i < n; i++) //�������и��У����Խ���
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


//�ⷨ���������ⷨ��˳��������и��У��жϸ�Ԫ���Ƿ�������½ǵ�Ԫ�أ�����У���ȡ�
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


//�ⷨ���������ⷨ��˳��������и��У��жϸ�Ԫ���Ƿ�������Ͻǵ�Ԫ�أ�����У���ȡ�
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
	cout << "main��ret = " << ret << endl;
	return 0;
}