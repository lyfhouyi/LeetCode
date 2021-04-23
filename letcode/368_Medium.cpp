#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����һ���� ���ظ� ��������ɵļ��� nums �������ҳ��������������������Ӽ� answer ���Ӽ���ÿһԪ�ض�(answer[i], answer[j]) ��Ӧ�����㣺
//	answer[i] % answer[j] == 0 ����
//	answer[j] % answer[i] == 0
//������ڶ����Ч���Ӽ������������κ�һ�����ɡ�
//
//
//��ʾ��
//
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 10^9
//	nums �е��������� ������ͬ
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/largest-divisible-subset
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//һά��̬�滮������һ�����飺dp[i] ��ʾ���������� nums �������е�ǰ���£��� nums[i] Ϊ��������������Ӽ�����󳤶ȡ�
//״̬ת�ƺ������� dp[i] �������������е� nums ����� j �� [0,i - 1]���� dp[i] Ϊ���� nums[j] ���Ա� nums[i] ������ dp[j] �����ֵ + 1���������� nums[j] ���Ա� nums[i] ������ j ������ dp[i] = 1 ��
//�߽�������max(dp[j]) = 0 ����û�� j ��������ʱ��
//���Ž⣺dp[:] ȡ�����ֵ�������ɵ��Ӽ�����ͨ�����Ƶõ�����
//���Ƚ��������� nums �������У����ʹ��һά��̬�滮������ nums[i] Ϊ��������������Ӽ�����󳤶ȣ�����Ƽ���dp[:] ȡ�����ֵ�������ɵ��Ӽ�����Ϊ����
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = nums.size();

	//�������� dp ����
	vector<int> dp(n, 1);
	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		int currentMaxLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
				currentMaxLength = currentMaxLength > dp[j] ? currentMaxLength : dp[j];
		}
		dp[i] = currentMaxLength + 1;
		maxLength = maxLength > dp[i] ? maxLength : dp[i];
	}

	//���Ƽ�����������Ӽ�
	vector<int> ret;
	for (int i = n - 1; i >= 0; i--)
	{
		if (dp[i] == maxLength && (ret.empty() || ret.back() % nums[i] == 0))
		{
			ret.push_back(nums[i]);
			maxLength--;
		}
	}
	return ret;
}


int main368()
{
	//vector<int> test = { 1,2,3,4,6,8,18,54,109 };
	//vector<int> test = { 1,2,4,8 };
	vector<int> test = { 5, 9, 18, 54, 108, 540, 90, 180, 360, 720 };
	//vector<int> test = { 1 };
	vector<int> ret = largestDivisibleSubset(test);
	cout << "main��ret = ";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
		cout << *it << "  ";
	return 0;
}