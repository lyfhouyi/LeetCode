#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


//给你一个 n 个点的带权无向连通图，节点编号为 0 到 n - 1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树(MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。
//
//请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。
//
//请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。
//
//
//提示：
//
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges[i].length == 3
//	0 <= fromi < toi < n
//	1 <= weighti <= 1000
//	所有(fromi, toi) 数对都是互不相同的。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind1489
{
public:
	UnionFind1489(int n) : fa(vector<int>(n)), rank(vector<int>(n,1)) { init(n); }

	void init(int n) //初始化，每个位置一个集合，位置自己是自己集合的代表元，每个集合的秩都为 1，每个连通域的编号都为其本身。
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
		}

	}

	int find(int index) //查找（路径压缩），找到位置 index 所在集合的代表元
	{
		if (index == fa[index])
			return index;
		else
		{
			fa[index] = find(fa[index]);
			return fa[index];
		}
	}

	void merge(int indexI, int indexJ) //合并（按秩合并）
	{
		int rootI = find(indexI);
		int rootJ = find(indexJ);
		if (rank[rootI] < rank[rootJ]) // indexI 所在的域被吞并
		{

			fa[rootI] = rootJ;
		}
		else
			fa[rootJ] = rootI; // indexJ 所在的域被吞并
		if (rank[rootI] == rank[rootJ] && rootI != rootJ)
			rank[rootJ]++;

	}
private:
	vector<int>fa; //父节点数组
	vector<int>rank; //秩数组
};


//计算最小生成树的权重
int weightOfMST(int n, vector<vector<int>>& edges)
{
	UnionFind1489 unionFind(n);
	int m = edges.size();
	int weight = 0;
	for (int i = 0; i < m; i++)
	{
		if (edges[i][2] < 0) //找到必须包含的边（若有）
		{
			unionFind.merge(edges[i][0], edges[i][1]);
			weight -= edges[i][2];
			edges[i][2] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (0==edges[i][2]) //找到必须不包含的边（必有）
			continue;
		if (unionFind.find(edges[i][0]) != unionFind.find(edges[i][1]))
		{
			weight += edges[i][2];
			unionFind.merge(edges[i][0], edges[i][1]);
		}
	}

	//检查连通性
	int domain = unionFind.find(0);
	for (int i = 1; i < n; i++)
		if (unionFind.find(i) != domain)
			return INT_MAX;
	return weight;
}


//遍历边集。一条边，若1.包含它的树比不包含它的树权重大，则它为不安全边；2.包含它的树比不包含它的树权重小，则它为关键边；3.包含它的树与不包含它的树权重相同，则它为非关键边。
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
{
	int m = edges.size();
	map<pair<int, int>, int>edgeNo;
	for (int i = 0; i < m; i++)
	{
		edgeNo[make_pair(edges[i][0], edges[i][1])] = i;
	}
	sort(edges.begin(), edges.end(), [&](vector<int> edgeA, vector<int> edgeB) {return edgeA[2] < edgeB[2]; }); //对边集排序
	int origin;
	int weightInclude;
	int weightNoInclude;
	vector<int> criticalEdges;
	vector<int> pseudoCriticalEdges;
	for (int i = 0; i < m; i++)
	{
		origin = edges[i][2]; //初始权重
		edges[i][2] = -edges[i][2]; //设为包含（权重为原始权重的相反数）
		weightInclude = weightOfMST(n, edges);
		cout << "findCriticalAndPseudoCriticalEdges：边（排序后）  " << i << "  weightInclude = " << weightInclude << endl;
		edges[i][2] = 0; //设为不包含（权重为 0）
		weightNoInclude = weightOfMST(n, edges);
		cout << "findCriticalAndPseudoCriticalEdges：边（排序后）  " << i << "  weightNoInclude = " << weightNoInclude << endl;
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
	cout << "main：ret = " << endl;
	vector<int>& criticalEdges = ret[0];
	vector<int>& pseudoCriticalEdges = ret[1];
	cout << "main：关键边：" << endl;
	for (int i = 0; i < criticalEdges.size(); i++)
		cout << criticalEdges[i] << "  ";
	cout << "\nmain：非关键边：" << endl;
	for (int i = 0; i < pseudoCriticalEdges.size(); i++)
		cout << pseudoCriticalEdges[i] << "  ";
	return 0;
}