#include<iostream>
#include<vector>

using namespace std;

//����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ���������� ������ɾ����������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
//
//
//˵����
//
//Ϊʲô������ֵ��������������Ĵ��������أ�
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
//
//��ʾ��
//
//	1 <= nums.length <= 3 * 10^4
//	- 10^4 <= nums[i] <= 10^4
//	nums �Ѱ���������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//˫ָ�롣˫ָ������������顣ʹ�� itOld ����ԭʼ���飬����ָ�������Ԫ�س��ֵĸ���С�� 2 �Σ����丳ֵ�� itNew �������� itNew ����һλ����� itNew ������λ�ü�Ϊ�������Ԫ�ظ�����
int removeDuplicates80(vector<int>& nums) {
	int n = nums.size();
	int itNew = 0; //ָ�������顱��ָ��
	int itOld = 0; //ָ�򡰾����顱��ָ��
	int lastValue = nums[0];
	int lastCnt = 0;
	while (itOld < n) //��������������顱
	{
		if (nums[itOld] == lastValue)
		{
			if (lastCnt < 2)
			{
				nums[itNew] = nums[itOld];
				lastCnt++;
				itNew++;
			}
		}
		else
		{
			nums[itNew] = nums[itOld];
			lastValue = nums[itOld];
			lastCnt = 1;
			itNew++;
		}
		itOld++;
	}
	return itNew;
}


int main80()
{
	vector<int> test = { 1,1,1,2,2,3 };
	//vector<int> test = { 0,0,1,1,1,1,2,3,3 };
	int ret = removeDuplicates80(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}