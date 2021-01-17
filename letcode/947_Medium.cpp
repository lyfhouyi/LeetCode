#include<iostream>
#include<vector>
#include<map>

using namespace std;

//n ��ʯͷ�����ڶ�άƽ���е�һЩ����������ϡ�ÿ������������ֻ����һ��ʯͷ��
//
//���һ��ʯͷ�� ͬ�л���ͬ�� ��������ʯͷ���ڣ���ô�Ϳ����Ƴ����ʯͷ��
//
//����һ������Ϊ n ������ stones ������ stones[i] = [xi, yi] ��ʾ�� i ��ʯͷ��λ�ã����� �����Ƴ���ʯ�� �����������
//
//
//��ʾ��
//
//	1 <= stones.length <= 1000
//	0 <= xi, yi <= 104
//	����������ʯͷ����ͬһ���������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class UnionFind947
{
public:
	UnionFind947(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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

	void merge(int indexI, int indexJ) //�ϲ������Ⱥϲ�����indexI �������̲� indexJ �����򣬺ϲ�����Ĵ���ԪΪԭ indexI ������Ĵ���Ԫ
	{
		int rootI = find(indexI);
		int rootJ = find(indexJ);
		if (rank[rootI] < rank[rootJ]) //�ϸ�С����ȷ���ϲ�����Ĵ���ԪΪԭ indexI ������Ĵ���Ԫ
			fa[rootI] = rootJ;
		else
			fa[rootJ] = rootI;
		if (rank[rootI] == rank[rootJ] && rootI != rootJ)
			rank[rootJ]++;

	}

	int setCount() //���㲢�鼯�в��ཻ���ϵĸ���
	{
		int n = fa.size();
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (fa[i] == i) //ֻ���ж� fa[i] �Ƿ���� i ���ɣ����� find(i) �ж��ǵȼ۵�
				cnt++;
		return cnt;
	}
private:
	vector<int>fa; //���ڵ�����
	vector<int>rank; //������
};


//���鼯����ʯͷ����Ϊ������ͨ����ÿ����ͨ��ֻ�豣��һ��ʯͷ��������ʯͷ�����Ƴ����������ݣ������л�������ֻ��������һ����ͨ��
int removeStones(vector<vector<int>>& stones)
{
	map<int, int>rows2domain; //��-����ĳԪ�ص�ӳ���ϵ��ӳ�䵽��������Ԫ�ض��ǵ�Ч�ģ�
	map<int, int>cols2domain; //��-����ĳԪ�ص�ӳ���ϵ��ӳ�䵽��������Ԫ�ض��ǵ�Ч�ģ�
	map<int, int>::iterator itRow;
	map<int, int>::iterator itCol;
	int n = stones.size();
	int tmp;
	UnionFind947 unionFind(n);
	
	//��ʯͷ���ֵ�������ͨ��
	for (int i = 0; i < n; i++)
	{
		if (rows2domain.end() == (itRow=rows2domain.find(stones[i][0])) && cols2domain.end() == (itCol=cols2domain.find(stones[i][1])))
		{
			rows2domain[stones[i][0]] = i;
			cols2domain[stones[i][1]] = i;
		}
		else
		{
			if (rows2domain.end() != itRow)
			{
				unionFind.merge(itRow->second, i);
				if (cols2domain.find(stones[i][1]) != cols2domain.end() && ((tmp=cols2domain.at(stones[i][1])) != itRow->second))
				{
					unionFind.merge(i, tmp);
				}
				cols2domain[stones[i][1]] = unionFind.find(itRow->second);
			}
			else
			{
				unionFind.merge(itCol->second, i);
				rows2domain[stones[i][0]] = unionFind.find(itCol->second);
			}
		}
	}

	//������ͨ��ĸ��������ز�ֵ
	return n - unionFind.setCount();
}

int main947()
{
	vector<vector<int>> test = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
	//vector<vector<int>> test = { {0,0},{0,2},{1,1},{2,0},{2,2} };
	//vector<vector<int>> test = { {0,0} };
	int ret = removeStones(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}