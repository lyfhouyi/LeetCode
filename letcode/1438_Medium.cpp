#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

//����һ���������� nums ����һ����ʾ���Ƶ����� limit�����㷵�������������ĳ��ȣ����������е���������Ԫ��֮��ľ��Բ����С�ڻ��ߵ��� limit ��
//
//������������������������飬�򷵻� 0 ��
//
//
//��ʾ��
//
//	1 <= nums.length <= 10 ^ 5
//	1 <= nums[i] <= 10 ^ 9
//	0 <= limit <= 10 ^ 9
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ��ʹ��˫ָ�빹�컬�����ڡ�ʹ�����򼯺ϼ��㴰����������Ԫ�صľ��Բ�����ֵ���������ֵ���� limit �򽫴����������һλ�����򽫴����Ҷ�����һλ������Ҫ��Ļ������ڵ���󳤶ȼ�Ϊ����
//int longestSubarray(vector<int>& nums, int limit)
//{
//	multiset<int> windowConclude;
//	int n = nums.size();
//	int windowRight = 0;
//	int windowLeft = 0;
//	int maxLength = 0;
//	int currentLength;
//
//	//�� [windowLeft,windowRight] Ϊ��������
//	while (windowRight < n)
//	{
//		windowConclude.insert(nums[windowRight]);
//
//		//�ҵ��� windowRight Ϊ�Ҷ˵������Ҫ����������
//		while (*windowConclude.rbegin() - *windowConclude.begin() > limit) //�����Ƴ���������˵�Ԫ��
//		{
//			windowConclude.erase(windowConclude.find(nums[windowLeft]));
//			windowLeft++;
//		}
//		currentLength = windowRight - windowLeft + 1;
//		maxLength = maxLength > currentLength ? maxLength : currentLength;
//		windowRight++;
//	}
//	return maxLength;
//}


//�ⷨ����ʹ��˫ָ�빹�컬�����ڡ�ʹ�õ������м��㴰����������Ԫ�صľ��Բ�����ֵ���������ֵ���� limit �򽫴����������һλ�����򽫴����Ҷ�����һλ������Ҫ��Ļ������ڵ���󳤶ȼ�Ϊ����
int longestSubarray(vector<int>& nums, int limit)
{
	deque<int> maxQueue; //���ֵ���С��洢���ܳ�Ϊ���������ֵ��Ԫ��ֵ��������
	deque<int> minQueue; //��Сֵ���С��洢���ܳ�Ϊ��������Сֵ��Ԫ��ֵ��������
	int n = nums.size();
	int windowRight = 0;
	int windowLeft = 0;
	int maxLength = 0;
	int currentLength;

	//�� [windowLeft,windowRight] Ϊ��������
	while (windowRight < n)
	{
		while (!maxQueue.empty() && nums[windowRight] > maxQueue.back())
			maxQueue.pop_back(); //��ЩԪ��ֵ�Ѳ����ܳ�Ϊ�������ڵ����ֵ
		while (!minQueue.empty() && nums[windowRight] < minQueue.back())
			minQueue.pop_back(); //��ЩԪ��ֵ�Ѳ����ܳ�Ϊ�������ڵ���Сֵ

		maxQueue.push_back(nums[windowRight]);
		minQueue.push_back(nums[windowRight]);

		//�ҵ��� windowRight Ϊ�Ҷ˵������Ҫ����������
		while (maxQueue.front()- minQueue.front() > limit) //�����Ƴ���������˵�Ԫ��
		{
			if (nums[windowLeft] == maxQueue.front()) //�Ƴ�����ԭ���ڵ����ֵ
				maxQueue.pop_front();
			if (nums[windowLeft] == minQueue.front()) //�Ƴ�����ԭ���ڵ���Сֵ
				minQueue.pop_front();
			windowLeft++;
		}
		currentLength = windowRight - windowLeft + 1;
		maxLength = maxLength > currentLength ? maxLength : currentLength;
		windowRight++;
	}
	return maxLength;
}


int main1438()
{
	//vector<int> test = { 10,1,2,4,7,2 };
	//vector<int> test = { 0,3,6,0,14,10,12,9,17 };
	vector<int> test = { 4,2,2,2,4,4,2,2 };
	//vector<int> test = { 8,2,4,7 };
	int ret = longestSubarray(test, 0);
	cout << "main��ret = " << ret << endl;
	return 0;
}