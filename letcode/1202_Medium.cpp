#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<functional>

using namespace std;

//给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
//
//你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
//
//返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。
//
//
//提示：
//
//	1 <= s.length <= 10 ^ 5
//	0 <= pairs.length <= 10 ^ 5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s 中只含有小写英文字母
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/smallest-string-with-swaps
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Pos
{
public:
	Pos(int no, string& s) :no(no), s(s), candidateQueue(nullptr), isInQueue(false) {} //初始化时，顶点和自己是不连通的
	int no;
	string& s;
	shared_ptr<priority_queue<char, vector<char>, greater<char>>> candidateQueue; //可交换字符构成的优先级队列
	bool isInQueue; //当前字符是否在当前节点的可交换字符构成的优先级队列中
	set<Pos*> connectivityVertex; //连接顶点集
	void addEdge(Pos* connectVertex) //增加一条边
	{
		pair<set<Pos*>::iterator, bool>result = connectivityVertex.insert(connectVertex);
		if (false == result.second)
			return;
		//cout << "addEdge：增加一条边：  " << this->no << "-->" << connectVertex->no << endl;
		connectivityVertex.insert(connectVertex);
		connectVertex->addEdge(this);
		for (set<Pos*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
			this->addEdge(*it);
	}

	//方法一：在构造关系图时，增加边的同时扩充优先级队列
	//void addEdge(Pos* connectVertex) //增加一条边
	//{
	//	pair<set<Pos*>::iterator, bool>result = connectivityVertex.insert(connectVertex);
	//	if (false == result.second)
	//		return;
	//	//cout << "addEdge：增加一条边：  " << this->no << "-->" << connectVertex->no << endl;
	//	//if ((connectVertex->no > this->no) && (s[minCharIndex] > s[connectVertex->no]))
	//	//	minCharIndex = connectVertex->no;
	//	connectivityVertex.insert(connectVertex);
	//	if (nullptr == candidateQueue)
	//	{
	//		candidateQueue.reset(new priority_queue<char, vector<char>, greater<char>>);
	//		//cout << "addEdge：新建一个可交换字符优先级队列：" << candidateQueue << endl;
	//	}
	//	if(nullptr == connectVertex->candidateQueue || this->candidateQueue == connectVertex->candidateQueue)
	//		connectVertex->candidateQueue = this->candidateQueue;
	//	else //合并两个优先级队列
	//	{
	//		//cout << "addEdge：合并可交换字符优先级队列：" << connectVertex->candidateQueue << "-->" << this->candidateQueue << endl;
	//		while (!connectVertex->candidateQueue->empty())
	//		{
	//			this->candidateQueue->push(connectVertex->candidateQueue->top());
	//			connectVertex->candidateQueue->pop();
	//		}
	//		connectVertex->candidateQueue = this->candidateQueue;
	//	}
	//	if (!isInQueue)
	//	{
	//		//cout << "addEdge：  " << s[this->no] << "  已加入可交换字符优先级队列  " << candidateQueue << endl;
	//		candidateQueue->push(s[this->no]);
	//		isInQueue = true;
	//	}
	//	connectVertex->addEdge(this);
	//	for (set<Pos*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
	//		this->addEdge(*it);
	//}
};


//无向图。将可交换的位置索引设为顶点，可交换的位置间的连通关系关系设为边，有无向边连接的索引位置可交换。首先遍历 pairs 数组构造关系图，每插入一个顶点都要确定该顶点的所有无向边；使用若干个优先级队列，存入各连通域的字符，可以在构造关系图时，增加边的同时扩充优先级队列，也可以在构造完关系图后，统一构造优先级队列；查询时正向遍历字符串 s ，从串首开始将每个位置的字符替换为其连通域内的最小字符，随后在相应的优先级队列中删除该字符。
//算法正确，但时间超时。
//string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
//{
//	map<int, Pos*> vertexs; //顶点集
//
//	//构造关系图
//	for (vector<vector<int>>::iterator it = pairs.begin(); it != pairs.end(); it++)
//	{
//		if(vertexs.end()==vertexs.find(it->at(0)))
//			vertexs[it->at(0)]=new Pos(it->at(0),s);
//		if (vertexs.end() == vertexs.find(it->at(1)))
//			vertexs[it->at(1)] = new Pos(it->at(1),s);
//		vertexs.at(it->at(0))->addEdge(vertexs.at(it->at(1)));
//	}
//
//	//构造优先级队列（方法二：在构造完关系图后，统一构造优先级队列）
//	for(map<int, Pos*>::iterator it=vertexs.begin();it!=vertexs.end();it++)
//	{
//		if (it->second->candidateQueue != nullptr)
//			continue;
//		it->second->candidateQueue.reset(new priority_queue<char, vector<char>, greater<char>>);
//		//it->second->candidateQueue->push(s[it->second->no]);
//		for (set<Pos*>::iterator it2 = it->second->connectivityVertex.begin(); it2 != it->second->connectivityVertex.end(); it2++)
//		{
//			(*it2)->candidateQueue = it->second->candidateQueue;
//			it->second->candidateQueue->push(s[(*it2)->no]);
//		}
//	}
//
//	//查询关系图
//	map<int, Pos*>::iterator currentItVertex;
//	set<Pos*>::iterator it;
//	for (int i = 0; i < s.length(); i++)
//	{
//		currentItVertex = vertexs.find(i);
//		if (vertexs.end() == currentItVertex)
//			continue;
//		s[i] = currentItVertex->second->candidateQueue->top();
//		currentItVertex->second->candidateQueue->pop();
//	}
//	return s;
//}



//深度优先搜索，基于优先级队列
//void dfs(const vector<vector<int>>& isConnected, vector<int>& candidateQueueNo, int startIndex,int queueNo,vector<priority_queue<char, vector<char>, greater<char>>*>& candidateQueues, string& s)
//{
//	candidateQueueNo[startIndex] = queueNo;
//	candidateQueues[queueNo - 1]->push(s[startIndex]);
//	int size = isConnected.size();
//	for (int i = 0; i < size; i++)
//		if (1 == isConnected[startIndex][i] && 0 == candidateQueueNo[i])
//			dfs(isConnected, candidateQueueNo, i, queueNo, candidateQueues,s);
//}


//深度优先搜索，基于优先级队列
//算法正确，但时间超时。
//string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
//{
//	int n = s.length();
//	vector<vector<int>> isConnected(n, vector<int>(n, 0)); //连接矩阵
//	
//	//构造连接矩阵
//	for (vector<vector<int>>::iterator it = pairs.begin(); it != pairs.end(); it++)
//	{
//		isConnected[it->at(0)][it->at(1)] = 1;
//		isConnected[it->at(1)][it->at(0)] = 1;
//	}
//
//	vector<int> candidateQueueNo(n, 0); //长度与原始字符串相同，指出原始字符串的每一个位置属于哪一个连通域，每个连通域对应一个优先级队列
//	vector<priority_queue<char, vector<char>, greater<char>>*> candidateQueues; //存储各个优先级队列，索引 = 该优先级队列的编号 - 1 。
//	int queueNo = 0; //优先级队列编号
//	
//	//深度优先搜索
//	for (int i = 0; i < n; i++)
//	{
//		if (candidateQueueNo[i]!=0)
//			continue;
//		queueNo++;
//		candidateQueues.push_back(new priority_queue<char, vector<char>, greater<char>>);
//		dfs(isConnected, candidateQueueNo, i, queueNo, candidateQueues,s);
//	}
//
//	//就地排序原始字符串
//	for (int i = 0; i < n; i++)
//	{
//		s[i]=candidateQueues[candidateQueueNo[i] - 1]->top();
//		candidateQueues[candidateQueueNo[i] - 1]->pop();
//	}
//	return s;
//}


//深度优先搜索，基于桶
void dfs(const vector<vector<int>>& isConnected, vector<int>& candidateBucketNo, int startIndex, int bucketNo, vector<vector<int>*>& candidateBuckets, string& s)
{
	candidateBucketNo[startIndex] = bucketNo;
	candidateBuckets[bucketNo - 1]->at(s[startIndex] - 'a')++;
	int size = isConnected.size();
	for (int i = 0; i < size; i++)
		if (1 == isConnected[startIndex][i] && 0 == candidateBucketNo[i])
			dfs(isConnected, candidateBucketNo, i, bucketNo, candidateBuckets, s);
}


//深度优先搜索，基于桶
//算法正确，但时间超时。
//string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
//{
//	int n = s.length();
//	vector<vector<int>> isConnected(n, vector<int>(n, 0)); //连接矩阵
//	
//	//构造连接矩阵
//	for (vector<vector<int>>::iterator it = pairs.begin(); it != pairs.end(); it++)
//	{
//		isConnected[it->at(0)][it->at(1)] = 1;
//		isConnected[it->at(1)][it->at(0)] = 1;
//	}
//
//	vector<int> candidateBucketNo(n, 0); //长度与原始字符串相同，指出原始字符串的每一个位置属于哪一个连通域，每个连通域对应一个桶
//	vector<vector<int>*> candidateBuckets; //存储各个桶，索引 = 该桶的编号 - 1 。
//	int bucketNo = 0; //优先级队列编号
//	
//	//深度优先搜索
//	for (int i = 0; i < n; i++)
//	{
//		if (candidateBucketNo[i]!=0)
//			continue;
//		bucketNo++;
//		candidateBuckets.push_back(new vector<int>(26,0));
//		dfs(isConnected, candidateBucketNo, i, bucketNo, candidateBuckets,s);
//	}
//
//	//就地排序原始字符串
//	int pMin;
//	for (int i = 0; i < n; i++)
//	{
//		for (pMin=0;pMin<26;pMin++)
//		{
//			if (candidateBuckets[candidateBucketNo[i] - 1]->at(pMin) != 0)
//			{
//				s[i] = 'a' + pMin;
//				candidateBuckets[candidateBucketNo[i] - 1]->at(pMin)--;
//				break;
//			}
//		}
//	}
//	return s;
//}


class Pos2
{
public:
	Pos2(int no) :no(no), domainNo(no) {} //初始化时，顶点和自己是不连通的，顶点自己就是一个连通域
	int no;
	int domainNo;
	set<Pos2*> connectivityVertex; //连接顶点集
	void addEdge(Pos2* connectVertex) //增加一条边
	{
		pair<set<Pos2*>::iterator, bool>result = connectivityVertex.insert(connectVertex);
		if (false == result.second)
			return;
		//cout << "addEdge：增加一条边：  " << this->no << "-->" << connectVertex->no << endl;
		connectivityVertex.insert(connectVertex);
		connectVertex->domainNo = this->domainNo;
		connectVertex->addEdge(this);
		for (set<Pos2*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
			this->addEdge(*it);
	}


};


//无向图。将可交换的位置索引设为顶点，可交换的位置间的连通关系关系设为边，有无向边连接的索引位置可交换。首先遍历 pairs 数组构造关系图，每插入一个顶点都要确定该顶点的所有无向边，及所属连通域；使用若干个优先级队列，存储各连通域的字符，首先遍历一遍原始字符串，为各个连通域加入字符；查询时正向遍历字符串 s ，从串首开始将每个位置的字符替换为其连通域内的最小字符，随后在相应的优先级队列中删除该字符。
//算法正确，但时间超时。
//string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
//{
//	int n = s.length();
//	map<int, Pos2*> vertexs; //顶点集
//	map<int, priority_queue<char, vector<char>, greater<char>>*> candidateQueues; //优先级队列集
//		
//	//构造关系图
//	for (vector<vector<int>>::iterator it = pairs.begin(); it != pairs.end(); it++)
//	{
//		if(vertexs.end()==vertexs.find(it->at(0)))
//			vertexs[it->at(0)]=new Pos2(it->at(0));
//		if (vertexs.end() == vertexs.find(it->at(1)))
//			vertexs[it->at(1)] = new Pos2(it->at(1));
//		vertexs.at(it->at(0))->addEdge(vertexs.at(it->at(1)));
//	}
//
//	//构造优先级队列
//	map<int, Pos2*>::iterator itPos;
//	for (int i = 0; i < n; i++)
//	{
//		if (vertexs.end() == (itPos = vertexs.find(i)))
//			continue;
//		
//		if (candidateQueues.end() == candidateQueues.find(itPos->second->domainNo))
//			candidateQueues[itPos->second->domainNo] = new priority_queue<char, vector<char>, greater<char>>;
//
//		candidateQueues.at(itPos->second->domainNo)->push(s[i]);
//	}
//
//	//查询关系图
//	for (int i = 0; i < n; i++)
//	{
//		if (vertexs.end() == (itPos = vertexs.find(i)))
//			continue;
//		s[i] = candidateQueues.at(itPos->second->domainNo)->top();
//		candidateQueues.at(itPos->second->domainNo)->pop();
//	}
//	return s;
//}


class UnionFind
{
public:
	UnionFind(int n) : fa(vector<int>(n)), rank(vector<int>(n)) { init(n); }

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


//并查集。首先遍历 pairs 数组调整各连通域，随后遍历原始字符串 s 构造各连通域优先级队列，最后再遍历原始字符串 s 重构出输出字符串
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
	int n = s.length();
	UnionFind unionFind(n);
	for (vector<vector<int>>::iterator it = pairs.begin(); it != pairs.end(); it++)
		unionFind.merge(it->at(0), it->at(1));
	map<int, priority_queue<char, vector<char>, greater<char>>*>candidateQueues;
	map<int, priority_queue<char, vector<char>, greater<char>>*>::iterator itDomainQueue;
	int domain;
	for (int i = 0; i < n; i++)
	{
		itDomainQueue = candidateQueues.find((domain = unionFind.find(i)));
		if (candidateQueues.end() == itDomainQueue)
			candidateQueues[domain] = new priority_queue<char, vector<char>, greater<char>>;
		candidateQueues[domain]->push(s[i]);
	}
	for (int i = 0; i < n; i++)
	{
		s[i] = candidateQueues[domain = unionFind.find(i)]->top();
		candidateQueues[domain]->pop();
	}
	return s;

}


int main1202()
{
	string test = "dcab";
	vector<vector<int>> pairs = { {0, 3},{1, 2},{0, 2} };
	//vector<vector<int>> pairs = { {0,0} };
	string ret = smallestStringWithSwaps(test, pairs);
	cout << "main：ret = " << ret << endl;
	return 0;
}