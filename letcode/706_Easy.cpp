#include<iostream>
#include<vector>

using namespace std;

//不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
//
//实现 MyHashMap 类：
//
//	MyHashMap() 用空映射初始化对象
//	void put(int key, int value) 向 HashMap 插入一个键值对(key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
//	int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 - 1 。
//	void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
//
//
//提示：
//
//	0 <= key, value <= 106
//	最多调用 104 次 put、get 和 remove 方法
//
//
//进阶：你能否不使用内置的 HashMap 库解决此问题？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/design-hashmap
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//桶
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
	cout << "main：ret = " << ret << endl;
	return 0;
}