#include<iostream>
#include<vector>

using namespace std;

//��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ�䣨HashMap����
//
//ʵ�� MyHashMap �ࣺ
//
//	MyHashMap() �ÿ�ӳ���ʼ������
//	void put(int key, int value) �� HashMap ����һ����ֵ��(key, value) ����� key �Ѿ�������ӳ���У���������Ӧ��ֵ value ��
//	int get(int key) �����ض��� key ��ӳ��� value �����ӳ���в����� key ��ӳ�䣬���� - 1 ��
//	void remove(key) ���ӳ���д��� key ��ӳ�䣬���Ƴ� key ��������Ӧ�� value ��
//
//
//��ʾ��
//
//	0 <= key, value <= 106
//	������ 104 �� put��get �� remove ����
//
//
//���ף����ܷ�ʹ�����õ� HashMap ���������⣿
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/design-hashmap
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


//Ͱ
class MyHashMap {
public:
	/** Initialize your data structure here. */
	MyHashMap() :myBucket(vector<int>(1000001, -1))
	{

	}

	/** value will always be non-negative. */
	void put(int key, int value)
	{
		myBucket[key] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key)
	{
		return myBucket[key];
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key)
	{
		myBucket[key] = -1;
	}
private:
	vector<int> myBucket;
};


int main706()
{
	MyHashMap* obj = new MyHashMap();
	obj->put(10, 75);
	obj->remove(10);
	int ret = obj->get(10);
	cout << "main��ret = " << ret << endl;
	return 0;
}