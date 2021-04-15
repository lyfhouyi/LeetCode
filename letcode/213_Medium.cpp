#include<iostream>
#include<vector>

using namespace std;


//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ ���ܹ�͵�Ե�����߽�
//
//
//��ʾ��
//
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 1000
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/house-robber-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//��ά��̬�滮��ά��һ����ά���飺dp[i][j] ��ʾ�� nums[i,j] ���ܹ�͵�Ե�����߽�
//״̬ת�ƺ�����dp[i][j] = max(nums[i] + dp[i + 2][j - 1], dp[i + 1][j]) ���� i != 0 || j != n - 1 ʱ��dp[0][n - 1] = nums[0] + dp[2][n - 2] > dp[1][n - 1] ? nums[0] + dp[2][n - 2] : dp[1][n - 1] ��
//�߽�������dp[:][:] = 0 ��
//���Ž⣺dp[0][n - 1] ��ֵ��
//int rob213(vector<int>& nums)
//{
//	int n = nums.size();
//	if (n == 1)
//		return nums[0];
//	vector<vector<int>> dp(n + 2, vector<int>(n, 0));
//	//�����ȱ������� dp ����
//	for (int j = 0; j < n; j++)
//	{
//		dp[j][j] = nums[j];
//		for (int i = j; i >= 0; i--)
//		{
//			if (i == j)
//				dp[j][j] = nums[j];
//			else
//				dp[i][j] = nums[i] + dp[i + 2][j] > dp[i + 1][j] ? nums[i] + dp[i + 2][j] : dp[i + 1][j];
//		}
//	}
//	return (nums[0] + dp[2][n - 2] > dp[1][n - 1] ? nums[0] + dp[2][n - 2] : dp[1][n - 1]);
//}


//һά��̬�滮��ά��һ����ά���飺dp[i] ��ʾ�� nums[i,indexLast] ���ܹ�͵�Ե�����߽�
//״̬ת�ƺ�����dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]) ��
//�߽�������dp[:] = 0 ��
//���Ž⣺dp[indexBegin] ��ֵ��
int calcRob(vector<int>& nums, int indexBegin, int indexLast)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	vector<int> dp(n + 1, 0);
	dp[indexLast] = nums[indexLast];
	for (int i = indexLast - 1; i >= indexBegin; i--)
		dp[i] = nums[i] + dp[i + 2] > dp[i + 1] ? nums[i] + dp[i + 2] : dp[i + 1];
	return dp[indexBegin];
}


//��̬�滮������͵������ֱ�Ϊ [0,n - 2] �� [1,n - 1] �Ķ��ߵĽϴ�ֵ��
int rob213(vector<int>& nums)
{
	int n = nums.size();
	int front = calcRob(nums, 0, n - 2);
	int back = calcRob(nums, 1, n - 1);
	return front > back ? front : back;
}


int main213()
{
	//vector<int> test = { 1,2,3,1 };
	//vector<int> test = { 1,4,5,2,1 };
	vector<int> test = { 1 };
	//vector<int> test = { 1,2,1,1 };
	int ret = rob213(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}