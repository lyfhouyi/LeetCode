#include<iostream>
#include<vector>

using namespace std;

//N �����������������е� 2N ����λ�ϣ���Ҫǣ���Է����֡� �������ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ�� һ�ν�����ѡ���������ˣ�������վ����������λ��
//
//�˺���λ�� 0 �� 2N - 1 ��������ʾ�������ǰ�˳���ţ���һ����(0, 1)���ڶ�����(2, 3)���Դ����ƣ����һ����(2N - 2, 2N - 1)��
//
//��Щ���µĳ�ʼ��λ  row[i] �������ʼ���ڵ� i ����λ�ϵ��˾����ġ�
//
//
//˵�� :
//
//	len(row) ��ż������ֵ��[4, 60]��Χ�ڡ�
//	���Ա�֤row ������ 0...len(row) - 1 ��һ��ȫ���С�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/couples-holding-hands
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class UnionFind765
{
public:
	UnionFind765(int n) : fa(vector<int>(n)), rank(vector<int>(n)), domainCnt(n) { init(n); }

	void init(int n) //��ʼ����ÿ��λ��һ�����ϣ�λ���Լ����Լ����ϵĴ���Ԫ��ÿ�����ϵ��ȶ�Ϊ 1
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
			rank[i] = 1;
		}

	}

	int find(int index) //���ң�·��ѹ�������ҵ�λ�� index ���ڼ��ϵĴ���Ԫ
	{
		if (index == fa[index])
			return index;
		else
		{
			fa[index] = find(fa[index]);
			return fa[index];
		}
	}

	void merge(int indexI, int indexJ) //�ϲ������Ⱥϲ���
	{
		int rootI = find(indexI);
		int rootJ = find(indexJ);
		if (rootI == rootJ)
			return;
		if (rank[rootI] < rank[rootJ])
			fa[rootI] = rootJ;
		else
			fa[rootJ] = rootI;
		if (rank[rootI] == rank[rootJ])
			rank[rootJ]++;
		domainCnt--;
	}

	int getDomainCnt()
	{
		return domainCnt;
	}
private:
	vector<int>fa; //���ڵ�����
	vector<int>rank; //������
	int domainCnt;
};


//�ⷨһ�������ⷨ����ָ��������飻���μ�鲢��λ��ǰλ�õ�����У�Ů�����ѣ�ÿ�μ����Ϻ�����������λ�������ϣ����ָ��ÿ���ƶ�����λ�á�
//int minSwapsCouples(vector<int>& row)
//{
//	int n = row.size();
//	int dest;
//	int j;
//	int swapCnt = 0;
//	for (int i = 0; i < n-1; i+=2)
//	{
//		dest = row[i] % 2 == 1 ? row[i] - 1 : row[i] + 1;
//		j = i + 1;
//		while (row[j] != dest)
//			j++;
//		if (j == i + 1)
//			continue;
//		swap(row[j], row[i + 1]);
//		swapCnt++;
//	}
//	return swapCnt;
//}


//�ⷨ�������鼯����ʼʱÿ��������һ����������ͨ������ʹ�ü��ָ��������飨����Ϊ 2 ����ÿ�ν����ڵ���������������ͨ�����ϲ���������Ϻ������¶�����ȥ��ͨ��������Ϊ������Ҫ�����Ĵ�����
int minSwapsCouples(vector<int>& row)
{
	int n = row.size();
	UnionFind765 unionFind(n / 2);
	for (int i = 0; i < n - 1; i += 2)
	{
		unionFind.merge(row[i] / 2, row[i + 1] / 2);
	}
	return n / 2 - unionFind.getDomainCnt();
}


int main765()
{
	vector<int> test = { 0,2,3,4,5,6,7,1 };
	//vector<int> test = { 0, 2, 1, 3 };
	int ret = minSwapsCouples(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}