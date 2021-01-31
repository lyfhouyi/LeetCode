#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

//在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置(i, j) 的平台高度。
//
//现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
//
//你从坐标方格的左上平台(0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N - 1, N - 1)？
//
//
//提示 :
//
//	2 <= N <= 50.
//	grid[i][j] 是[0, ..., N*N - 1] 的排列。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/swim-in-rising-water
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind778
{
public:
	UnionFind778(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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
	}
private:
	vector<int>fa; //父节点数组
	vector<int>rank; //秩数组
};


//并查集。首先构造边集（优先级队列，按所需水位由低至高排序）；随后依次取出所需水位最低的边，连通该边的两顶点；直到左上角和右下角的顶点连通。
int swimInWater(vector<vector<int>>& grid)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pathSet;
	int n = grid.size();

	//构造边集
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != n - 1) //右边
				pathSet.push(make_pair(max(grid[i][j],grid[i][j + 1]), make_pair(i*n + j, i*n + j + 1)));
			if (i != n - 1) //下边
				pathSet.push(make_pair(max(grid[i][j],grid[i + 1][j]), make_pair(i*n + j, i*n + j + n)));
		}
	}

	//计算最小体力消耗值
	UnionFind778 unionFind(n*n);
	int minLevel = 0;
	int  dest = n * n - 1;
	pair<int, pair<int, int>> currentPath;
	while (unionFind.find(0) != unionFind.find(dest))
	{
		currentPath = pathSet.top();
		pathSet.pop();
		minLevel = currentPath.first;
		unionFind.merge(currentPath.second.first, currentPath.second.second);
	}
	return minLevel;
}


int main778()
{
	vector<vector<int>> test = { {0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6} };
	int ret = swimInWater(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}