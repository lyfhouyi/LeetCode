﻿#include<iostream>
#include<vector>
#include<string>

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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
{
	return accounts;
}

int main()
{
	vector<vector<string>> test = { {"John", "johnsmith@mail.com", "john00@mail.com"}, { "John", "johnnybravo@mail.com" }, { "John", "johnsmith@mail.com", "john_newyork@mail.com" }, { "Mary", "mary@mail.com" }};
	vector<vector<string>> ret = accountsMerge(test);

	for (vector<vector<string>>::iterator it = ret.begin(); it != ret.end(); it++)
	{

	}
}