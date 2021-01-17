#include<iostream>
#include<vector>
#include<map>

using namespace std;

//n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。
//
//如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。
//
//给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子 的最大数量。
//
//
//提示：
//
//	1 <= stones.length <= 1000
//	0 <= xi, yi <= 104
//	不会有两块石头放在同一个坐标点上
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind947
{
public:
	UnionFind947(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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

	void merge(int indexI, int indexJ) //合并（按秩合并），indexI 所在域吞并 indexJ 所在域，合并后，域的代表元为原 indexI 所在域的代表元
	{
		int rootI = find(indexI);
		int rootJ = find(indexJ);
		if (rank[rootI] < rank[rootJ]) //严格小于以确保合并后，域的代表元为原 indexI 所在域的代表元
			fa[rootI] = rootJ;
		else
			fa[rootJ] = rootI;
		if (rank[rootI] == rank[rootJ] && rootI != rootJ)
			rank[rootJ]++;

	}

	int setCount() //计算并查集中不相交集合的个数
	{
		int n = fa.size();
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (fa[i] == i) //只需判断 fa[i] 是否等于 i 即可，与用 find(i) 判断是等价的
				cnt++;
		return cnt;
	}
private:
	vector<int>fa; //父节点数组
	vector<int>rank; //秩数组
};


//并查集。将石头划分为各个连通域，则每个连通域只需保留一块石头，其他的石头都可移除。理论依据：任意行或任意列只可能属于一个连通域
int removeStones(vector<vector<int>>& stones)
{
	map<int, int>rows2domain; //行-域中某元素的映射关系（映射到域中任意元素都是等效的）
	map<int, int>cols2domain; //列-域中某元素的映射关系（映射到域中任意元素都是等效的）
	map<int, int>::iterator itRow;
	map<int, int>::iterator itCol;
	int n = stones.size();
	int tmp;
	UnionFind947 unionFind(n);
	
	//将石头划分到各个连通域
	for (int i = 0; i < n; i++)
	{
		if (rows2domain.end() == (itRow=rows2domain.find(stones[i][0])) && cols2domain.end() == (itCol=cols2domain.find(stones[i][1])))
		{
			rows2domain[stones[i][0]] = i;
			cols2domain[stones[i][1]] = i;
		}
		else
		{
			if (rows2domain.end() != itRow)
			{
				unionFind.merge(itRow->second, i);
				if (cols2domain.find(stones[i][1]) != cols2domain.end() && ((tmp=cols2domain.at(stones[i][1])) != itRow->second))
				{
					unionFind.merge(i, tmp);
				}
				cols2domain[stones[i][1]] = unionFind.find(itRow->second);
			}
			else
			{
				unionFind.merge(itCol->second, i);
				rows2domain[stones[i][0]] = unionFind.find(itCol->second);
			}
		}
	}

	//计算连通域的个数并返回差值
	return n - unionFind.setCount();
}

int main947()
{
	vector<vector<int>> test = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
	//vector<vector<int>> test = { {0,0},{0,2},{1,1},{2,0},{2,2} };
	//vector<vector<int>> test = { {0,0} };
	int ret = removeStones(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}