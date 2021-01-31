#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

//你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows - 1, columns - 1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
//
//一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
//
//请你返回从左上角走到右下角的最小体力消耗值。
//
//
//提示：
//
//	rows == heights.length
//	columns == heights[i].length
//	1 <= rows, columns <= 100
//	1 <= heights[i][j] <= 10^6
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/path-with-minimum-effort
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind1631
{
public:
	UnionFind1631(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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


//并查集。首先构造边集（优先级队列，按体力消耗由低至高排序）；随后依次取出体力消耗最小的边，连通该边的两顶点；直到左上角和右下角的顶点连通。
int minimumEffortPath(vector<vector<int>>& heights)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pathSet;
	int rows = heights.size();
	int cols = heights[0].size();

	//构造边集
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j != cols - 1) //右边
				pathSet.push(make_pair(abs(heights[i][j] - heights[i][j + 1]), make_pair(i*cols + j, i*cols + j + 1)));
			if (i != rows - 1) //下边
				pathSet.push(make_pair(abs(heights[i][j] - heights[i + 1][j]), make_pair(i*cols + j, i*cols + j + cols)));
		}
	}

	//计算最小体力消耗值
	UnionFind1631 unionFind(rows*cols);
	int minEffort = 0;
	int  dest = rows * cols - 1;
	pair<int, pair<int, int>> currentPath;
	while (unionFind.find(0) != unionFind.find(dest))
	{
		currentPath = pathSet.top();
		pathSet.pop();
		minEffort = currentPath.first;
		unionFind.merge(currentPath.second.first, currentPath.second.second);
	}
	return minEffort;
}



int main1631()
{
	//vector<vector<int>> test = { {1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1} };
	vector<vector<int>> test = { {1, 10, 6, 7, 9, 10, 4, 9}};
	int ret = minimumEffortPath(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}