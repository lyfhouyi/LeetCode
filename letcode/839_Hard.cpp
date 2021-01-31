#include<iostream>
#include<vector>
#include<string>

using namespace std;

//如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
//
//例如，"tars" 和 "rats" 是相似的(交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。
//
//总之，它们通过相似性形成了两个关联组：{ "tars", "rats", "arts" } 和{ "star" }。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
//
//给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。请问 strs 中有多少个相似字符串组？
//
//
//提示：
//
//	1 <= strs.length <= 100
//	1 <= strs[i].length <= 1000
//	sum(strs[i].length) <= 2 * 104
//	strs[i] 只包含小写字母。
//	strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。
//
//
//备注：
//
//	字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/similar-string-groups
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind839
{
public:
	UnionFind839(int n) : fa(vector<int>(n)), rank(vector<int>(n)), domainCnt(n){ init(n); }

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


//判断两个字符串是否相似。相似返回 true ；不相似返回 false 。由于 s1 、s2 具有相同的长度，且是彼此的字母异位词，因此只有当 s1 、s2 同位置字符不同的个数为 0 或 2 时，它们才是相似的。
bool isSimilar(string& s1, string& s2)
{
	int n = s1.length();
	int diffCnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			diffCnt++;
		if (diffCnt > 2)
			return false;
	}
	if (1 == diffCnt)
		return false;
	return true;
}

//并查集。依次两两判断字符串是否相似，相似则将它们所在的域合并；全部判断完毕后，连通域的个数即为相似字符串组的个数。
int numSimilarGroups(vector<string>& strs)
{
	int n = strs.size();
	UnionFind839 unionFind(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (unionFind.find(i) != unionFind.find(j) && isSimilar(strs[i], strs[j]))
			{
					unionFind.merge(i, j);
			}
		}
	}
	return unionFind.getDomainCnt();
}


int main839()
{
	vector<string> test = { "tars","rats","arts","star" };
	//vector<string> test = { "ovm","omv" };
	int ret = numSimilarGroups(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}