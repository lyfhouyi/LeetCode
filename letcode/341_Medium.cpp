#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
//
//列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/flatten-nested-list-iterator
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class NestedInteger {
public:
	NestedInteger(vector<int> content) :content(content) {}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const
	{
		return content.size() == 1;
	}

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const
	{
		return content[0];
	}

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const
	{
		vector<NestedInteger> nestedList;
		return nestedList;
	}
private:
	vector<int> content;
};


//解法一：深度优先搜索。构造迭代器时，使用深度优先搜索将输入 nestedList 的全部整数值存入 valueVec 数组；随后基于 valueVec 数组实现 next() 及 hasNext() 函数；迭代器实际上是 valueVec 数组的索引 index 。
//class NestedIterator {
//public:
//	NestedIterator(const vector<NestedInteger> &nestedList)
//	{
//		dfs(nestedList); //储存 nestedList 的全部整数值
//		index = valueVec.size();
//	}
//
//	int next() //返回当前指针指向的整数元素
//	{
//		return valueVec[index];
//	}
//
//	bool hasNext() //若存在，则将当前指针指向下一整数元素
//	{
//		if (index == valueVec.size())
//			index = 0;
//		else
//			index++;
//		return index != valueVec.size();
//	}
//private:
//	vector<int> valueVec;
//	int index;
//	void dfs(const vector<NestedInteger> &nestedList)
//	{
//		int n = nestedList.size();
//		for (int i = 0; i < n; i++)
//		{
//			if (nestedList[i].isInteger())
//				valueVec.push_back(nestedList[i].getInteger());
//			else
//				dfs(nestedList[i].getList());
//		}
//	}
//};


//解法二：栈。使用一个栈，栈顶元素为当前指向的 NestedInteger 数组的索引及数组尾。当当前指向的下一个元素为一个 NestedInteger 数组时，将该 NestedInteger 数组的相关信息压栈。
class NestedIterator {
public:
	NestedIterator(const vector<NestedInteger> &nestedList)
	{
		itStack.push(make_pair(nestedList.cbegin(), nestedList.cend()));
	}
	int next() //返回当前指针指向的整数元素，并将指针指向下一 NestedInteger 元素
	{
		int ret = itStack.top().first->getInteger();
		itStack.top().first++;
		return ret;
	}
	bool hasNext() //若存在，则将当前指针置为其后第一个整数元素
	{
		while (!itStack.empty())
		{
			if (itStack.top().first == itStack.top().second)
			{
				itStack.pop();
				continue;
			}
			if (itStack.top().first->isInteger())
				return true;
			else
			{
				const vector<NestedInteger>& tmp = itStack.top().first->getList();
				itStack.top().first++;
				itStack.push(make_pair(tmp.cbegin(), tmp.cend()));
			}
		}
		return false;
	}
private:
	stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> itStack;
};


int main341()
{
	//vector<NestedInteger> nestedList = { NestedInteger({1,1}),NestedInteger({2}),NestedInteger({1,1}) };
	vector<NestedInteger> nestedList = { NestedInteger({1}),NestedInteger({2}),NestedInteger({3}) };
	NestedIterator i(nestedList);
	cout << "main：ret =";
	while (i.hasNext()) cout << i.next();
	return 0;
}