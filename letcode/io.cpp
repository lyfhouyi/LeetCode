#include<iostream>
#include<string>
#include<vector>

using namespace std;

//�������룬�ո�����ȡһ��
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