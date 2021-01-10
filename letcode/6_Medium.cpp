#include<iostream>
#include<vector>
#include<string>

using namespace std;

//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
//请你实现这个将字符串进行指定行数变换的函数：
//
//string convert(string s, int numRows);
//
//
//提示：
//
//	1 <= s.length <= 1000
//	s 由英文字母（小写和大写）、',' 和 '.' 组成
//	1 <= numRows <= 1000
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/zigzag-conversion
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//单指针遍历。
string convert(string s, int numRows) 
{
	numRows = numRows < s.size() ? numRows : s.size();
	vector<string>rows(numRows, string());
	vector<string>::iterator itRow = rows.begin();
	bool isDownward = true;

	//构造行集
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

	//构造输出字符串
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
	cout << "main：ret = " << ret << endl;
	return 0;
}