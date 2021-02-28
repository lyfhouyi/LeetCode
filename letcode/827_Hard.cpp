#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。
//
//进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）
//
//
//说明 :
//
//	1 <= grid.length = grid[0].length <= 50
//	0 <= grid[i][j] <= 1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/making-a-large-island
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind827
{
public:
	UnionFind827(int n) : fa(vector<int>(n)), rank(vector<int>(n)), cnt(vector<int>(n)), maxCnt(1) { init(n); }

	void init(int n) //初始化，每个位置一个集合，位置自己是自己集合的代表元，每个集合的秩都为 1
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
			rank[i] = 1;
			cnt[i] = 1;
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
		{
			cnt[rootJ] = cnt[rootI] + cnt[rootJ];
			maxCnt = maxCnt > cnt[rootJ] ? maxCnt : cnt[rootJ];
			fa[rootI] = rootJ;
		}
		else
		{
			cnt[rootI] = cnt[rootI] + cnt[rootJ];
			maxCnt = maxCnt > cnt[rootI] ? maxCnt : cnt[rootI];
			fa[rootJ] = rootI;
		}
		if (rank[rootI] == rank[rootJ])
			rank[rootJ]++;
	}

	int getCnt(int index) //返回所属域的成员数量
	{
		return cnt[find(index)];
	}

	int getMaxCnt() //返回域成员数量的最大值
	{
		return maxCnt;
	}

private:
	vector<int>fa; //父节点数组
	vector<int>rank; //秩数组
	vector<int>cnt; //所属域中的成员数量
	int maxCnt; //域成员数量的最大值
};


//并查集。使用并查集计算初始时地图上的岛屿情况；遍历每一个海洋位置，找到所有位置中四周的岛屿面积之和的最大值即为所求。
int largestIsland(vector<vector<int>>& grid)
{
	int n = grid.size();
	UnionFind827 unionFind(n*n); //初始时地图上每个位置均为一个独立集合。
	for (int i = 0; i < n; i++) //计算初始时的岛屿情况
	{
		for (int j = 0; j < n; j++)
		{
			if (0 == grid[i][j])
				continue;
			if (j != n - 1 && grid[i][j + 1] != 0) //合并右方岛屿
				unionFind.merge(i*n + j, i*n + j + 1);
			if (i != n - 1 && grid[i + 1][j] != 0) //合并下方岛屿
				unionFind.merge(i*n + j, (i + 1)*n + j);
		}
	}

	int maxCnt = unionFind.getMaxCnt();
	int tmpCnt;
	unordered_set<int> domainSet;
	//遍历各海洋位置，计算将其填为陆地时，包含该位置的岛屿面积
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (1 == grid[i][j])
				continue;
			tmpCnt = 1;
			domainSet.clear();
			if (i != 0 && grid[i - 1][j] != 0) //合并上方岛屿
				domainSet.insert(unionFind.find((i - 1)*n + j));
			if (i != n - 1 && grid[i + 1][j] != 0) //合并下方岛屿
				domainSet.insert(unionFind.find((i + 1)*n + j));
			if (j != 0 && grid[i][j - 1] != 0) //合并左方岛屿
				domainSet.insert(unionFind.find(i*n + j - 1));
			if (j != n - 1 && grid[i][j + 1] != 0) //合并右方岛屿
				domainSet.insert(unionFind.find(i*n + j + 1));

			for (unordered_set<int>::iterator it = domainSet.begin(); it != domainSet.end(); it++) //计算包含填海位置的岛屿面积
				tmpCnt += unionFind.getCnt(*it);
			maxCnt = maxCnt > tmpCnt ? maxCnt : tmpCnt;
		}
	}
	return maxCnt;
}


int main827()
{
	vector<vector<int>> test = { {1, 1},{1, 0} };
	//vector<vector<int>> test = { {1} };
	//vector<vector<int>> test = { {1,0,0,1,1,1,0,1},{0,1,0,1,1,0,0,1},{0,0,0,1,1,0,0,1},{0,1,1,0,0,0,1,0},{1,0,0,1,0,0,1,0},{0,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0},{1,0,1,1,0,0,1,1} };
	int ret = largestIsland(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}