#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//ѧУ������ȼ�����ʱ��һ��Ҫ��ѧ������ �ǵݼ� �ĸ߶�˳�����С�
//
//���㷵����������ѧ���� �ǵݼ� �߶����е���С��Ҫ�ƶ�������
//
//ע�⣬��һ��ѧ����ѡ��ʱ������֮��������κο��ܵķ�ʽ�������򣬶�δ��ѡ�е�ѧ��Ӧ�ñ��ֲ�����
//
//
//��ʾ��
//
//	1 <= heights.length <= 100
//	1 <= heights[i] <= 100
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/height-checker
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�ⷨһ�������ⷨ�������Ƚϡ�
//int heightChecker(vector<int>& heights)
//{
//	vector<int> sortHeights(heights.begin(), heights.end());
//	sort(sortHeights.begin(), sortHeights.end());
//	int n = heights.size();
//	int moveCnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (heights[i] != sortHeights[i])
//			moveCnt++;
//	}
//	return moveCnt;
//}


//�ⷨ����Ͱ���Ƚ�ԭʼ���������۲��������в�ͬԪ�صĸ�����
int heightChecker(vector<int>& heights)
{
	vector<int> bucketVec(101, 0);
	int n = heights.size();
	for (int i = 0; i < n; i++) //����Ͱ
	{
		bucketVec[heights[i]]++;
	}
	int moveCnt = 0;
	int i = 0;
	for (int j = 1; j < 101; j++) //�Ƚ�ԭʼ���������۲��������в�ͬԪ�صĸ���
	{
		while (bucketVec[j] > 0)
		{
			if (heights[i] != j)
				moveCnt++;
			bucketVec[j]--;
			i++;
		}
	}
	return moveCnt;
}


int main1051()
{
	//vector<int> test = { 1,1,4,2,1,3 };
	//vector<int> test = { 5,1,2,3,4 };
	vector<int> test = { 1,2,3,4,5 };
	int ret = heightChecker(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}