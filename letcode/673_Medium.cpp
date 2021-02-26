#include<iostream>
#include<vector>

using namespace std;

//����һ��δ������������飬�ҵ�����������еĸ�����
//
//
//ע�� : ���������鳤�Ȳ����� 2000 ���ҽ��һ����32λ�з�������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//һά��̬�滮��ά���������飺dp[i] ��ʾ������Ϊ i ��Ԫ�ؽ�β���������е���ϸ���������еĳ��ȡ�cnt[i] ��ʾ������Ϊ i ��Ԫ�ؽ�β����������ȡ����ϸ����������ʱ�Ŀ��н⣨��·������������
//״̬ת�ƺ������� dp[i] ������ nums ����� j �� [0,i - 1]���� dp[i] Ϊ���� nums[j] < nums[i] �� dp[j] �����ֵ + 1���� cnt[i] Ϊ��� dp[j] ��ֵ��ȵĿ��н⣨��·�������ĸ������ܺ͡���������  nums[j] < nums[i] �� j ������ dp[i] = 1 ��cnt[i] = 1 ��
//�߽�������dp[0] = 1 ��
//���Ž⣺dp[:] ȡ�����ֵʱ��Ӧ�� cnt[i] ���ܺ͡�
int findNumberOfLIS(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(n, 1);
	vector<int> cnt(n, 1);
	int currentLength;
	int feasibleCnt;
	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		//ά�� dp ���顢cnt ����
		currentLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				if (dp[j] > currentLength)
				{
					currentLength = dp[j];
					cnt[i] = cnt[j];
				}
				else
				{
					if (dp[j] == currentLength)
						cnt[i] += cnt[j];
				}
			}
		}
		dp[i] = currentLength + 1;

		//��¼ dp ��������ֵ����Ӧ�� cnt ֵ���ܺ�
		if (dp[i] > maxLength)
		{
			maxLength = dp[i];
			feasibleCnt = cnt[i];
		}
		else
		{
			if (dp[i] == maxLength)
				feasibleCnt += cnt[i];
		}
	}
	return feasibleCnt;
}




int main673()
{
	vector<int> test = { 0,8,4,12,2,3 };
	//vector<int> test = { 2,2,2,2,2 };
	//vector<int> test = { 1,3,5,4,7 };
	int ret = findNumberOfLIS(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}