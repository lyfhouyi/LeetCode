#include<iostream>
#include<vector>
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


vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
{
	sort(edges.begin(), edges.end(), [&](vector<int>& edgeA, vector<int>& edgeB) {return edgeA[2] < edgeB[2]; });
	return edges;
}


int main()
{
	vector<vector<int>> test = { {0, 1, 1},{1, 2, 1}, {2, 3, 2}, {0, 3, 2},{0, 4, 3},{3, 4, 3},{1, 4, 6} };
	vector<vector<int>> ret = findCriticalAndPseudoCriticalEdges(5, test);
	cout << "main��ret = " << endl;
	vector<int>& criticalEdges = ret[0];
	vector<int>& pseudoCriticalEdges = ret[1];
	cout << "main���ؼ��ߣ�" << endl;
	for (int i = 0; i < criticalEdges.size(); i++)
		cout << criticalEdges[i] << "  ";
	cout << "\nmain���ؼ��ߣ�" << endl;
	for (int i = 0; i < pseudoCriticalEdges.size(); i++)
		cout << pseudoCriticalEdges[i] << "  ";
	return 0;
}