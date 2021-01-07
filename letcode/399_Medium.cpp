#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

//����һ������������ equations ��һ��ʵ��ֵ���� values ��Ϊ��֪���������� equations[i] = [Ai, Bi] �� values[i] ��ͬ��ʾ��ʽ Ai / Bi = values[i] ��ÿ�� Ai �� Bi ��һ����ʾ�����������ַ�����
//
//����һЩ������ queries ��ʾ�����⣬���� queries[j] = [Cj, Dj] ��ʾ�� j �����⣬���������֪�����ҳ� Cj / Dj = ? �Ľ����Ϊ�𰸡�
//
//���� ��������Ĵ� ���������ĳ���޷�ȷ���Ĵ𰸣����� - 1.0 �������𰸡�
//
//
//ע�⣺����������Ч�ġ�����Լ�����������в�����ֳ���Ϊ 0 ��������Ҳ������κ�ì�ܵĽ����
//
//
//��ʾ��
//
//1 <= equations.length <= 20
//equations[i].length == 2
//1 <= Ai.length, Bi.length <= 5
//values.length == equations.length
//0.0 < values[i] <= 20.0
//	1 <= queries.length <= 20
//	queries[i].length == 2
//	1 <= Cj.length, Dj.length <= 5
//	Ai, Bi, Cj, Dj ��СдӢ����ĸ���������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/evaluate-division
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Vertex
{
public:
	Vertex(string name) :name(name), outEdges(map<Vertex*, double>()) {}
	string name;
	map<Vertex*, double>outEdges; //���߼���pair<Ŀ�궥�㣨��Ϊ���ӣ�����ֵ����Ϊ��ֵ��>��
	void addOutEdge(Vertex* outVertex, double value) //����һ������
	{
		if (outEdges.end() != outEdges.find(outVertex))
			return;
		cout << "addOutEdge������һ���ߣ�" << this->name << "->" << outVertex->name << "  ( " << this->name << " / " << outVertex->name << " ) = " << value << endl;
		outEdges[outVertex] = value;
		outVertex->addOutEdge(this, 1 / value); //���ӷ�����ĳ���

		//������ر�
		for (map<Vertex*, double>::iterator it = outVertex->outEdges.begin(); it != outVertex->outEdges.end(); it++)
			this->addOutEdge(it->first, (outEdges.at(outVertex))*(it->second));
	}
};


//��Ȩ����ͼ����������Ϊ���㣬������ı�ֵ��ϵ��Ϊ�ߣ�����ߵĳ�������Ϊ���ӣ��붥����Ϊ��ĸ�����ȱ��� equations ���鹹���ϵͼ��ÿ����һ�����㶼Ҫȷ���ö������������ߣ���ѯʱ���� queries ���飬����ѯ���������㣩�������߼��ǲ�ѯ�����
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	map<string, Vertex*>vertexs; //���㼯
	vector<double> result;
	//�����ϵͼ
	for (int i = 0; i < equations.size(); i++)
	{
		if (vertexs.end() == vertexs.find(equations[i][0]))
			vertexs[equations[i][0]] = new Vertex(equations[i][0]);
		if (vertexs.end() == vertexs.find(equations[i][1]))
			vertexs[equations[i][1]] = new Vertex(equations[i][1]);
		vertexs.at(equations[i][0])->addOutEdge(vertexs.at(equations[i][1]), values[i]);
	}

	//��ѯ��ϵͼ
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

//�����ϵͼ��ʱ�临�Ӷ� O(n^2)=1lg1+2lg2+xlgx+mlgm
//��ѯ��ϵͼ��ʱ�临�Ӷ� O(nlgm)
int main()
{
	vector<vector<string>> equations = { {"a","b"},{"c","d"} };
	vector<double> values = { 1,1 };
	vector<vector<string>> queries = { {"a","c"},{"b","d"} ,{"b","a"}, {"d","c"} };
	vector<double> ret = calcEquation(equations, values, queries);
	cout << "main��ret = [";
	for (vector<double>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << " ,";
	}
	cout << "]" << endl;
	return 0;
}