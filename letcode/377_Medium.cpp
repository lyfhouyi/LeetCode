#include<iostream>
#include<vector>

using namespace std;

//����һ���� ��ͬ ������ɵ����� nums ����һ��Ŀ������ target ������� nums ���ҳ��������ܺ�Ϊ target ��Ԫ����ϵĸ�����
//
//��Ŀ���ݱ�֤�𰸷��� 32 λ������Χ��
//
//
//��ʾ��
//
//	1 <= nums.length <= 200
//	1 <= nums[i] <= 1000
//	nums �е�����Ԫ�� ������ͬ
//	1 <= target <= 1000
//
//
//���ף���������������к��и����ᷢ��ʲô�������������ֱ仯��������������֣���Ҫ����Ŀ�������Щ����������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/combination-sum-iv
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����㷨�����ݵ�ǰ���Ԫ�غ� currentSum �ж���һ�����Խ��ĸ�Ԫ�ؼ��뵽��ǰ����С���������һ�����뵱ǰ��ϵ�����һ��Ԫ�أ��ݹ������ǰ���Ԫ�غ�����Ҫ��ʱ������������� ret ��һ��
void validCombination(vector<int>& nums, int currentSum, int target, int& ret)
{
	if (currentSum == target)
	{
		cout << "find:" << ret << endl;
		ret++;
		return;
	}
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (nums[i] + currentSum <= target)
			validCombination(nums, nums[i] + currentSum, target, ret);
	}
	return;
}


//�ݹ顣�ݹ���� validCombination() �������ж�Ӧ�ڵ�ǰ����м����ĸ�Ԫ�ء�
//�㷨��ȷ����ʱ�䳬ʱ��
//int combinationSum4(vector<int>& nums, int target)
//{
//	int ret = 0;
//	validCombination(nums, 0, target, ret);
//	return ret;
//}


//һά��̬�滮��ά��һ��һά���飺dp[i] ��ʾԪ��֮��Ϊ i ����ϵĸ�����
//״̬ת�ƺ�����dp[i] = sum(dp[i - nums[j]]) ������ nums[j] <= i ��
//�߽�������dp[:] = 0 ��dp[0] = 1 ��
//���Ž⣺dp[target] ��ֵ��
int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	int n = nums.size();
	//�������� dp ����
	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (nums[j] <= i && dp[i - nums[j]] < INT_MAX - dp[i])
				dp[i] += dp[i - nums[j]];
		}
	}
	return dp[target];
}


int main377()
{
	//vector<int> test = { 1,2,3 };
	vector<int> test = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111 };
	//vector<int> test = { 9 };
	int ret = combinationSum4(test, 999);
	cout << "main��ret = " << ret << endl;
	return 0;
}