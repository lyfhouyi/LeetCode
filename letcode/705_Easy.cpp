#include<iostream>
#include<vector>

using namespace std;

//��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ���ϣ�HashSet����
//
//ʵ�� MyHashSet �ࣺ
//
//	void add(key) ���ϣ�����в���ֵ key ��
//	bool contains(key) ���ع�ϣ�������Ƿ�������ֵ key ��
//	void remove(key) ������ֵ key �ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������
//
//
//��ʾ��
//
//	0 <= key <= 106
//	������ 104 �� add��remove �� contains ��
//
//
//���ף�����Բ�ʹ���ڽ��Ĺ�ϣ���Ͽ�����������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/design-hashset
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//Ͱ��
class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() :myBucket(vector<vector<bool>>(1001, vector<bool>(1000, false)))
	{

	}

	void add(int key)
	{
		myBucket[key / 1000][key % 1000] = true;
	}

	void remove(int key)
	{
		myBucket[key / 1000][key % 1000] = false;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key)
	{
		return myBucket[key / 1000][key % 1000];
	}
private:
	vector<vector<bool>> myBucket;
};


int main705()
{
	MyHashSet* obj = new MyHashSet();
	obj->add(1000000);
	obj->remove(29);
	bool ret = obj->contains(10);
	cout << "main��ret = " << ret << endl;
	return 0;
}