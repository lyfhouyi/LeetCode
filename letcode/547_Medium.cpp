#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

//有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
//
//省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//
//给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
//
//返回矩阵中 省份 的数量。
//
//提示：
//
//	1 <= n <= 200
//	n == isConnected.length
//	n == isConnected[i].length
//	isConnected[i][j] 为 1 或 0
//	isConnected[i][i] == 1
//	isConnected[i][j] == isConnected[j][i]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-provinces
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Vertex
{
public:
	Vertex(int no) :no(no), degree(0), connectivityVertex(set<Vertex*>()) {} //初始化时，顶点和自己是不连通的
	int no;
	int degree;
	set<Vertex*>connectivityVertex; //连接顶点集
	void addEdge(Vertex* connectVertex) //增加一条边
	{
		pair<set<Vertex*>::iterator, bool> ret = connectivityVertex.insert(connectVertex);
		if (false == ret.second)
			return;
		cout << "addEdge：增加一条边：" << this->no << "--" << connectVertex->no << endl;
		connectVertex->addEdge(this); //增加反方向的边

		//增加相关边
		for (set<Vertex*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
			this->addEdge(*it);
		degree = connectivityVertex.size();
	}
};


//解法一：无向图。将城市设为顶点，城市间的连通关系设为边。首先构造城市集，随后遍历 isConnected 数组，构造关系图，每插入一条边都要确定该顶点的所有边；顶点的度反映了与该城市连通的城市的数量，通过构造城市数量数组计算省份数量。
int findCircleNum(vector<vector<int>>& isConnected) 
{
	map<int, Vertex*>vertexs; //顶点集
	int size = isConnected.size(); //城市总数
	int i;

	//构造顶点集
	for (i = 0; i < size; i++)
	{
		if (vertexs.end() == vertexs.find(i))
			vertexs[i] = new Vertex(i);
	}

	//构造关系图
	for (i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (1 == isConnected[i][j])
				vertexs[i]->addEdge(vertexs[j]);
		}
	}

	//计算省份数量
	vector<int>cityCnt(size); //保存每一个城市所在的省份的城市数量
	int provinceCnt = 0;
	for (i=0;i<size;i++)
	{
		cout << vertexs[i]->degree << "  ";
		cityCnt[i]= vertexs[i]->degree;
	}
	sort(cityCnt.begin(), cityCnt.end());
	for (i = 0; i < size; )
	{
		provinceCnt++;
		i += cityCnt[i];
	}
	return provinceCnt;
}


void dfs(const vector<vector<int>>& isConnected, vector<bool>& isVisited, int startIndex)
{
	isVisited[startIndex] = true;
	int size = isConnected.size();
	for (int i = 0; i < size; i++)
		if (1 == isConnected[startIndex][i] && false == isVisited[i])
			dfs(isConnected, isVisited, i);
}


//解法二：深度优先搜索
//int findCircleNum(vector<vector<int>>& isConnected)
//{
//	int provinceCnt = 0;
//	int size = isConnected.size();
//	vector<bool> isVisited(size, false);
//	for (int i = 0; i < size; i++)
//	{
//		if (true == isVisited[i])
//			continue;
//		provinceCnt++;
//		dfs(isConnected, isVisited, i);
//	}
//	return provinceCnt;
//}


//解法三：广度优先搜索
//int findCircleNum(vector<vector<int>>& isConnected)
//{
//	int provinceCnt = 0;
//	int size = isConnected.size();
//	int currentVisit;
//	int j;
//	vector<bool> isVisited(size, false);
//	queue<int>visitList;
//	for (int i = 0; i < size; i++)
//	{
//		if (true == isVisited[i])
//			continue;
//		provinceCnt++;
//		visitList.push(i);
//		while (!visitList.empty())
//		{
//			currentVisit = visitList.front();
//			visitList.pop();
//			isVisited[currentVisit] = true;
//			for (j = 0; j < size; j++)
//			{
//				if (1 == isConnected[currentVisit][j] && false == isVisited[j])
//					visitList.push(j);
//			}
//		}
//	}
//	return provinceCnt;
//}

int main547()
{
	vector<vector<int>> test{ {1, 0, 0, 1},{0, 1, 1, 0},{0, 1, 1,1},{1, 0, 1, 1} };
	//vector<vector<int>> test{ {1, 0, 0},{0, 1, 0},{0, 0, 1} };
	int ret = findCircleNum(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}