#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>

using namespace std;

//外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。
//
//字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：
//
//	单词 word 中包含谜面 puzzle 的第一个字母。
//	单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
//
//返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。
//
//
//提示：
//
//	1 <= words.length <= 10 ^ 5
//	4 <= words[i].length <= 50
//	1 <= puzzles.length <= 10 ^ 4
//	puzzles[i].length == 7
//	words[i][j], puzzles[i][j] 都是小写英文字母。
//	每个 puzzles[i] 所包含的字符都不重复。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//暴力解法。首先通过字母数组构造谜底位数组；随后暴力遍历谜面、谜底，利用谜面的位表示计算其对应的谜底数量。
//算法正确，但时间超时。
//vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
//{
//	int m = words.size();
//	int n = puzzles.size();
//
//	//构造字母数组
//	vector<int> alphabetDict(26);
//	for (int i = 0; i < 26; i++)
//		alphabetDict[i] = pow(2, 25 - i);
//
//	//构造谜底位数组
//	vector<int> wordBitVec(m);
//	for (int i = 0; i < m; i++)
//	{
//		int len = words[i].size();
//		for (int j = 0; j < len; j++)
//		{
//			wordBitVec[i] |= alphabetDict[words[i][j] - 'a'];
//		}
//	}
//
//	//构造谜面位数组并计算其对应的谜底数量
//	vector<int> ret(n);
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		int len = puzzles[i].size();
//		for (int j = 0; j < len; j++) //计算谜面的位表示
//		{
//			tmp |= alphabetDict[puzzles[i][j] - 'a'];
//		}
//		for (int wIndex = 0; wIndex < m; wIndex++)
//		{
//			if ((0 == (~tmp & wordBitVec[wIndex])) && ((alphabetDict[puzzles[i][0] - 'a'] & wordBitVec[wIndex]) != 0))
//				ret[i]++;
//		}
//	}
//	return ret;
//}


//暴力解法，优化版。谜底包含字母的集合必是谜面包含字母的集合的子集，且该子集中必包含谜面的首字母。首先构造谜底数量字典；随后遍历各谜面，枚举该谜面所包含字母的全部子集，利用谜底数量字典计算该子集在谜底中的数量。
//优化一：计算谜底、谜面的位表示时使用移位运算替代字母数组；优化二：利用题目中 puzzles[i].length == 7 的特性，使用谜面的子集（规模很小）快速查找其对应的谜底数量。
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
{
	int m = words.size();
	int n = puzzles.size();

	//构造谜底位数组
	unordered_map<int, int> wordCntMap;
	for (int i = 0; i < m; i++)
	{
		int wordBit = 0; //谜底的位表示
		int len = words[i].size();
		for (int j = 0; j < len; j++)
		{
			wordBit |= 1 << (words[i][j] - 'a');
		}
		wordCntMap[wordBit]++;
		//cout << bitset<26>(wordBit);
		//cout << endl;
	}

	//构造谜面位数组并计算其对应的谜底数量
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
	{
		int puzzleBit = 0; //谜面的位表示
		int len = puzzles[i].size();
		for (int j = 1; j < len; j++) //计算谜面的位表示
		{
			puzzleBit |= (1 << (puzzles[i][j] - 'a'));
		}

		//枚举谜面的全部子集
		int initial = 1 << (puzzles[i][0] - 'a'); //谜面的首字母
		int subSet = puzzleBit; //谜面的子集
		int s; //谜面包含首字母的子集
		while (subSet != 0)
		{
			s = subSet | initial;
			if (wordCntMap.count(s) == 1)
				ret[i] += wordCntMap.at(s);
			subSet = (subSet - 1) & puzzleBit;
		}
		if (wordCntMap.count(initial) == 1)
			ret[i] += wordCntMap.at(initial);
	}
	return ret;
}


int main1178()
{
	vector<string> words = { "aaaa","asas","able","ability","actt","actor","access" };
	vector<string> puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
	vector<int> ret = findNumOfValidWords(words, puzzles);
	cout << "main：ret = [";
	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
	return 0;
}