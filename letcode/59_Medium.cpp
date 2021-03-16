#include<iostream>
#include<vector>

using namespace std;

//����һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��
//
//
//��ʾ��
//
//	1 <= n <= 20
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/spiral-matrix-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�������Ȧ��Ԫ��
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
	for (int j = 0; j < cols - 1; j++) //�������
		matrix[beginI][beginJ + j] = beginValue++;
	for (int i = 0; i < rows - 1; i++) //�������
		matrix[beginI + i][beginJ + cols - 1] = beginValue++;
	for (int j = 0; j < cols - 1; j++) //�������
		matrix[beginI + rows - 1][beginJ + cols - 1 - j] = beginValue++;
	for (int i = 0; i < rows - 1; i++) //�������
		matrix[beginI + rows - 1 - i][beginJ] = beginValue++;
}


//�����ⷨ������������Ȧ��Ԫ�ء�
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