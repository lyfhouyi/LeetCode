#include<iostream>
#include<vector>

using namespace std;

//��MATLAB�У���һ���ǳ����õĺ��� reshape�������Խ�һ����������Ϊ��һ����С��ͬ���¾��󣬵�������ԭʼ���ݡ�
//
//����һ���ɶ�ά�����ʾ�ľ����Լ�����������r��c���ֱ��ʾ��Ҫ���ع��ľ����������������
//
//�ع���ľ�����Ҫ��ԭʼ���������Ԫ������ͬ���б���˳����䡣
//
//������и���������reshape�����ǿ����Һ���ģ�������µ����ܾ��󣻷������ԭʼ����
//
//
//ע�⣺
//
//	��������Ŀ�͸߷�Χ��[1, 100]��
//	������ r �� c ����������
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/reshape-the-matrix
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//����ԭ���飬����Ԫ��λ��ӳ����������λ�á�
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
	cout << "main��ret = " << endl;
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