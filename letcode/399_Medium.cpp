#include<iostream>
#include<vector>
#include<string>

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



vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
{
	return values;
}



int main()
{
	vector<vector<string>> equations = { {"a","b"},{"b","c"} ,{"bc","cd"} };
	vector<double> values = { 1.5, 2.5, 5.0 };
	vector<vector<string>> queries = { {"a","c"},{"c","b"} ,{"bc","cd"}, {"cd","bc"} };
	vector<double> ret = calcEquation(equations, values, queries);
	cout << "main��ret = [";
	for (vector<double>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << " ,";
	}
	cout << "]" << endl;
	return 0;
}