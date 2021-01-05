#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
//
//ע�� :
//
//1.������Ϊ������յ����Ǵ���������㡣
//2.����[1, 2] ��[2, 3] �ı߽��໥���Ӵ�������û���໥�ص�

//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/non-overlapping-intervals
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


bool smallInterval(vector<int>intervalA, vector<int>intervalB)
{
	if (intervalA[0] < intervalB[0])
		return true;
	if (intervalA[0] == intervalB[0])
		return (intervalA[1] < intervalB[1]);
	return false;
}

//�ж� A , B �����ĸ�Ӧ�ñ��Ƴ��� A ���� 1��B ���� 2�������Ƴ����� 0 ��
int which2erase(vector<int>intervalA, vector<int>intervalB)
{
	if (intervalB[0] >= intervalA[1])
		return 0;
	if (intervalB[1] >= intervalA[1])
		return 2;
	return 1;
}


//̰���㷨����������������αȽ������������䣬����Ϊ1��ÿ�αȽ϶������Ƚϵ������������ĸ�Ӧ�ñ��Ƴ����߶������Ƴ���
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
	if (0 == intervals.size())
		return 0;
	sort(intervals.begin(), intervals.end(), smallInterval);
	vector<vector<int>>::iterator it1 = intervals.begin();
	vector<vector<int>>::iterator it2 = intervals.begin() + 1;
	int eraseInterval = -1;
	int eraseCnt = 0;
	while (it2 != intervals.end())
	{
		eraseInterval = which2erase(*it1, *it2);
		switch (eraseInterval)
		{
		case 2:
		{
			cout << "�Ƴ����䣺[" << (*it2)[0] << "," << (*it2)[1] << "]" << endl;
			eraseCnt++;
			*it2 = *it1;
			break;
		}
		case 1:
		{
			cout << "�Ƴ����䣺[" << (*it1)[0] << "," << (*it1)[1] << "]" << endl;
			eraseCnt++;
			break;
		}
		default:
			break;
		}
		it1++;
		it2++;
	}
	return eraseCnt;
}


int main435()
{
	//vector<vector<int>>test = { {1,2},{2,3},{3,4},{1,3} };
	vector<vector<int>>test = {  };
	int ret = eraseOverlapIntervals(test);
	cout << "main��ret=" << ret << endl;
	return 0;
}