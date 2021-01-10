#include<iostream>
#include<vector>
#include<string>

using namespace std;

//��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
//
//���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��
//
//����ʵ��������ַ�������ָ�������任�ĺ�����
//
//string convert(string s, int numRows);
//
//
//��ʾ��
//
//	1 <= s.length <= 1000
//	s ��Ӣ����ĸ��Сд�ʹ�д����',' �� '.' ���
//	1 <= numRows <= 1000
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/zigzag-conversion
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//��ָ�������
string convert(string s, int numRows) 
{
	numRows = numRows < s.size() ? numRows : s.size();
	vector<string>rows(numRows, string());
	vector<string>::iterator itRow = rows.begin();
	bool isDownward = true;

	//�����м�
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		itRow->append(1,*it);
		if (rows.end() - 1 == itRow)
			isDownward = false;
		if (rows.begin() == itRow)
			isDownward = true;
		isDownward ? itRow++ : itRow--;
		if (rows.end() == itRow)
			itRow = rows.begin();
	}

	//��������ַ���
	string ret;
	for (itRow = rows.begin(); itRow != rows.end(); itRow++)
	{
		ret += *itRow;
	}
	return ret;
}


int main()
{
	string test = "P";
	string ret = convert(test, 12);
	cout << "main��ret = " << ret << endl;
	return 0;
}