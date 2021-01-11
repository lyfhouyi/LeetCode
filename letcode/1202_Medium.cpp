#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>

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


class Vertex
{
public:
	Vertex(int no,string& s):no(no),s(s),candidateQueue(nullptr), isInQueue(false){} //顶点和自己是不连通的
	int no;
	string& s;
	priority_queue<char>* candidateQueue; //可交换字符构成的优先级队列
	bool isInQueue; //当前字符是否在当前节点的可交换字符构成的优先级队列中
	set<Vertex*> connectivityVertex; //连接顶点集
	void addEdge(Vertex* connectVertex) //增加一条边
	{
		pair<set<Vertex*>::iterator, bool>result = connectivityVertex.insert(connectVertex);
		if (false == result.second)
			return;
		//if ((connectVertex->no > this->no) && (s[minCharIndex] > s[connectVertex->no]))
		//	minCharIndex = connectVertex->no;
		connectivityVertex.insert(connectVertex);
		if (nullptr == candidateQueue)
			candidateQueue = new priority_queue<char>;
		connectVertex->candidateQueue = this->candidateQueue;
		if (!isInQueue)
		{
			cout << "addEdge：  " << s[this->no] << "  字符已加入可交换字符优先级队列" << endl;
			candidateQueue->push(s[this->no]);
			isInQueue = true;
		}
		connectVertex->addEdge(this);
		for (set<Vertex*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
			this->addEdge(*it);
	}
};


//无向图。将可交换的位置索引设为顶点，可交换的位置间的连通关系关系设为边，有无向边连接的索引位置可交换。首先遍历 pairs 数组构造关系图，每插入一个顶点都要确定该顶点的所有无向边；查询时正向遍历字符串 s ，从串首开始将每个位置的字符替换为其后的可替换的最小字符。
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
	map<int,Vertex*> vertexs; //顶点集

	//构造关系图
	for (vector<vector<int>>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if(vertexs.end()==vertexs.find(it->at(0)))
			vertexs[it->at(0)]=new Vertex(it->at(0),s);
		if (vertexs.end() == vertexs.find(it->at(1)))
			vertexs[it->at(1)] = new Vertex(it->at(1),s);
		vertexs.at(it->at(0))->addEdge(vertexs.at(it->at(1)));
	}

	int changeCnt = 0;
	//查询关系图
	map<int, Vertex*>::iterator currentItVertex;
	set<Vertex*>::iterator it;
	for (int i = 0; i < s.length(); i++)
	{
		currentItVertex = vertexs.find(i);
		if (vertexs.end() == currentItVertex)
			continue;
		//changeCnt++;
		//swap(s[i], s[vertexs[i]->minCharIndex]);

		for (it = currentItVertex->second->connectivityVertex.begin(); it != currentItVertex->second->connectivityVertex.end(); it++)
		{
			if (currentItVertex->second->no < (*it)->no && s[i]>s[(*it)->no])
			{
				swap(s[i], s[(*it)->no]);
				changeCnt++;
			}
		}
	}
	cout << "smallestStringWithSwaps：changeCnt = " << changeCnt << endl;
	return s;
}


int main()
{
	string test = "dcab";
	vector<vector<int>> pairs = { {3,0},{1,2},{0,2}  };
	//vector<vector<int>> pairs = { {0,0} };
	string ret = smallestStringWithSwaps(test, pairs);
	cout << "main：ret = " << ret << endl;
	return 0;
}