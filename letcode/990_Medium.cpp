#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

//给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
//
//只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
//
//
//提示：
//
//	1 <= equations.length <= 500
//	equations[i].length == 4
//	equations[i][0] 和 equations[i][3] 是小写字母
//	equations[i][1] 要么是 '='，要么是 '!'
//	equations[i][2] 是 '='
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/satisfiability-of-equality-equations
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Vertex
{
public:
	Vertex(char name) :name(name), degree(0), connectivityVertex(set<Vertex*>()) { this->addEdge(this); } //顶点和自己是连通的
	char name;
	int degree;
	set<Vertex*>connectivityVertex; //连接顶点集
	void addEdge(Vertex* connectVertex) //增加一条边
	{
		pair<set<Vertex*>::iterator, bool> ret = connectivityVertex.insert(connectVertex);
		if (false == ret.second)
			return;
		cout << "addEdge：增加一条边：" << this->name << "--" << connectVertex->name << endl;
		connectVertex->addEdge(this); //增加反方向的边

		//增加相关边
		for (set<Vertex*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
			this->addEdge(*it);
		degree = connectivityVertex.size();
	}
};


//无向图。将变量设为顶点，变量间的相等关系设为边，有无向边连接的变量相等。首先遍历 equations 数组构造关系图，每插入一个顶点都要确定该顶点的所有无向边边；查询时遍历 equations 数组，两查询变量（顶点）间的无向边即是查询结果。
bool equationsPossible(vector<string>& equations)
{
	map<char, Vertex*>vertexs; //顶点集

	//构造关系图
	for (vector<string>::iterator it = equations.begin(); it != equations.end(); it++)
	{
		if (vertexs.end() == vertexs.find(it->at(0)))
			vertexs[it->at(0)] = new Vertex(it->at(0));
		if (vertexs.end() == vertexs.find(it->at(3)))
			vertexs[it->at(3)] = new Vertex(it->at(3));
		if ('=' == it->at(1))
			vertexs.at(it->at(0))->addEdge(vertexs.at(it->at(3)));
	}

	//查询关系图
	for (vector<string>::iterator it = equations.begin(); it != equations.end(); it++)
	{
		if ('!' == it->at(1) && vertexs.at(it->at(0))->connectivityVertex.end() != vertexs.at(it->at(0))->connectivityVertex.find(vertexs.at(it->at(3))))
			return false;
	}
	return true;
}


int main990()
{
	vector<string> test = { "a==c","b==d","x!=x" };
	bool ret = equationsPossible(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}