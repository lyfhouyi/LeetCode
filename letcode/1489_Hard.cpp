#include<iostream>
#include<vector>
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


vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
{
	sort(edges.begin(), edges.end(), [&](vector<int>& edgeA, vector<int>& edgeB) {return edgeA[2] < edgeB[2]; });
	return edges;
}


int main()
{
	vector<vector<int>> test = { {0, 1, 1},{1, 2, 1}, {2, 3, 2}, {0, 3, 2},{0, 4, 3},{3, 4, 3},{1, 4, 6} };
	vector<vector<int>> ret = findCriticalAndPseudoCriticalEdges(5, test);
	cout << "main：ret = " << endl;
	vector<int>& criticalEdges = ret[0];
	vector<int>& pseudoCriticalEdges = ret[1];
	cout << "main：关键边：" << endl;
	for (int i = 0; i < criticalEdges.size(); i++)
		cout << criticalEdges[i] << "  ";
	cout << "\nmain：关键边：" << endl;
	for (int i = 0; i < pseudoCriticalEdges.size(); i++)
		cout << pseudoCriticalEdges[i] << "  ";
	return 0;
}