#include<iostream>
#include<vector>

using namespace std;

//不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
//
//实现 MyHashSet 类：
//
//	void add(key) 向哈希集合中插入值 key 。
//	bool contains(key) 返回哈希集合中是否存在这个值 key 。
//	void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//
//
//提示：
//
//	0 <= key <= 106
//	最多调用 104 次 add、remove 和 contains 。
//
//
//进阶：你可以不使用内建的哈希集合库解决此问题吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/design-hashset
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//桶。
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
	cout << "main：ret = " << ret << endl;
	return 0;
}