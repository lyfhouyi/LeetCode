#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//给你一个字符串 s，找到 s 中最长的回文子串。
//
//
//提示：
//
//	1 <= s.length <= 1000
//	s 仅由数字和英文字母（大写和 / 或小写）组成
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-palindromic-substring
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//使用 Manacher 算法求得最大回文半径数组，基于最大回文半径数组找到最长的回文子串。
string longestPalindrome(string s)
{
	// Manacher 算法
	//初始化母串
	string Ms = "$#";
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		Ms += *it;
		Ms += '#';
	}
	Ms += "!";
	//cout << s << endl;
	//cout << Ms << endl;

	int MsSize = Ms.size();
	vector<int> rMaxArray(MsSize, 1); //各位置最大回文半径初始化为 1

	int r = 0;
	int rMax = 1; //最大回文右端点
	int rCentre = 1; //最大回文右端点对应的回文中心
	int j = 0;
	//int cnt = 0;

	for (int i = 1; i < MsSize; i++)
	{
		j = 2 * rCentre - i;
		r = i < rMax ? min(rMaxArray[j] - 1, rMax - i) : 1;
		while (Ms[i - r] == Ms[i + r])
		{
			//if (1 == r % 2)
			//	cout << "countSubstrings：找到回文子串  " << ++cnt << "  " << string(Ms.begin() + i - r, Ms.begin() + i + r + 1) << "长度="<<r<<endl;
			r++;
		}
		rMaxArray[i] = r;
		rCentre = i + r - 1 > rMax ? i : rCentre;
		rMax = i + r - 1 > rMax ? i + r - 1 : rMax;
	}

	//查找最长回文子串
	vector<int>::iterator longestPos = max_element(rMaxArray.begin(), rMaxArray.end());
	int longestIndex = longestPos - rMaxArray.begin();
	string ret;
	for (string::iterator it = Ms.begin() + longestIndex - *longestPos + 1; it != Ms.begin() + longestIndex + *longestPos; it++)
	{
		if (*it != '#')
			ret += *it;
	}
	return ret;
}


int main5()
{
	string test = "abba";
	string ret = longestPalindrome(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}