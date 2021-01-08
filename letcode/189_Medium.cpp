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


//��������׼��ʼʱ����β���� k ��Ԫ����Ϊ��Ŀ��Ρ���ÿ��ѭ������������ k ��Ԫ�ؽ���λ�ã�һ��ѭ�� (n-1)/k �Ρ�
//�㷨��ȷ��ʱ�䳬ʱ��ʱ�临�Ӷ� O(n)��ʱ�临�Ӷ� O(1)��
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	if (size <= 1)
//		return;
//	k = k % size;
//	if (0 == k)
//		return;
//	int i;
//	int j;
//	int sour=size+k;
//	int dist = 0;
//
//	//ǰ (n-1)/k-1 ������ѭ��
//	for (i = 0; i < (size - 1) / k-1;i++)
//	{
//		sour -= 2*k;
//		dist = sour - k;
//		for (j = 0; j < k; j++)
//		{
//			swap(nums[sour], nums[dist]);
//			sour++;
//			dist = sour - k;
//		}
//	}
//	//���һ��ѭ��ֻ���� [begin,Ŀ���β] ��ѭ��
//	sour -= 2*k;
//	size = sour + k;
//	int tmp;
//	vector<int>::iterator it = nums.begin()+size;
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


//ʹ�ö���Ŀռ�
//void rotate(vector<int>& nums, int k)
//{
//	int size = nums.size();
//	k = k % size;
//	for (int i = 0; i < size - k; i++)
//		nums.push_back(nums[i]);
//	nums.assign(nums.begin() + size - k, nums.end());
//}


//���鷭ת
void rotate(vector<int>& nums, int k)
{
	k = k % nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

int main()
{
	vector<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << "  ";
	cout << endl;
	rotate(test, 0);
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++)
		cout << *it << "  ";
	cout << endl;
	return 0;
}