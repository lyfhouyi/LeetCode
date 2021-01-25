#include<iostream>
#include<vector>

using namespace std;

//����һ��δ��������������飬�ҵ���� ���������������У������ظ����еĳ��ȡ�
//
//���������������� �����������±� l �� r��l < r��ȷ�����������ÿ�� l <= i < r������ nums[i] < nums[i + 1] ����ô������[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] �����������������С�
//
//
//��ʾ��
//
//	0 <= nums.length <= 10^4
//	- 10^9 <= nums[i] <= 10^9
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//��ָ���������
int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int maxLength = 1;
	int currentLength = 1;
	for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++)
	{
		if (*it > *(it - 1))
			currentLength++;
		else
			currentLength = 1;
		maxLength = maxLength > currentLength ? maxLength : currentLength;
	}
	return maxLength;
}


int main674()
{
	//vector<int> test = { -10 ,8,6,5,1,3,38,6,7,2 };
	//vector<int> test = { 1,3,5,4,7 };
	vector<int> test = {  };
	int ret = findLengthOfLCIS(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}