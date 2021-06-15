#include<iostream>
#include<vector>

using namespace std;

//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//
//˵����
//
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/single-number
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ��λ���㣺��λ���1.����������㽻���ɺͽ���ɣ�2.�κ����������������������Ϊ 0��3.�κ����� 0 ���������Ϊ�䱾��
int singleNumber(vector<int>& nums)
{
	int ret = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++)
		ret ^= nums[i];
	return ret;
}

//�ⷨ����λ���㣺��λ���ࡣ�𰸵ĵ� i ��������λ��������������Ԫ�صĵ� i ��������λ֮�ͳ��� 2 ��������
//int singleNumber(vector<int>& nums)
//{
//	int ret = 0;
//	int n = nums.size();
//	int bitSum;
//	for (int i = 0; i < 32; i++)
//	{
//		bitSum = 0;
//		for (int j = 0; j < n; j++)
//		{
//			bitSum += (nums[j] >> i) & 1;
//		}
//		ret += ((bitSum % 2) & 1) << i;
//	}
//	return ret;
//}


int main()
{
	vector<int> test = { 4,1,2,1,2 };
	int ret = singleNumber(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}