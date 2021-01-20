#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

//����һ���������飬���������ҳ�����������ɵ����˻������������˻���
//
//
//ע�� :
//
//	�������������鳤�ȷ�Χ��[3, 104]�����������е�Ԫ�ط�Χ��[-1000, 1000]��
//	����������������������ĳ˻����ᳬ��32λ�з��������ķ�Χ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/maximum-product-of-three-numbers
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ����Ԫ������Ϊ�������������鲢���򣬸���������Ԫ�صĸ������ز�ͬ��ֵ��
//int maximumProduct(vector<int>& nums)
//{
//	vector<int>posArray;
//	vector<int>negArray;
//	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//	{
//		if (*it >= 0)
//			posArray.push_back(*it);
//		else
//			negArray.push_back(*it);
//	}
//	sort(posArray.begin(), posArray.end(), [=](int A, int B) {return A > B; });
//	sort(negArray.begin(), negArray.end());
//	switch (posArray.size())
//	{
//	case 0:return negArray[negArray.size() - 1] * negArray[negArray.size() - 2] * negArray[negArray.size() - 3];
//	case 1:return negArray[0] * negArray[1] * posArray[0];
//	case 2:return (negArray.size() == 1 ? (posArray[0] * posArray[1] * negArray[0]) : (posArray[0] * negArray[0] * negArray[1]));
//	default:return (negArray.size() > 1 ? (max(posArray[0] * posArray[1] * posArray[2], negArray[0] * negArray[1] * posArray[0])) : (posArray[0] * posArray[1] * posArray[2]));
//	}
//	return 0;
//}


//�ⷨ������ԭ����������������ֻ���ڡ�β���������ĳ˻������ײ���������β���ĳ˻����г��֡�
//int maximumProduct(vector<int>& nums)
//{
//	sort(nums.begin(), nums.end());
//	int n = nums.size();
//	return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
//}


//�ⷨ����˼·ͬ�ⷨ����ֻ������ʹ�����򣬶����ڵ�ָ���������ʱ��¼��С����������������������
int maximumProduct(vector<int>& nums)
{
	int min1 = INT_MAX;
	int min2 = INT_MAX;
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	int max3 = INT_MIN;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		//����������������ע���ӣ�
		if (*it > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = *it;
		}
		else
		{
			if (*it > max2)
			{
				max3 = max2;
				max2 = *it;
			}
			else
				if (*it > max3)
					max3 = *it;
		}

		//������С����������ע���ӣ�
		if (*it < min1)
		{
			min2 = min1;
			min1 = *it;
		}
		else
			if (*it < min2)
				min2 = *it;
	}
	return max(max1*max2*max3, max1*min1*min2);
}


int main628()
{
	vector<int> test = { 903, 606, 48, -474, 313, -672, 872, -833, 899, -629, 558, -368, 231, 621, 716, -41, -418, 204, -1, 883, 431, 810, 452, -801, 19, 978, 542, 930, 85, 544, -784, -346, 923, 224, -533, -473, 499, -439, -925, 171, -53, 247, 373, 898, 700, 406, -328, -468, 95, -110, -102, -719, -983, 776, 412, -317, 606, 33, -584, -261, 761, -351, -300, 825, 224, 382, -410, 335, 187, 880, -762, 503, 289, -690, 117, -742, 713, 280, -781, 447, 227, -579, -845, -526, -403, -714, -154, 960, -677, 805, 230, 591, 442, -458, -905, 832, -285, 511, 536, -86 };
	//vector<int> test = {7,3,1,0,0,6};
	int ret = maximumProduct(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}