#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
//
//连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ： | xi - xj | +| yi - yj | ，其中  | val | 表示 val 的绝对值。
//
//请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
//
//
//提示：
//
//	1 <= points.length <= 1000
//	- 106 <= xi, yi <= 106
//	所有点 (xi, yi) 两两不同。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/min-cost-to-connect-all-points
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind1584
{
public:
	UnionFind1584(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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
		if (rank[rootI] < rank[rootJ])
			fa[rootI] = rootJ;
		else
			fa[rootJ] = rootI;
		if (rank[rootI] == rank[rootJ] && rootI != rootJ)
			rank[rootJ]++;

	}
private:
	vector<int>fa; //父节点数组
	vector<int>rank; //秩数组
};


int calcDistance(vector<int>& pointA, vector<int>& pointB)
{
	return abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
}


//最小生成树 kruskal 算法，使用并查集。首先遍历 points 数组，计算全部候选边的边长并存入边集（边的优先级队列）；随后遍历边的优先级队列（每次取出的都是当前边集中边长最小的那条边），若该边连接的顶点不在同一个连通域中，则该边应该被选取（产生费用），否则不选取该边（不产生费用）。
int minCostConnectPoints(vector<vector<int>>& points)
{
	int n = points.size();
	UnionFind1584 unionFind(points.size());
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> edgeQueue; //边的优先级队列，元素为：<边长,<顶点 A 的索引,顶点 B 的索引>>
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			edgeQueue.push(make_pair(calcDistance(points[i], points[j]), make_pair(i, j)));
	pair<int, pair<int, int>>element;
	int cost = 0;
	while (!edgeQueue.empty())
	{
		element = edgeQueue.top();
		edgeQueue.pop();
		if (unionFind.find(element.second.first) != unionFind.find(element.second.second))
		{
			cost += element.first;
			unionFind.merge(element.second.first, element.second.second);
		}
	}
	return cost;
}


int main()
{
	//vector<vector<int>> test = { {0, 0} ,{2,2},{3,10},{5,2},{7,0} };
	//vector<vector<int>> test = { {3, 12} ,{-2,5},{-4,1} };
	//vector<vector<int>> test = { {-1000000, -1000000} ,{1000000, 1000000} };
	vector<vector<int>> test = { {0, 0} };
	int ret = minCostConnectPoints(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}