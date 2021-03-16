#include<iostream>
#include<stack>

using namespace std;

//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//	void push(int x) 将元素 x 推到队列的末尾
//	int pop() 从队列的开头移除并返回元素
//	int peek() 返回队列开头的元素
//	boolean empty() 如果队列为空，返回 true ；否则，返回 false
//
//
//说明：
//
//	你只能使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//	你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//
//
//进阶：
//
//	你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
//
//
//提示：
//
//	1 <= x <= 9
//	最多调用 100 次 push、pop、peek 和 empty
//	假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-queue-using-stacks
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//维护两个栈。一个正序栈，负责压入队列；一个逆序栈，负责弹出队列。
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue()
	{

	}

	/** Push element x to the back of queue. */
	void push(int x) 
	{
		sPositive.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() 
	{
		if (sNegative.empty())
			this->getInverted();
		int ret = sNegative.top();
		sNegative.pop();
		return ret;
	}

	/** Get the front element. */
	int peek() 
	{
		if (sNegative.empty())
			this->getInverted();
		return sNegative.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() 
	{
		if (sNegative.empty())
			this->getInverted();
		return sNegative.empty();
	}

private:
	stack<int> sPositive;
	stack<int> sNegative;

	//将正序栈中的元素装入逆序栈
	void getInverted()
	{
		while (!sPositive.empty())
		{
			sNegative.push(sPositive.top());
			sPositive.pop();
		}
	}
};


int main232()
{
	MyQueue* obj = new MyQueue();
	obj->push(10);
	obj->push(20);
	int test = obj->pop();
	cout << test << endl;
	test = obj->peek();
	cout << test << endl;
	test = obj->empty();
	cout << test << endl;
	return 0;
}