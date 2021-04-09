#include<iostream>
#include<vector>

using namespace std;

//����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
//
//
//˵�� :
//
//Ϊʲô������ֵ��������������Ĵ��������� ?
//
//��ע�⣬�����������ԡ����á���ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�
//
//����������ڲ��������� :
//
//	// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
//	int len = removeDuplicates(nums);
//
//	// �ں������޸�����������ڵ������ǿɼ��ġ�
//	// ������ĺ������صĳ���, �����ӡ�������� �ó��ȷ�Χ�� ������Ԫ�ء�
//	for (int i = 0; i < len; i++) {
//		print(nums[i]);
//	}
//
//
//
//��ʾ��
//
//	0 <= nums.length <= 3 * 10^4
//	- 10^4 <= nums[i] <= 10^4
//	nums �Ѱ���������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//˫ָ�롣˫ָ������������顣ʹ�� itOld ����ԭʼ���飬����ָ�������Ԫ��δ���ֹ������丳ֵ�� itNew �������� itNew ����һλ����� itNew ������λ�ü�Ϊ�������Ԫ�ظ�����
int removeDuplicates26(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return n;
	int itNew = 1; //ָ�������顱��ָ��
	int itOld = 1; //ָ�򡰾����顱��ָ��
	int lastValue = nums[0];
	while (itOld < n) //��������������顱
	{
		if (nums[itOld] != lastValue)
		{
			nums[itNew] = nums[itOld];
			lastValue = nums[itOld];
			itNew++;
		}
		itOld++;
	}
	return itNew;
}


int main26()
{
	//vector<int> test = { 1,1,2};
	//vector<int> test = { 1,1,1,2,2,3 };
	vector<int> test = { 0,0,1,1,1,2,2,3,3,4 };
	int ret = removeDuplicates26(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}