#include<iostream>
#include<vector>

using namespace std;

//Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：
//
//类型 1：只能由 Alice 遍历。
//类型 2：只能由 Bob 遍历。
//类型 3：Alice 和 Bob 都可以遍历。
//给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。
//
//返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 - 1 。
//
//
//提示：
//
//	1 <= n <= 10 ^ 5
//	1 <= edges.length <= min(10 ^ 5, 3 * n * (n - 1) / 2)
//	edges[i].length == 3
//	1 <= edges[i][0] <= 3
//	1 <= edges[i][1] < edges[i][2] <= n
//	所有元组(typei, ui, vi) 互不相同
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind1579
{
public:
	UnionFind1579(int n) : fa(vector<int>(n)), domainCnt(n), rank(vector<int>(n)) { init(n); }
	UnionFind1579(UnionFind1579& unionFind) :fa(unionFind.fa), domainCnt(unionFind.domainCnt), rank(unionFind.rank) {}

	void init(int n) //初始化，每个位置一个集合，位置自己是自己集合的代表元，每个集合的秩都为 1
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
			rank[i] = 1;
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
	vector<int>fa; //父节点数组
	vector<int>rank; //秩数组
	int domainCnt;
};


//并查集。优先考察公共边，随后考察 Alice 和 Bob 的独占边。
int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
{
	int m = edges.size();
	int removeCnt = 0;
	UnionFind1579 unionFind(n);

	//使用公共边（类型3）连接节点
	for (int i = 0; i < m; i++)
	{
		if (3 == edges[i][0])
		{
			if (unionFind.find(edges[i][1] - 1) == unionFind.find(edges[i][2] - 1))
				removeCnt++;
			else
				unionFind.merge(edges[i][1] - 1, edges[i][2] - 1);
		}
	}

	if (1 == unionFind.getDomainCnt())
	{
		//cout << "maxNumEdgesToRemove：公共边全连通" << endl;
		return m - n + 1; //理想情况下，只需 n - 1 条公共边即可实现全图连通
	}

	UnionFind1579 unionFind_duplicate(unionFind);

	//使用 Alice 的边连通 Alice 的域
	for (int i = 0; i < m; i++)
	{
		if (1 == edges[i][0])
		{
			if (unionFind.find(edges[i][1] - 1) == unionFind.find(edges[i][2] - 1))
				removeCnt++;
			else
				unionFind.merge(edges[i][1] - 1, edges[i][2] - 1);
		}
	}

	if (1 != unionFind.getDomainCnt())
	{
		//cout << "maxNumEdgesToRemove：Alice 无法连通" << endl;
		return -1;
	}

	//使用 Bob 的边连通 Bob 的域
	for (int i = 0; i < m; i++)
	{
		if (2 == edges[i][0])
		{
			if (unionFind_duplicate.find(edges[i][1] - 1) == unionFind_duplicate.find(edges[i][2] - 1))
				removeCnt++;
			else
				unionFind_duplicate.merge(edges[i][1] - 1, edges[i][2] - 1);
		}
	}

	if (1 != unionFind_duplicate.getDomainCnt())
	{
		//cout << "maxNumEdgesToRemove：Bob 无法连通" << endl;
		return -1;
	}

	//cout << "maxNumEdgesToRemove：删除完毕" << endl;
	return removeCnt;
}


int main1579()
{
	//vector<vector<int>> test = { {3, 1, 2},{3, 2, 3},{1, 1, 3},{1, 2, 4},{1, 1, 2},{2, 3, 4} };
	vector<vector<int>> test = { {3, 2, 3},{1, 1, 2},{2, 3, 4} };
	//vector<vector<int>> test = { {3, 1, 2},{3, 2, 3},{1, 1, 4},{2, 1, 4} };
	//vector<vector<int>> test = { {3, 2, 3},{1, 1, 2},{2, 3, 4} };
	int ret = maxNumEdgesToRemove(4, test);
	cout << "main：ret = " << ret << endl;
	return 0;
}