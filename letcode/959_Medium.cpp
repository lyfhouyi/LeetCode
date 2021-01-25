#include<iostream>
#include<vector>
#include<string>

using namespace std;

//在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 / 、\ 或空格构成。这些字符会将方块划分为一些共边的区域。
//
//（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。
//
//返回区域的数目。
//
//
//提示：
//
//	1 <= grid.length == grid[0].length <= 30
//	grid[i][j] 是 '/'、'\'、或 ' '。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/regions-cut-by-slashes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind959
{
public:
	UnionFind959(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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


//并查集。使用边将顶点连通，则划分的区域数 = Σ(顶点个数大于 2 的代表元) 代表元中顶点间的边数 - 代表元中顶点的个数 + 1 ，即图中各连通域的的冗余的边数之和。
int regionsBySlashes(vector<string>& grid)
{
	int n = grid.size();
	UnionFind959 unionFind((n + 1)*(n + 1)); // n * n 的网格有 (n + 1)*(n + 1) 个顶点

	//根据边集合并顶点
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || i == n || j == 0 || j == n)
				unionFind.merge(0, i*(n + 1) + j); //合并边缘顶点
			if (i != n && j != n && grid[i][j] != ' ') //合并内部顶点
			{
				if (grid[i][j] == '\\')
					unionFind.merge(i*(n + 1) + j, (i + 1)*(n + 1) + (j + 1)); //合并顶点 (i, j) 与 (i + 1, j + 1)
				else
					unionFind.merge((i + 1)*(n + 1) + j, i*(n + 1) + (j + 1)); //合并顶点 (i + 1, j) 与 (i, j + 1)
			}
		}
	}

	//根据合并后的图，计算共边区域个数
	vector<int> connectedCnt((n + 1)*(n + 1),0); //各代表元中顶点的个数
	vector<int> edgeCnt((n + 1)*(n + 1),0); //各代表元中连接顶点的边的个数
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			connectedCnt[unionFind.find(i*(n + 1) + j)]++; //更新代表元中顶点的个数

			if (i != n && j != n && grid[i][j] != ' ') //更新代表元中连接顶点的边的个数
			{
				if (grid[i][j] == '\\')
					edgeCnt[unionFind.find(i*(n + 1) + j)]++;
				else
					edgeCnt[unionFind.find((i + 1)*(n + 1) + j)]++;
			}
		}
	}
	edgeCnt[unionFind.find(0)] += 4 * n; //考察图边缘的边
	
	//计算共边区域的个数
	int areaCnt = 0;
	for (int i = 0; i < (n + 1)*(n + 1); i++)
	{
		if (connectedCnt[i] > 2)
			areaCnt += edgeCnt[i] - connectedCnt[i] + 1;
	}
	return areaCnt;
}


int main959()
{
	vector<string> test = { " /", "/ " };
	//vector<string> test = { "/\\/\\", "\\///", " \\//", "////" };
	//vector<string> test = { "\\//\\/\\//\\", "\\  /\\/ //", "//\\/ /\\\\ ", "\\\\\\//\\///", "\\//// ///", "\\   / \\\\\\", "\\ /\\ /\\/\\", "/\\\\//  \\/", " ///\\/\\\\/" };
	int ret = regionsBySlashes(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}