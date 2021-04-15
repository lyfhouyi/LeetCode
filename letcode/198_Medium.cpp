#include<iostream>
#include<vector>

using namespace std;

//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
//
//
//��ʾ��
//
//	0 <= nums.length <= 100
//	0 <= nums[i] <= 400
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/house-robber
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//һά��̬�滮��ά��һ����ά���飺dp[i] ��ʾ�� nums[i,n - 1] ���ܹ�͵�Ե�����߽�
//״̬ת�ƺ�����dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]) ��
//�߽�������dp[:] = 0 ��
//���Ž⣺dp[0] ��ֵ��
int rob198(vector<int>& nums)
{
	int n = nums.size();
	if (n == 1)
		return nums[0];
	vector<int> dp(n + 2, 0);
	for (int i = n - 1; i >= 0; i--)
		dp[i] = nums[i] + dp[i + 2] > dp[i + 1] ? nums[i] + dp[i + 2] : dp[i + 1];
	return dp[0];
}


int main198()
{
	//vector<int> test = { 2,7,9,3,1 };
	//vector<int> test = { 1,2,3,1 };
	//vector<int> test = { 1,4,5,2,1 };
	vector<int> test = { 1 };
	//vector<int> test = { 1,2,1,1 };
	int ret = rob198(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}