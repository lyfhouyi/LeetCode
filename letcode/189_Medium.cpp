#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
//
//
//˵�� :
//
//	�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
//	Ҫ��ʹ�ÿռ临�Ӷ�Ϊ O(1) �� ԭ�� �㷨��


//������ÿ��ѭ���������������� 1 ��λ�ã�һ������ k �Ρ�
//�㷨��ȷ��ʱ�䳬ʱ��ʱ�临�Ӷ� O(k*n)������k = k % size��ʱ�临�Ӷ� O(1)��
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	if (size <= 1)
//		return;
//	k = k % size;
//	int tmp;
//	int i;
//	while (k > 0)
//	{
//		tmp = nums[size - 1];
//		for (i = size - 2; i >= 0; i--)
//			nums[i + 1] = nums[i];
//		nums[0] = tmp;
//		k--;
//	}
//}


//��������׼��ʼʱ����β���� k ��Ԫ�أ�ÿ��ѭ���������� 1 ��λ�ã�һ������ n-k �Ρ�
//�㷨��ȷ��ʱ�䳬ʱ��ʱ�临�Ӷ� O(k*(n-k))������k = k % size��ʱ�临�Ӷ� O(1)��
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	if (size < 1)
//		return;
//	k = k % size;
//	int tmp;
//	int i;
//	vector<int>::iterator it = nums.end();
//	while (it != nums.begin() + k)
//	{
//		it = it - k;
//		tmp = *(it - 1);
//		for (i = 0; i < k; i++)
//		{
//			*(it - 1) = *it;
//			it++;
//		}
//		it--;
//		*it = tmp;
//	}
//}





//�ⷨһ��ʹ�ö���Ŀռ�
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	k = k % size;
//	for (int i = 0; i < size - k; i++)
//		nums.push_back(nums[i]);
//	nums.assign(nums.begin() + size - k, nums.end());
//}


//�ⷨ�������鷭ת
//void rotate(vector<int>& nums, int k)
//{
//	k = k % nums.size();
//	reverse(nums.begin(), nums.end());
//	reverse(nums.begin(), nums.begin() + k);
//	reverse(nums.begin() + k, nums.end());
//}


//�ⷨ������״�滻
void rotate(vector<int>& nums, int k)
{
	int size = nums.size();
	k = k % size;
	int changeCnt = 0;
	int startIndex=0;
	int currentIndex;
	int changeIndex;
	int tmp;
	while (changeCnt < size)
	{
		currentIndex = startIndex;
		tmp = nums[currentIndex];
		do 
		{
			changeIndex = (currentIndex + k + size) % size;
			swap(nums[changeIndex], tmp);
			changeCnt++;
			currentIndex = changeIndex;
		} while (currentIndex != startIndex);
		startIndex++;
	}
}


int main189()
{
	vector<int> test = { 1};
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << "  ";
	cout << endl;
	rotate(test,7);
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}