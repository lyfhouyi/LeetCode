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
int reachNumber(int target)
{
	vector<int> reachableDomain;
	reachableDomain.push_back(0);
	int stepCnt = 1;
	int n;
	while (true)
	{
		n = reachableDomain.size();
		vector<int> reachableDomainNew;
		for (int i = 0; i < n; i++)
		{
			if (reachableDomain[i] + stepCnt == target)
				return stepCnt;
			else
				reachableDomainNew.push_back(reachableDomain[i] + stepCnt);

			if (reachableDomain[i] - stepCnt == target)
				return stepCnt;
			else
				reachableDomainNew.push_back(reachableDomain[i] - stepCnt);
		}
		reachableDomain = reachableDomainNew;
		reachableDomainNew.clear();
		stepCnt++;
	}
	return 0;
}


int main()
{
	int ret = reachNumber(100000);
	cout << "main��ret = " << ret << endl;
	return 0;
}