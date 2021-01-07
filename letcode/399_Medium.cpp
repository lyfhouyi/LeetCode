#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

//给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
//
//另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
//
//返回 所有问题的答案 。如果存在某个无法确定的答案，则用 - 1.0 替代这个答案。
//
//
//注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
//
//
//提示：
//
//1 <= equations.length <= 20
//equations[i].length == 2
//1 <= Ai.length, Bi.length <= 5
//values.length == equations.length
//0.0 < values[i] <= 20.0
//	1 <= queries.length <= 20
//	queries[i].length == 2
//	1 <= Cj.length, Dj.length <= 5
//	Ai, Bi, Cj, Dj 由小写英文字母与数字组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/evaluate-division
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Vertex
{
public:
	Vertex(string name) :name(name), outEdges(map<Vertex*, double>()) {}
	string name;
	map<Vertex*, double>outEdges; //出边集（pair<目标顶点（作为分子），边值（作为比值）>）
	void addOutEdge(Vertex* outVertex, double value) //增加一条出边
	{
		if (outEdges.end() != outEdges.find(outVertex))
			return;
		cout << "addOutEdge：增加一条边：" << this->name << "->" << outVertex->name << "  ( " << this->name << " / " << outVertex->name << " ) = " << value << endl;
		outEdges[outVertex] = value;
		outVertex->addOutEdge(this, 1 / value); //增加反方向的出边

		//增加相关边
		for (map<Vertex*, double>::iterator it = outVertex->outEdges.begin(); it != outVertex->outEdges.end(); it++)
			this->addOutEdge(it->first, (outEdges.at(outVertex))*(it->second));
	}
};


//带权有向图。将变量设为顶点，变量间的比值关系设为边，有向边的出顶点设为分子，入顶点设为分母。首先遍历 equations 数组构造关系图，每插入一个顶点都要确定该顶点的所有有向边；查询时遍历 queries 数组，两查询变量（顶点）间的有向边即是查询结果。
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	map<string, Vertex*>vertexs; //顶点集
	vector<double> result;
	//构造关系图
	for (int i = 0; i < equations.size(); i++)
	{
		if (vertexs.end() == vertexs.find(equations[i][0]))
			vertexs[equations[i][0]] = new Vertex(equations[i][0]);
		if (vertexs.end() == vertexs.find(equations[i][1]))
			vertexs[equations[i][1]] = new Vertex(equations[i][1]);
		vertexs.at(equations[i][0])->addOutEdge(vertexs.at(equations[i][1]), values[i]);
	}

	//查询关系图
	for (int i = 0; i < queries.size(); i++)
	{
		if (vertexs.end() == vertexs.find(queries[i][0]) || vertexs.end() == vertexs.find(queries[i][1]))
			result.push_back(-1);
		else
		{
			if (vertexs.at(queries[i][0])->outEdges.end() == vertexs.at(queries[i][0])->outEdges.find(vertexs.at(queries[i][1])))
				result.push_back(-1);
			else
				result.push_back(vertexs.at(queries[i][0])->outEdges.at(vertexs.at(queries[i][1])));
		}
	}
	return result;
}

//构造关系图的时间复杂度 O(n^2)=1lg1+2lg2+xlgx+mlgm
//查询关系图的时间复杂度 O(nlgm)
int main()
{
	vector<vector<string>> equations = { {"a","b"},{"c","d"} };
	vector<double> values = { 1,1 };
	vector<vector<string>> queries = { {"a","c"},{"b","d"} ,{"b","a"}, {"d","c"} };
	vector<double> ret = calcEquation(equations, values, queries);
	cout << "main：ret = [";
	for (vector<double>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << " ,";
	}
	cout << "]" << endl;
	return 0;
}