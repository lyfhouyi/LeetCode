#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//�ڸ����������У�ÿ����Ԫ���������������ֵ֮һ��
//
//	ֵ 0 ����յ�Ԫ��
//	ֵ 1 �����������ӣ�
//	ֵ 2 �����õ����ӡ�
//	ÿ���ӣ��κ��븯�õ����ӣ��� 4 ���������ϣ����ڵ��������Ӷ��ḯ�á�
//
//����ֱ����Ԫ����û����������Ϊֹ�����뾭������С����������������ܣ����� - 1��
//
//
//��ʾ��
//
//	1 <= grid.length <= 10
//	1 <= grid[0].length <= 10
//	grid[i][j] ��Ϊ 0��1 �� 2
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/rotting-oranges
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�������������ʹ�ö��д洢���¸��õ����ӡ����ȱ���ԭʼ���飬����ǰ�Ѹ��õ����ӵ�λ��ѹ����У����ѭ��ȡ�����У�ֱ����û�����ʵ����ӻ�û���µ����Ӹ��ã�������ǰ���ӵ�����������Ϊ���ã�������ѹ����У�ͬʱ�������¸��õ���������������ʱ��ѭ����ɺ����������ʵ����ӣ��򷵻� -1 �����򷵻ظ�����ʱ��
int orangesRotting(vector<vector<int>>& grid)
{
	int freshCnt = 0; //�������ӵ�����
	int lastRotCnt = 0; //���¸��õ����ӵ�����
	queue<int> rotQueue; //���ö���
	int m = grid.size();
	int n = grid[0].size();
	for (int i = 0; i < m; i++) //��ʼ�����ö���
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1)
				freshCnt++;
			else if (grid[i][j] == 2)
			{
				rotQueue.push(i * n + j);
				lastRotCnt++;
			}
		}
	}

	int decayTime = 0;
	int newRotCnt;
	while (freshCnt != 0 && lastRotCnt != 0) //��û�����ʵ����ӻ�û���µ����Ӹ���ʱ�˳�ѭ��
	{
		newRotCnt = 0;
		while (lastRotCnt != 0) //���¸��õ����Ӹ��������ڵ�����
		{
			int i = rotQueue.front() / n;
			int j = rotQueue.front() % n;
			rotQueue.pop();
			if (i != 0 && grid[i - 1][j] == 1) //�����Ϸ�������
			{
				grid[i - 1][j] = 2;
				rotQueue.push((i - 1)*n + j);
				newRotCnt++;
				freshCnt--;
			}
			if (i != m - 1 && grid[i + 1][j] == 1) //�����·�������
			{
				grid[i + 1][j] = 2;
				rotQueue.push((i + 1)*n + j);
				newRotCnt++;
				freshCnt--;
			}
			if (j != 0 && grid[i][j - 1] == 1) //�����󷽵�����
			{
				grid[i][j - 1] = 2;
				rotQueue.push(i*n + j - 1);
				newRotCnt++;
				freshCnt--;
			}
			if (j != n - 1 && grid[i][j + 1] == 1) //�����ҷ�������
			{
				grid[i][j + 1] = 2;
				rotQueue.push(i*n + j + 1);
				newRotCnt++;
				freshCnt--;
			}
			lastRotCnt--;
		}
		lastRotCnt = newRotCnt;
		decayTime++; //���¸�����ʱ
	}
	if (freshCnt != 0)
		return -1;
	return decayTime;
}


int main994()
{
	//vector<vector<int>> test = { {0,2} };
	vector<vector<int>> test = { {2,1,1},{0,1,1},{1,0,1} };
	//vector<vector<int>> test = { {2,1,1},{1,1,0},{0,1,1} };
	int ret = orangesRotting(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}