#include<iostream>
#include<vector>
#include<string>

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
	cout << "main：ret = [";
	for (vector<double>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << " ,";
	}
	cout << "]" << endl;
	return 0;
}