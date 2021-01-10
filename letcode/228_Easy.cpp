#include<iostream>
#include<string>
#include<vector>

using namespace std;

//����һ�����ظ�Ԫ�ص������������� nums ��
//
//���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б�Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ����Ҳ���������ĳ����Χ�������� nums ������ x ��
//
//�б��е�ÿ�����䷶Χ[a, b] Ӧ�ð����¸�ʽ�����
//
//"a->b" ����� a != b
//"a" ����� a == b
//
//
//��ʾ��
//
//	0 <= nums.length <= 20
//	- 231 <= nums[i] <= 231 - 1
//	nums �е�����ֵ�� ������ͬ
//	nums ����������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/summary-ranges
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//��ָ�������
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> ret;
	if (0 == nums.size())
		return ret;
	nums.push_back(nums.back()); //����β���ڱ����Դ������һ������
	int intervalBegin = nums[0];
	for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); it++)
	{
		if (*(it-1) == *it-1)
			continue;
		string tmp = to_string(intervalBegin);
		if (intervalBegin != *(it - 1))
			tmp += "->" + to_string(*(it - 1));
		ret.push_back(tmp);
		intervalBegin = *it;
	}
	return ret;
}


int main228()
{
	vector<int> test = {-2147483647, 2147483647 };
	//vector<int> test = { 0, 2, 3, 4, 6, 8, 9 };
	//vector<int> test = { 0,1,2,4,5,7 };
	vector<string> ret = summaryRanges(test);
	cout << "main��ret = ";
	for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}