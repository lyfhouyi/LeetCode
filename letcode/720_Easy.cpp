#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

//����һ���ַ�������words��ɵ�һ��Ӣ��ʵ䡣�����ҳ����һ�����ʣ��õ�������words�ʵ����������������һ����ĸ��ɡ��������ж�����еĴ𰸣��򷵻ش����ֵ�����С�ĵ��ʡ�
//
//���޴𰸣��򷵻ؿ��ַ�����
//
//
//��ʾ��
//
//	����������ַ�����ֻ����Сд��ĸ��
//	words���鳤�ȷ�ΧΪ[1, 1000]��
//	words[i]�ĳ��ȷ�ΧΪ[1, 30]��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/longest-word-in-dictionary
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//ǰ׺���ڵ�
class TrieNode720
{
public:
	TrieNode720() :isEnd(false), charVec(26) {}

	bool isEnd; //��ǰ�ڵ��Ƿ�Ϊ��β
	vector<TrieNode720*> charVec; //�������飨�洢��ǰ�ڵ�ĺ�׺�ڵ㣩
	string endWord; //�ⷨ��ʹ��
};


//ǰ׺����Trie����
class Trie720 {
public:
	Trie720() :root(root), height(0)
	{
		root = new TrieNode720;
	}

	void insert(string word)
	{
		TrieNode720* node = this->root;
		for (string::iterator it = word.begin(); it != word.end(); it++)
		{
			if (node->charVec[*it - 'a'] == nullptr)
				node->charVec[*it - 'a'] = new TrieNode720;
			node = node->charVec[*it - 'a'];
		}
		//��ʱ node �ڵ�ָ�� word ���ʵ����һ����ĸ
		node->isEnd = true;
		node->endWord = word;
	}

	bool search(string word)
	{
		TrieNode720* node = this->root;
		for (string::iterator it = word.begin(); it != word.end(); it++)
		{
			if (node->charVec[*it - 'a'] == nullptr)
				return false;
			node = node->charVec[*it - 'a'];
		}
		//��ʱ node �ڵ�ָ�� word ���ʵ����һ����ĸ
		return (node->isEnd == true); //��� node �ڵ��Ƿ�Ϊ��β
	}

	bool startsWith(string prefix)
	{
		TrieNode720* node = this->root;
		for (string::iterator it = prefix.begin(); it != prefix.end(); it++)
		{
			if (node->charVec[*it - 'a'] == nullptr)
				return false;
			node = node->charVec[*it - 'a'];
		}
		//��ʱ node �ڵ�ָ�� prefix ���ʵ����һ����ĸ
		return true;
	}
	//����Ϊͨ���෽��

	bool insert2(string word) //�ⷨ��ʹ�ã�����һ���ַ����������ظ��ַ����Ƿ�Ϊ�������ַ�����
	{
		bool ret = true;
		TrieNode720* node = this->root;
		int n = word.length();
		for (int i = 0; i < n; i++)
		{
			if (node->charVec[word[i] - 'a'] == nullptr)
				node->charVec[word[i] - 'a'] = new TrieNode720;
			node = node->charVec[word[i] - 'a'];
			if (i != n - 1 && node->isEnd == false) //ǰ׺���в����������ַ�����ĳǰ׺
				ret = false;
		}
		//��ʱ node �ڵ�ָ�� word ���ʵ����һ����ĸ
		node->isEnd = true;
		node->endWord = word;
		return ret;
	}

	void dfs(TrieNode720* node, int currentHeight) //�ⷨ��ʹ�ã��������������������
	{
		if (node == nullptr || (currentHeight > 0 && node->isEnd == false)) //ǰ׺�������Ե�ǰ�ڵ�Ϊ��β���ַ���
			return;
		if (currentHeight > this->height)
		{
			this->height = currentHeight;
			this->s = node->endWord;
		}
		for (vector<TrieNode720*>::iterator it = node->charVec.begin(); it != node->charVec.end(); it++)
		{
			dfs(*it, currentHeight + 1);
		}
	}

	string calcHeight() //�ⷨ��ʹ�ã��ҵ�����Ҫ�����ַ���
	{
		this->dfs(this->root, 0);
		return this->s;
	}
private:
	TrieNode720* root;
	int height; //�ⷨ��ʹ�ã�����Ҫ�����ַ�����������
	string s; //�ⷨ��ʹ�ã�����Ҫ�����ַ���
};


//�ⷨһ����ϣ�����Ƚ�ԭʼ�ַ������鰴�������������������ַ��������и��ַ�����ʹ�ù�ϣ���ж����Ƿ�Ϊ�������ַ�����������¼������ġ������ַ�������Ϊ����ֵ�����ҽ���������������֮һʱ���ַ��� s[0,n] Ϊ�������ַ�������1.�ַ�������Ϊ 1 ���� n==0 ��2. s[0,n - 1] Ϊ�������ַ�������
//string longestWord(vector<string>& words)
//{
//	sort(words.begin(), words.end());
//	map<string, bool> builtMap; //��ϣ����¼���ַ����Ƿ�Ϊ�������ַ�����
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


//�ⷨ����ǰ׺�������Ƚ�ԭʼ�ַ������鰴�������������������ַ��������и��ַ��������ν������ǰ׺�����ڲ�������Ĺ������жϸ��ַ����Ƿ�Ϊ�������ַ�����������¼������ġ������ַ�������Ϊ����ֵ�����ҽ���������������ʱ���ַ��� s[0,n] Ϊ�������ַ�������ǰ׺���а����ַ��� s[0,n] ������ǰ׺��
//string longestWord(vector<string>& words)
//{
//	sort(words.begin(), words.end());
//	Trie720* obj = new Trie720();
//	string ret;
//	int maxLength = 0;
//	bool isBuilt;
//	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
//	{
//		isBuilt = obj->insert2(*it);
//		if (isBuilt == true && it->length() > maxLength)
//		{
//			maxLength = it->length();
//			ret = *it;
//		}
//	}
//	return ret;
//}


//�ⷨ����ǰ׺���������ַ��������и��ַ��������ν������ǰ׺����������ǰ׺��������Ҫ�����ַ���������Ҫ��ָ���ַ���������ǰ׺����ǰ׺���С�
string longestWord(vector<string>& words)
{
	Trie720* obj = new Trie720();
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
		obj->insert(*it);
	return obj->calcHeight();
}

int main720()
{
	//vector<string> test = { "ts", "e", "x", "pbhj", "opto", "xhigy", "erikz", "pbh", "opt", "erikzb", "eri", "erik", "xlye", "xhig", "optoj", "optoje", "xly", "pb", "xhi", "x", "o" };
	vector<string> test = { "a","banana", "app", "appl", "ap", "apply", "apple" };
	string ret = longestWord(test);
	cout << "main��ret = " << ret << endl;
	return 0;
}