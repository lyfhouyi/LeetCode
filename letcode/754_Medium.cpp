#include<iostream>
#include<vector>

using namespace std;

//��һ�����޳��������ϣ���վ��0��λ�á��յ���target��λ�á�
//
//ÿ�������ѡ������������ƶ����� n ���ƶ����� 1 ��ʼ���������� n ����
//
//���ص����յ���Ҫ����С�ƶ�������
//
//
//ע�� :
//
//	target����[-10 ^ 9, 10 ^ 9]��Χ�еķ���������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/reach-a-number
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//�����ⷨ��ö�����пɴ�⣬ֱ���ҵ�Ŀ��ֵ��
//�㷨��ȷ����ʱ�䳬ʱ��
//int reachNumber(int target)
//{
//	vector<int> reachableDomain(1,0);
//	int stepCnt = 1;
//	int n;
//	while (true)
//	{
//		n = reachableDomain.size();
//		vector<int> reachableDomainNew;
//		for (int i = 0; i < n; i++)
//		{
//			if (reachableDomain[i] + stepCnt == target)
//				return stepCnt;
//			else
//				reachableDomainNew.push_back(reachableDomain[i] + stepCnt);
//
//			if (reachableDomain[i] - stepCnt == target)
//				return stepCnt;
//			else
//				reachableDomainNew.push_back(reachableDomain[i] - stepCnt);
//		}
//		reachableDomain = reachableDomainNew;
//		reachableDomainNew.clear();
//		stepCnt++;
//	}
//	return 0;
//}


//�ⷨһ����ѧ�����������ҵ��ۼӺ��㹻��� k ������ж��ۼӺ���Ŀ��ֵ�Ĳ����ż�ԣ����ۼӺ���Ŀ��ֵ֮��Ϊż��ʱ��ֻ�轫 k �е�ĳ��ֵȡ�����ɣ����ۼӺ���Ŀ��ֵ֮��Ϊ����ʱ����ȡ�� k + 1 �� k + 2 ʹĿ�ۼӺ���Ŀ��ֵ֮��Ϊż���������ۼӺ��е�ĳ��ֵȡ�����ɡ�����֤�������ۼӺ���Ŀ��ֵ֮��Ϊż��ʱ��������һ������ĳ���ۼӺ�Ԫ�أ�����ȡ��ʱ���ԴﵽĿ��ֵ���Ҵ�ʱ�������١�
//int reachNumber(int target)
//{
//	target = target > 0 ? target : -target;
//	int s = 0;
//	int k = 0;
//	while (s < target)
//	{
//		k++;
//		s += k;
//	}
//	int delta = s - target;
//	int ret = k + delta % 2;
//	if (delta % 2 == 1 && k % 2 == 1)
//		ret++;
//	return ret;
//}


//�ⷨ������ѧ����������ۼ��ۼӺͣ�ֱ���ۼӺʹ��ڻ����Ŀ��ֵ�����ۼӺ���Ŀ��ֵ֮��Ϊż��Ϊֹ����ʱֻ�轫�ۼӺ���Ŀ��ֵ֮���һ����Ǹ��ۼӺ���ȡ�����ɵõ�Ŀ��ֵ������֤������ʱ�Ĳ������١�
int reachNumber(int target)
{
	target = target > 0 ? target : -target;
	int s = 0;
	int k = 0;
	while (s < target || (s - target) % 2 == 1)
	{
		k++;
		s += k;
	}
	return k;
}


int main754()
{
	int ret = reachNumber(100000);
	cout << "main��ret = " << ret << endl;
	return 0;
}