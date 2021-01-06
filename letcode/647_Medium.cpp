#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
//
//具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//
//提示：
//
//	输入的字符串长度不会超过 1000 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/palindromic-substrings
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


////解法一：单指针遍历数组。查找回文子串的核心是：利用回文字符串轴对称的性质，将原字符串的各字符依次作为子串的对称轴（回文中心）；每次设定对称轴后，不断扩展子串以找到更长的回文子串。时间复杂度 O(n^2)，空间复杂度 O(1)。
//int countSubstrings(string s)
//{
//	int palindromeCnt = 0;
//	int sSize = s.size();
//	int j;
//	for (int i = 0; i < sSize; i++)
//	{
//		j = 0;
//		while (i - j >= 0 && i + j < sSize && s[i - j] == s[i + j]) //找到以 s[i] 为中心的回文子串
//		{
//			palindromeCnt++;
//			cout << "countSubstrings：找到回文字串  " << string(s.begin() + i - j, s.begin() + i + j + 1) << endl;
//			j++;
//		}
//
//		if (s[i] == s[i + 1]) //找到以 s[i] s[i+1] 为中心的回文字串
//		{
//			j = 0;
//			while (i - j >= 0 && i + j + 1 < sSize && s[i - j] == s[i + j + 1]) //找到以 s[i]s[i+1] 为中心的回文子串
//			{
//				palindromeCnt++;
//				cout << "countSubstrings：找到回文字串  " << string(s.begin() + i - j, s.begin() + i + j + 1 + 1) << endl;
//				j++;
//			}
//		}
//
//		cout << endl;
//	}
//	return palindromeCnt;
//}


//解法二：基于 Manacher 算法。利用最大回文半径数组减少每个候选回文中心的扩展次数。以空间换时间，时间复杂度 O(n)，空间复杂度 O(n)。
int countSubstrings(string s)
{
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
	int palindromeCnt = 0;
	int cnt = 0;
	for (int i = 1; i < MsSize; i++)
	{
		j = 2 * rCentre - i;
		r = i < rMax ? min(rMaxArray[j] - 1, rMax - i) : 1;
		while (Ms[i - r] == Ms[i + r])
		{
			if (1 == r % 2)
				cout << "countSubstrings：找到回文子串  " << ++cnt << "  " << string(Ms.begin() + i - r, Ms.begin() + i + r + 1) << endl;
			r++;
		}
		rMaxArray[i] = r;
		rCentre = i + r - 1 > rMax ? i : rCentre;
		rMax = i + r - 1 > rMax ? i + r - 1 : rMax;
		palindromeCnt += r / 2; //最大回文半径 - 1 = 该回文中心最长回文子串的长度（包含的有效字符数）
	}
	return palindromeCnt;
}


int main647()
{
	string test = "dfghjkl";
	int ret = countSubstrings(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}