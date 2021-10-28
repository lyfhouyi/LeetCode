#include<iostream>
#include<string>
#include<vector>

using namespace std;

//整行输入，空格间隔，取一行
int main()
{
	vector<string> vstr;
	string str;
	while (cin >> str)
	{
		vstr.push_back(str);
		if (cin.get() == '\n')
			break;
	}
	return 0;
}