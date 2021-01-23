#include<iostream>
#include<vector>

using namespace std;

//用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n - 1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。
//
//网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。
//
//给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回  - 1 。 
//
//
//提示：
//
//	1 <= n <= 10 ^ 5
//	1 <= connections.length <= min(n*(n - 1) / 2, 10 ^ 5)
//	connections[i].length == 2
//	0 <= connections[i][0], connections[i][1] < n
//	connections[i][0] != connections[i][1]
//	没有重复的连接。
//	两台计算机不会通过多条线缆连接。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-operations-to-make-network-connected
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind1319
{
public:
	UnionFind1319(int n) : fa(vector<int>(n)), domainCnt(n), rank(vector<int>(n)) { init(n); }

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


//遍历边集。找到冗余边，通过初始图中连通域的个数与冗余边的数量关系计算所需的最少操作次数。
//int makeConnected(int n, vector<vector<int>>& connections) 
//{
//	UnionFind1319 unionFind(n);
//	int redundancy = 0;
//	for (vector<vector<int>>::iterator it = connections.begin(); it != connections.end(); it++)
//	{
//		
//		if (unionFind.find(it->at(0)) == unionFind.find(it->at(1)))
//			redundancy++;
//		else
//			unionFind.merge(it->at(0), it->at(1));
//	}
//	if (redundancy < unionFind.getDomainCnt() - 1)
//		return -1;
//	else
//		return unionFind.getDomainCnt() - 1;
//}


//优化版。边数少于节点个数 - 1 时，必不可能使全部计算机连通；否则返回初始图中连通域的个数 - 1 即可。
int makeConnected(int n, vector<vector<int>>& connections)
{
	if (connections.size() < n - 1)
		return -1;
	UnionFind1319 unionFind(n);
	for (vector<vector<int>>::iterator it = connections.begin(); it != connections.end(); it++)
	{
		unionFind.merge(it->at(0), it->at(1)); //只有有效合并时，连通域个数才减一
	}
	return unionFind.getDomainCnt() - 1;
}


int main1319()
{
	vector<vector<int>> test = { {0,1},{0,2},{0,3},{1,2} };
	int ret = makeConnected(6, test);
	cout << "main：ret = " << ret << endl;
	return 0;
}