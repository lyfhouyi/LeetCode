#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//����һ��Ǹ����� nums����������ÿ������˳��ÿ�������ɲ�֣�ʹ֮���һ������������
//
//ע�⣺���������ܷǳ�����������Ҫ����һ���ַ���������������
//
//
//��ʾ��
//
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 10^9
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/largest-number
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����⡱���������
bool mySort(int A, int B)
{
	string sA = to_string(A) + to_string(B); //���� A ��ǰ�����ȡ�õ�ֵ
	string sB = to_string(B) + to_string(A); //���� B ��ǰ�����ȡ�õ�ֵ
	return sA > sB;
}


//�����⡱���������
//bool mySort(int A, int B)
//{
//	long upA = 10;
//	long upB = 10;
//
//	while (upA <= A) //����С�Ĵ��� A �� 10 ��������
//		upA *= 10;
//	while (upB <= B) //����С�Ĵ��� B �� 10 ��������
//		upB *= 10;
//
//	return A * upB + B > B*upA + A;
//}


//������ѡ��������������������ϳ��ַ�����Ϊ����ֵ��
string largestNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), mySort);
	string ret;
	if (nums[0] == 0)
		return "0";
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		ret += to_string(*it);
	}
	return ret;
}


int main179()
{
	//vector<int> test = { 9,99,6,65,68,54,66,60 };
	//vector<int> test = { 10,0,0,0 };
	//vector<int> test = { 34323, 3432 };
	vector<int> test = { 0, 0, 0 };
	//vector<int> test = { 3,30,34,5,9 };
	string ret = largestNumber(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}