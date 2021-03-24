#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//����һ��Ƕ�׵������б��������һ����������ʹ���ܹ�������������б��е�����������
//
//�б��е�ÿһ�����Ϊһ����������������һ���б������б��Ԫ��Ҳ�������������������б�
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/flatten-nested-list-iterator
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


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


//�ⷨһ������������������������ʱ��ʹ������������������� nestedList ��ȫ������ֵ���� valueVec ���飻������ valueVec ����ʵ�� next() �� hasNext() ������������ʵ������ valueVec ��������� index ��
//class NestedIterator {
//public:
//	NestedIterator(const vector<NestedInteger> &nestedList)
//	{
//		dfs(nestedList); //���� nestedList ��ȫ������ֵ
//		index = valueVec.size();
//	}
//
//	int next() //���ص�ǰָ��ָ�������Ԫ��
//	{
//		return valueVec[index];
//	}
//
//	bool hasNext() //�����ڣ��򽫵�ǰָ��ָ����һ����Ԫ��
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


//�ⷨ����ջ��ʹ��һ��ջ��ջ��Ԫ��Ϊ��ǰָ��� NestedInteger ���������������β������ǰָ�����һ��Ԫ��Ϊһ�� NestedInteger ����ʱ������ NestedInteger ����������Ϣѹջ��
class NestedIterator {
public:
	NestedIterator(const vector<NestedInteger> &nestedList)
	{
		itStack.push(make_pair(nestedList.cbegin(), nestedList.cend()));
	}
	int next() //���ص�ǰָ��ָ�������Ԫ�أ�����ָ��ָ����һ NestedInteger Ԫ��
	{
		int ret = itStack.top().first->getInteger();
		itStack.top().first++;
		return ret;
	}
	bool hasNext() //�����ڣ��򽫵�ǰָ����Ϊ����һ������Ԫ��
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
	cout << "main��ret =";
	while (i.hasNext()) cout << i.next();
	return 0;
}