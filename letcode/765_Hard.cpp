#include<iostream>
#include<vector>

using namespace std;

//N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。
//
//人和座位用 0 到 2N - 1 的整数表示，情侣们按顺序编号，第一对是(0, 1)，第二对是(2, 3)，以此类推，最后一对是(2N - 2, 2N - 1)。
//
//这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。
//
//
//说明 :
//
//	len(row) 是偶数且数值在[4, 60]范围内。
//	可以保证row 是序列 0...len(row) - 1 的一个全排列。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/couples-holding-hands
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind765
{
public:
	UnionFind765(int n) : fa(vector<int>(n)), rank(vector<int>(n)), domainCnt(n) { init(n); }

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


//解法一：暴力解法。单指针遍历数组；依次检查并归位当前位置的配对男（女）朋友；每次检查完毕后连续的两个位置配对完毕；检查指针每次移动两个位置。
//int minSwapsCouples(vector<int>& row)
//{
//	int n = row.size();
//	int dest;
//	int j;
//	int swapCnt = 0;
//	for (int i = 0; i < n-1; i+=2)
//	{
//		dest = row[i] % 2 == 1 ? row[i] - 1 : row[i] + 1;
//		j = i + 1;
//		while (row[j] != dest)
//			j++;
//		if (j == i + 1)
//			continue;
//		swap(row[j], row[i + 1]);
//		swapCnt++;
//	}
//	return swapCnt;
//}


//解法二：并查集。初始时每对情侣是一个单独的连通分量；使用检查指针遍历数组（步长为 2 ），每次将相邻的两个人所属的连通分量合并；遍历完毕后，总情侣对数减去连通分量数即为最少需要交换的次数。
int minSwapsCouples(vector<int>& row)
{
	int n = row.size();
	UnionFind765 unionFind(n / 2);
	for (int i = 0; i < n - 1; i += 2)
	{
		unionFind.merge(row[i] / 2, row[i + 1] / 2);
	}
	return n / 2 - unionFind.getDomainCnt();
}


int main765()
{
	vector<int> test = { 0,2,3,4,5,6,7,1 };
	//vector<int> test = { 0, 2, 1, 3 };
	int ret = minSwapsCouples(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}