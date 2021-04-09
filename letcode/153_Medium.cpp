#include<iostream>
#include<vector>

using namespace std;

//��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣���磬ԭ���� nums = [0, 1, 2, 4, 5, 6, 7] �ڱ仯����ܵõ���
//	����ת 4 �Σ�����Եõ�[4, 5, 6, 7, 0, 1, 2]
//	����ת 7 �Σ�����Եõ�[0, 1, 2, 4, 5, 6, 7]
//ע�⣬����[a[0], a[1], a[2], ..., a[n - 1]] ��תһ�� �Ľ��Ϊ����[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] ��
//
//����һ��Ԫ��ֵ ������ͬ ������ nums ����ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е� ��СԪ�� ��
//
//
//��ʾ��
//
//	n == nums.length
//	1 <= n <= 5000
//	- 5000 <= nums[i] <= 5000
//	nums �е��������� ������ͬ
//	nums ԭ����һ��������������飬�������� 1 �� n ����ת
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//���ֲ��ҡ������е� mid ����ֵ��������˵��ֵ�Ĵ�С��ȷ��������СֵӦ�����������Ҳࡣ
int findMin(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid;
	while (left < right) //���ֲ��ң��������� [left,right]
	{
		mid = (left + right) / 2;
		if (nums[right] > nums[left]) //���� [left,right] �Ѱ���������
			return nums[left];
		if (nums[left] > nums[mid]) //��Сֵֻ��λ�� [left,mid] ��
		{
			right = mid;
		}
		else //��Сֵֻ��λ�� (mid,right] ��
		{
			left = mid + 1;
		}
	}
	return nums[left];
}


int main153()
{
	//vector<int> test = { 3,4,5,1,2 };
	vector<int> test = { 11, 13, 15, 17 };
	//vector<int> test = { 4,5,6,7,0,1,2 };
	int ret = findMin(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}