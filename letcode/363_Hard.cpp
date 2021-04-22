#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std;

//给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
//
//题目数据保证总会存在一个数值和不超过 k 的矩形区域。
//
//
//提示：
//
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 100
//	- 100 <= matrix[i][j] <= 100
//	- 10^5 <= k <= 10^5
//
//
//进阶：如果行数远大于列数，该如何设计解决方案？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//解法一：暴力遍历。首先预计算前缀和数组 preSum[i][j] 表示矩阵 matrix[0:i][0:j] 上元素的和；随后暴力遍历矩阵上矩形框的位置，使用前缀和数组计算矩形框内的元素和；满足要求的最大元素和即为所求。
//算法正确，但非常容易超时。
//int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
//{
//	int m = matrix.size();
//	int n = matrix[0].size();
//	vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
//
//	//预计算前缀和数组
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
//	//找到满足要求的元素和最大的矩形框
//	int ret = INT_MIN;
//	int currentSum;
//	for (int i1 = 0; i1 < m; i1++) //遍历原矩阵上矩形框的位置
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


//解法二：有序集合。首先预计算前缀和数组 preSum[i][j] 表示矩阵 matrix[0:i][0:j] 上元素的和；随后暴力遍历矩阵上矩形框的三条边（上下右三边），使用前缀和数组及有序集合找到使元素和最大且满足要求的第四条边；固定上下边，在右边移动的过程中，将其左侧的矩形框内的元素和存入集合；对任一右边，在集合中找到满足要求的最小元素即为候选解。
int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));

	//预计算前缀和数组
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

	//找到满足要求的元素和最大的矩形框
	int ret = INT_MIN;
	int currentSum;
	int rightSum;
	set<int> leftSumSet;
	set<int>::iterator it;
	for (int top = 0; top < m; top++) //遍历原矩阵上矩形框的上下右三边
	{
		for (int bot = top; bot < m; bot++)
		{
			leftSumSet.clear(); //清空当前上下边下的左侧元素和集合
			leftSumSet.insert(0); //初始状态：左边为 0 时，左侧和为 0
			for (int right = 0; right < n; right++)
			{
				rightSum = preSum[bot + 1][right + 1] - preSum[top][right + 1];
				it = leftSumSet.lower_bound(rightSum - k);
				if (it != leftSumSet.end()) //找到了当前右边下，可以使矩形框内的元素和满足要求的（最大）值
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
	cout << "main：ret = " << ret << endl;
	return 0;
}