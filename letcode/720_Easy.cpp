#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

//给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
//
//若无答案，则返回空字符串。
//
//
//提示：
//
//	所有输入的字符串都只包含小写字母。
//	words数组长度范围为[1, 1000]。
//	words[i]的长度范围为[1, 30]。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/longest-word-in-dictionary
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//前缀树（Trie）。
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() :isEnd(false), charVec(26, nullptr)
	{

	}

	/** Inserts a word into the trie. */
	bool insert(string word) //插入一个字符串，并返回该字符串是否为“生成字符串”
	{
		bool ret = true;
		Trie* node = this;
		int n = word.length();
		for (int i = 0; i < n; i++)
		{
			if (node->charVec[word[i] - 'a'] == nullptr)
				node->charVec[word[i] - 'a'] = new Trie;
			node = node->charVec[word[i] - 'a'];
			if (i != n - 1 && node->isEnd == false) //前缀树中不包含输入字符串的某前缀
				ret = false;
		}
		//此时 node 节点指向 word 单词的最后一个字母
		node->isEnd = true;
		node->endWord = word;
		return ret;
	}

private:
	bool isEnd; //当前节点是否为词尾
	vector<Trie*> charVec; //孩子数组（存储当前节点的后缀节点）
	string endWord; //本例中非必须
};


//哈希表。首先将原始字符串数组按升序排序；随后正序遍历字符串数组中各字符串，使用哈希表判断其是否为“生成字符串”，并记录长度最长的“生成字符串”作为返回值；当且仅当满足以下条件之一时，字符串 s[0,n] 为“生成字符串”：1.字符串长度为 1 ，即 n==0 ；2. s[0,n - 1] 为“生成字符串”。
//string longestWord(vector<string>& words)
//{
//	sort(words.begin(), words.end());
//	map<string, bool> builtMap; //哈希表，记录各字符串是否为“生成字符串”
//	string ret;
//	int maxLength = 0;
//
//	string tmp;
//	map<string, bool>::iterator tmpIt;
//	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
//	{
//		if (it->length() == 1)
//		{
//			builtMap.insert(make_pair(*it, true));
//			if (it->length() > maxLength)
//			{
//				maxLength = it->length();
//				ret = *it;
//			}
//		}
//		else
//		{
//			tmp = it->substr(0, it->length() - 1);
//			if ((tmpIt = builtMap.find(tmp)) != builtMap.end() && tmpIt->second == true)
//			{
//				builtMap.insert(make_pair(*it, true));
//				if (it->length() > maxLength)
//				{
//					maxLength = it->length();
//					ret = *it;
//				}
//			}
//			else
//				builtMap.insert(make_pair(*it, false));
//		}
//	}
//	return ret;
//}


//前缀树。首先将原始字符串数组按升序排序；随后正序遍历字符串数组中各字符串，依次将其插入前缀树，在插入操作的过程中判断该字符串是否为“生成字符串”，并记录长度最长的“生成字符串”作为返回值；当且仅当满足以下条件时，字符串 s[0,n] 为“生成字符串”：前缀树中包含字符串 s[0,n] 的所有前缀。
string longestWord(vector<string>& words)
{
	sort(words.begin(), words.end());
	Trie* obj = new Trie();
	string ret;
	int maxLength = 0;
	bool isBuilt;
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
	{
		isBuilt = obj->insert(*it);
		if (isBuilt == true && it->length() > maxLength)
		{
			maxLength = it->length();
			ret = *it;
		}
	}
	return ret;
}


int main()
{
	//vector<string> test = { "ts", "e", "x", "pbhj", "opto", "xhigy", "erikz", "pbh", "opt", "erikzb", "eri", "erik", "xlye", "xhig", "optoj", "optoje", "xly", "pb", "xhi", "x", "o" };
	vector<string> test = { "a","banana", "app", "appl", "ap", "apply", "apple" };
	string ret = longestWord(test);
	cout << "main：ret = " << ret << endl;
	return 0;
}