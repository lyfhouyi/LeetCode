#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std;

//����һ�� m x n �ľ��� matrix ��һ������ k ���ҳ������ؾ����ڲ���������Ĳ����� k �������ֵ�͡�
//
//��Ŀ���ݱ�֤�ܻ����һ����ֵ�Ͳ����� k �ľ�������
//
//
//��ʾ��
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 100
//	- 100 <= matrix[i][j] <= 100
//	- 10^5 <= k <= 10^5
//
//
//���ף��������Զ�����������������ƽ��������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ����������������Ԥ����ǰ׺������ preSum[i][j] ��ʾ���� matrix[0:i][0:j] ��Ԫ�صĺͣ���������������Ͼ��ο��λ�ã�ʹ��ǰ׺�����������ο��ڵ�Ԫ�غͣ�����Ҫ������Ԫ�غͼ�Ϊ����
//�㷨��ȷ�����ǳ����׳�ʱ��
//int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
//{
//	int m = matrix.size();
//	int n = matrix[0].size();
//	vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
//
//	//Ԥ����ǰ׺������
//	int sumLine;
//	for (int i = 1; i <= m; i++)
//	{
//		sumLine = 0;
//		for (int j = 1; j <= n; j++)
//		{
//			sumLine += matrix[i - 1][j - 1];
//			preSum[i][j] = preSum[i - 1][j] + sumLine;
//		}
//	}
//
//	//�ҵ�����Ҫ���Ԫ�غ����ľ��ο�
//	int ret = INT_MIN;
//	int currentSum;
//	for (int i1 = 0; i1 < m; i1++) //����ԭ�����Ͼ��ο��λ��
//	{
//		for (int j1 = 0; j1 < n; j1++)
//		{
//			for (int i2 = i1; i2 < m; i2++)
//			{
//				for (int j2 = j1; j2 < n; j2++)
//				{
//					currentSum = preSum[i2 + 1][j2 + 1] - preSum[i2 + 1][j1] - preSum[i1][j2 + 1] + preSum[i1][j1];
//					if (currentSum <= k && currentSum > ret)
//						ret = currentSum;
//				}
//			}
//		}
//	}
//	return ret;
//}


//�ⷨ�������򼯺ϡ�����Ԥ����ǰ׺������ preSum[i][j] ��ʾ���� matrix[0:i][0:j] ��Ԫ�صĺͣ���������������Ͼ��ο�������ߣ����������ߣ���ʹ��ǰ׺�����鼰���򼯺��ҵ�ʹԪ�غ����������Ҫ��ĵ������ߣ��̶����±ߣ����ұ��ƶ��Ĺ����У��������ľ��ο��ڵ�Ԫ�غʹ��뼯�ϣ�����һ�ұߣ��ڼ������ҵ�����Ҫ�����СԪ�ؼ�Ϊ��ѡ�⡣
int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));

	//Ԥ����ǰ׺������
	int sumLine;
	for (int i = 1; i <= m; i++)
	{
		sumLine = 0;
		for (int j = 1; j <= n; j++)
		{
			sumLine += matrix[i - 1][j - 1];
			preSum[i][j] = preSum[i - 1][j] + sumLine;
		}
	}

	//�ҵ�����Ҫ���Ԫ�غ����ľ��ο�
	int ret = INT_MIN;
	int currentSum;
	int rightSum;
	set<int> leftSumSet;
	set<int>::iterator it;
	for (int top = 0; top < m; top++) //����ԭ�����Ͼ��ο������������
	{
		for (int bot = top; bot < m; bot++)
		{
			leftSumSet.clear(); //��յ�ǰ���±��µ����Ԫ�غͼ���
			leftSumSet.insert(0); //��ʼ״̬�����Ϊ 0 ʱ������Ϊ 0
			for (int right = 0; right < n; right++)
			{
				rightSum = preSum[bot + 1][right + 1] - preSum[top][right + 1];
				it = leftSumSet.lower_bound(rightSum - k);
				if (it != leftSumSet.end()) //�ҵ��˵�ǰ�ұ��£�����ʹ���ο��ڵ�Ԫ�غ�����Ҫ��ģ����ֵ
					ret = rightSum - *it > ret ? rightSum - *it : ret;
				leftSumSet.insert(rightSum);
			}
		}

	}
	return ret;
}


int main()
{
	//vector<vector<int>> test = { {-1,2,3},{-9,1,2},{-1,-2,-4} };
	//vector<vector<int>> test = { {7, 7, 4, -6, -10},{-7, -3, -9, -1, -7},{9, 6, -3, -7, 7},{-4, 1, 4, -3, -8},{-7, -4, -4, 6, -10},{1, 3, -2, 3, -10},{8, -2, 1, 1, -8} };
	//vector<vector<int>> test = { {1,0,1},{0,-2,3} };
	//vector<vector<int>> test = { {1} };
	vector<vector<int>> test = { {5, -4, -3, 4},{-3, -4, 4, 5},{5, 1, 5, -4} };
	//vector<vector<int>> test = { {2,2,-1} };
	int ret = maxSumSubmatrix(test, 3);
	cout << "main��ret = " << ret << endl;
	return 0;
}