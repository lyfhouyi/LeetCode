#include<iostream>
#include<vector>
#include<set>

using namespace std;

//Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
//
//请你实现 Trie 类：
//
//	Trie() 初始化前缀树对象。
//	void insert(String word) 向前缀树中插入字符串 word 。
//	boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
//	boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
//
//
//提示：
//
//	1 <= word.length, prefix.length <= 2000
//	word 和 prefix 仅由小写英文字母组成
//	insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-trie-prefix-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//有序集合。
//class Trie {
//public:
//	/** Initialize your data structure here. */
//	Trie()
//	{
//
//	}
//
//	/** Inserts a word into the trie. */
//	void insert(string word)
//	{
//		wordSet.insert(word);
//	}
//
//	/** Returns if the word is in the trie. */
//	bool search(string word)
//	{
//		return wordSet.count(word);
//	}
//
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(string prefix)
//	{
//		set<string>::iterator it = wordSet.lower_bound(prefix);
//		return (it != wordSet.end() && (it->substr(0, prefix.length()) == prefix));
//	}
//private:
//	set<string> wordSet;
//};


//前缀树（Trie）。
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() :isEnd(false), charVec(26,nullptr)
	{

	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		Trie* node = this;
		for (string::iterator it=word.begin();it!=word.end();it++)
		{
			if (node->charVec[*it - 'a'] == nullptr)
				node->charVec[*it - 'a'] = new Trie;
			node = node->charVec[*it - 'a'];
		}
		//此时 node 节点指向 word 单词的最后一个字母
		node->isEnd = true;
		node->endWord = word;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		Trie* node = this;
		for (string::iterator it = word.begin(); it != word.end(); it++)
		{
			if (node->charVec[*it - 'a'] == nullptr)
				return false;
			node = node->charVec[*it - 'a'];
		}
		//此时 node 节点指向 word 单词的最后一个字母
		return (node->isEnd == true); //检查 node 节点是否为词尾
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		Trie* node = this;
		for (string::iterator it = prefix.begin(); it != prefix.end(); it++)
		{
			if (node->charVec[*it - 'a'] == nullptr)
				return false;
			node = node->charVec[*it - 'a'];
		}
		//此时 node 节点指向 prefix 单词的最后一个字母
		return true;
	}
private:
	bool isEnd; //当前节点是否为词尾
	vector<Trie*> charVec; //孩子数组（存储当前节点的后缀节点）
	string endWord; //本例中非必须
};


int main208()
{
	Trie* obj = new Trie();
	//obj->insert("lpfhouyi");
	obj->insert("abc");
	//obj->insert("");
	obj->insert("lyz");
	//obj->insert("lyfhouyi");
	bool ret = obj->search("lyz");
	cout << "main：ret = " << ret << endl;
	ret = obj->startsWith("lyf");
	cout << "main：ret = " << ret << endl;
	return 0;
}