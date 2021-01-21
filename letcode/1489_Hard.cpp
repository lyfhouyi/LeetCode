#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


//����һ�� n ����Ĵ�Ȩ������ͨͼ���ڵ���Ϊ 0 �� n - 1 ��ͬʱ����һ������ edges ������ edges[i] = [fromi, toi, weighti] ��ʾ�� fromi �� toi �ڵ�֮����һ����Ȩ����ߡ���С������(MST) �Ǹ���ͼ�бߵ�һ���Ӽ��������������нڵ���û�л���������Щ�ߵ�Ȩֵ����С��
//
//�����ҵ�����ͼ����С�����������йؼ��ߺ�α�ؼ��ߡ������ͼ��ɾȥĳ���ߣ��ᵼ����С��������Ȩֵ�����ӣ���ô���Ǿ�˵����һ���ؼ��ߡ�α�ؼ������ǿ��ܻ������ĳЩ��С�������е����������������С�������еıߡ�
//
//��ע�⣬����Էֱ�������˳�򷵻عؼ��ߵ��±��α�ؼ��ߵ��±ꡣ
//
//
//��ʾ��
//
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges[i].length == 3
//	0 <= fromi < toi < n
//	1 <= weighti <= 1000
//	����(fromi, toi) ���Զ��ǻ�����ͬ�ġ�
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class UnionFind1489
{
public:
	UnionFind1489(int n) : fa(vector<int>(n)), rank(vector<int>(n,1)) { init(n); }

	void init(int n) //��ʼ����ÿ��λ��һ�����ϣ�λ���Լ����Լ����ϵĴ���Ԫ��ÿ�����ϵ��ȶ�Ϊ 1��ÿ����ͨ��ı�Ŷ�Ϊ�䱾��
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
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
		if (rank[rootI] < rank[rootJ]) // indexI ���ڵ����̲�
		{

			fa[rootI] = rootJ;
		}
		else
			fa[rootJ] = rootI; // indexJ ���ڵ����̲�
		if (rank[rootI] == rank[rootJ] && rootI != rootJ)
			rank[rootJ]++;

	}
private:
	vector<int>fa; //���ڵ�����
	vector<int>rank; //������
};


//������С��������Ȩ��
int weightOfMST(int n, vector<vector<int>>& edges)
{
	UnionFind1489 unionFind(n);
	int m = edges.size();
	int weight = 0;
	for (int i = 0; i < m; i++)
	{
		if (edges[i][2] < 0) //�ҵ���������ıߣ����У�
		{
			unionFind.merge(edges[i][0], edges[i][1]);
			weight -= edges[i][2];
			edges[i][2] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (0==edges[i][2]) //�ҵ����벻�����ıߣ����У�
			continue;
		if (unionFind.find(edges[i][0]) != unionFind.find(edges[i][1]))
		{
			weight += edges[i][2];
			unionFind.merge(edges[i][0], edges[i][1]);
		}
	}

	//�����ͨ��
	int domain = unionFind.find(0);
	for (int i = 1; i < n; i++)
		if (unionFind.find(i) != domain)
			return INT_MAX;
	return weight;
}


//�����߼���һ���ߣ���1.�����������Ȳ�����������Ȩ�ش�����Ϊ����ȫ�ߣ�2.�����������Ȳ�����������Ȩ��С������Ϊ�ؼ��ߣ�3.�����������벻����������Ȩ����ͬ������Ϊ�ǹؼ��ߡ�
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
{
	int m = edges.size();
	map<pair<int, int>, int>edgeNo;
	for (int i = 0; i < m; i++)
	{
		edgeNo[make_pair(edges[i][0], edges[i][1])] = i;
	}
	sort(edges.begin(), edges.end(), [&](vector<int> edgeA, vector<int> edgeB) {return edgeA[2] < edgeB[2]; }); //�Ա߼�����
	int origin;
	int weightInclude;
	int weightNoInclude;
	vector<int> criticalEdges;
	vector<int> pseudoCriticalEdges;
	for (int i = 0; i < m; i++)
	{
		origin = edges[i][2]; //��ʼȨ��
		edges[i][2] = -edges[i][2]; //��Ϊ������Ȩ��ΪԭʼȨ�ص��෴����
		weightInclude = weightOfMST(n, edges);
		cout << "findCriticalAndPseudoCriticalEdges���ߣ������  " << i << "  weightInclude = " << weightInclude << endl;
		edges[i][2] = 0; //��Ϊ��������Ȩ��Ϊ 0��
		weightNoInclude = weightOfMST(n, edges);
		cout << "findCriticalAndPseudoCriticalEdges���ߣ������  " << i << "  weightNoInclude = " << weightNoInclude << endl;
		if (weightNoInclude == weightInclude)
			pseudoCriticalEdges.push_back(edgeNo.at(make_pair(edges[i][0], edges[i][1])));
		else
			if (weightNoInclude > weightInclude)
				criticalEdges.push_back(edgeNo.at(make_pair(edges[i][0], edges[i][1])));
		edges[i][2] = origin;
	}
	vector<vector<int>> ret(2);
	ret[0] = criticalEdges;
	ret[1] = pseudoCriticalEdges;
	return ret;
}


int main()
{
	//vector<vector<int>> test = { {0, 1, 1},{1, 2, 1}, {2, 3, 2}, {0, 3, 2},{0, 4, 3},{3, 4, 3},{1, 4, 6} };
	//vector<vector<int>> test = { {0, 1, 1},{1, 2, 1}, {2, 3, 1}, {0, 3, 1} };
	vector<vector<int>> test = { {0, 1, 1},{1, 2, 1}, {0, 2, 1}, {2, 3, 4}, {3, 4, 2} , {3, 5, 2} , {4, 5, 2} };
	vector<vector<int>> ret = findCriticalAndPseudoCriticalEdges(6, test);
	cout << "main��ret = " << endl;
	vector<int>& criticalEdges = ret[0];
	vector<int>& pseudoCriticalEdges = ret[1];
	cout << "main���ؼ��ߣ�" << endl;
	for (int i = 0; i < criticalEdges.size(); i++)
		cout << criticalEdges[i] << "  ";
	cout << "\nmain���ǹؼ��ߣ�" << endl;
	for (int i = 0; i < pseudoCriticalEdges.size(); i++)
		cout << pseudoCriticalEdges[i] << "  ";
	return 0;
}