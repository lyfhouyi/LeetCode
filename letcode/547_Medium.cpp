#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

//�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������
//
//ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�
//
//����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
//
//���ؾ����� ʡ�� ��������
//
//��ʾ��
//
//	1 <= n <= 200
//	n == isConnected.length
//	n == isConnected[i].length
//	isConnected[i][j] Ϊ 1 �� 0
//	isConnected[i][i] == 1
//	isConnected[i][j] == isConnected[j][i]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/number-of-provinces
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Vertex
{
public:
	Vertex(int no) :no(no), degree(0), connectivityVertex(set<Vertex*>()) {} //��ʼ��ʱ��������Լ��ǲ���ͨ��
	int no;
	int degree;
	set<Vertex*>connectivityVertex; //���Ӷ��㼯
	void addEdge(Vertex* connectVertex) //����һ����
	{
		pair<set<Vertex*>::iterator, bool> ret = connectivityVertex.insert(connectVertex);
		if (false == ret.second)
			return;
		cout << "addEdge������һ���ߣ�" << this->no << "--" << connectVertex->no << endl;
		connectVertex->addEdge(this); //���ӷ�����ı�

		//������ر�
		for (set<Vertex*>::iterator it = connectVertex->connectivityVertex.begin(); it != connectVertex->connectivityVertex.end(); it++)
			this->addEdge(*it);
		degree = connectivityVertex.size();
	}
};


//�ⷨһ������ͼ����������Ϊ���㣬���м����ͨ��ϵ��Ϊ�ߡ����ȹ�����м��������� isConnected ���飬�����ϵͼ��ÿ����һ���߶�Ҫȷ���ö�������бߣ�����Ķȷ�ӳ����ó�����ͨ�ĳ��е�������ͨ��������������������ʡ��������
int findCircleNum(vector<vector<int>>& isConnected) 
{
	map<int, Vertex*>vertexs; //���㼯
	int size = isConnected.size(); //��������
	int i;

	//���춥�㼯
	for (i = 0; i < size; i++)
	{
		if (vertexs.end() == vertexs.find(i))
			vertexs[i] = new Vertex(i);
	}

	//�����ϵͼ
	for (i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (1 == isConnected[i][j])
				vertexs[i]->addEdge(vertexs[j]);
		}
	}

	//����ʡ������
	vector<int>cityCnt(size); //����ÿһ���������ڵ�ʡ�ݵĳ�������
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


//�ⷨ���������������
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


//�ⷨ���������������
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
	cout << "main��ret = " << ret << endl;
	return 0;
}