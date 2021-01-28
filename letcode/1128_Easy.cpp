#include<iostream>
#include<vector>

using namespace std;

//����һ����һЩ����ŵ������ɵ��б� dominoes��
//
//�������ĳһ�Ŷ���ŵ���ƿ���ͨ����ת 0 �Ȼ� 180 �ȵõ���һ�Ŷ���ŵ���ƣ����Ǿ���Ϊ���������ǵȼ۵ġ�
//
//��ʽ�ϣ�dominoes[i] = [a, b] �� dominoes[j] = [c, d] �ȼ۵�ǰ���� a == c �� b == d������ a == d �� b == c��
//
//�� 0 <= i < j < dominoes.length ��ǰ���£��ҳ����� dominoes[i] �� dominoes[j] �ȼ۵Ĺ��ƶ�(i, j) ��������
//
//
//��ʾ��
//
//	1 <= dominoes.length <= 40000
//	1 <= dominoes[i][j] <= 9
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//ʹ�ù���Ͱ��¼�ȼ۵Ĺ���������
//int numEquivDominoPairs(vector<vector<int>>& dominoes) 
//{
//	const int BucketSize = 81;
//	vector<int> dominoBucket(BucketSize);
//	int minPair;
//	int maxPair;
//
//	//װ�����Ͱ
//	for (vector<vector<int>>::iterator it = dominoes.begin(); it != dominoes.end(); it++)
//	{
//		minPair = it->at(0) > it->at(1) ? it->at(1) : it->at(0);
//		maxPair = it->at(0) > it->at(1) ? it->at(0) : it->at(1);
//		dominoBucket[9 * (minPair - 1) + (maxPair - 1)]++;
//	}
//	
//	//����ȼ۹��ƶ�
//	int equivCnt = 0;
//	for (int i = 0; i < BucketSize; i++)
//	{
//		equivCnt += dominoBucket[i] * (dominoBucket[i] - 1) / 2;
//	}
//	return equivCnt;
//}


//�Ż��档
int numEquivDominoPairs(vector<vector<int>>& dominoes)
{
	const int BucketSize = 81;
	vector<int> dominoBucket(BucketSize);

	//װ�����Ͱ��ͬʱ����ȼ۹��ƶ�������
	int equivCnt = 0;
	int index;
	for (vector<vector<int>>::iterator it = dominoes.begin(); it != dominoes.end(); it++)
	{
		index = it->at(0) > it->at(1) ? (9 * (it->at(0) - 1) + it->at(1) - 1) : (9 * (it->at(1) - 1) + it->at(0) - 1);
		equivCnt += dominoBucket[index];
		dominoBucket[index]++;
	}
	return equivCnt;
}

int main1128()
{
	vector<vector<int>> test = { {1,2},{2,2},{2,1},{1,2} ,{1,2} };
	int ret = numEquivDominoPairs(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}