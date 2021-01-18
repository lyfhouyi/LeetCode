#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

//给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称(name)，其余元素是 emails 表示该账户的邮箱地址。
//
//现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
//
//合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。
//
//
//
//提示：
//
//	accounts的长度将在[1，1000]的范围内。
//	accounts[i]的长度将在[1，10]的范围内。
//	accounts[i][j]的长度将在[1，30]的范围内。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/accounts-merge
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class UnionFind721
{
public:
	UnionFind721(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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


//并查集。首先将每个账户设为一个单独的域；随后遍历 accounts 数组，逐账户检查各个邮箱是否已存在，若存在则将两个账户合并；
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
{
	int n = accounts.size();
	int nEmail;
	int j;
	int hasDomain = -1; //指示当前账户与哪个账户属于同一个人
	UnionFind721 unionFind(n);
	map<string, int> email2Domain;
	for (int i=0;i<n;i++)
	{
		hasDomain = -1;
		nEmail = accounts[i].size();
		for (j = 1; j < nEmail; j++)
		{
			if (email2Domain.end() == email2Domain.find(accounts[i][j]))
				email2Domain[accounts[i][j]] = i; //建立邮箱到域中元素（不一定是代表元）的映射关系
			else
				hasDomain = email2Domain.at(accounts[i][j]);
		}
		if (-1 != hasDomain)
			unionFind.merge(hasDomain, i);
	}
	return accounts;
}


int main()
{
	vector<vector<string>> test = { {"John", "johnsmith@mail.com", "john00@mail.com"}, { "John", "johnnybravo@mail.com" }, { "John", "johnsmith@mail.com", "john_newyork@mail.com" }, { "Mary", "mary@mail.com" }};
	vector<vector<string>> ret = accountsMerge(test);
	for (vector<vector<string>>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		for (int i = 0; i < it->size(); i++)
			cout << it->at(i) << ",";
		cout << endl;
	}
}