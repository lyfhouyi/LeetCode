#include<iostream>

using namespace std;

//反转一个单链表。
//
//
//进阶 :
//	你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct ListNode206
{
	int val;
	ListNode206 *next;
	ListNode206() : val(0), next(nullptr) {}
	ListNode206(int x) : val(x), next(nullptr) {}
	ListNode206(int x, ListNode206 *next) : val(x), next(next) {}
};


//反转以 headNode 为首节点的全部链表，反转后链表的首节点保存在 headNode 中，尾节点保存在 lastNode 中。
void reverseListRecursion(ListNode206*& headNode, ListNode206*& lastNode)
{
	if (headNode->next == nullptr)
	{
		lastNode = headNode;
		return;
	}
	ListNode206* newLast;
	ListNode206* newHead = headNode->next;
	reverseListRecursion(newHead, newLast);
	newLast->next = headNode;
	lastNode = headNode;
	headNode->next = nullptr;
	headNode = newHead;
	return;
}


//解法一：迭代。单指针遍历链表。将当前节点置为首节点。
//ListNode206* reverseList(ListNode206* head)
//{
//	if (head == nullptr)
//		return nullptr;
//	ListNode206* ret = new ListNode206(0, head);
//	ListNode206* reverseNode = head;
//	ListNode206* currentNode = head;
//	ListNode206* tmp = nullptr;
//	head = head->next;
//	while (head != nullptr)
//	{
//		tmp = head->next;
//		currentNode->next = head->next;
//		ret->next = head;
//		head->next = reverseNode;
//		reverseNode = ret->next;
//		head = tmp;
//	}
//	return ret->next;
//}


//解法二：递归。递归反转第二个节点之后的链表。
//ListNode206* reverseList(ListNode206* head)
//{
//	if (head == nullptr)
//		return nullptr;
//	ListNode206* newLast;
//	reverseListRecursion(head, newLast);
//	return head;
//}


//解法三：迭代。单指针遍历链表。将当前节点的后继节点设为其前驱节点。
ListNode206* reverseList(ListNode206* head)
{
	ListNode206* preNode = nullptr;
	ListNode206* nextNode;
	while (head != nullptr)
	{
		nextNode = head->next;
		head->next = preNode;
		preNode = head;
		head = nextNode;
	}
	return preNode;
}


int main206()
{
	ListNode206* head = nullptr;
	//ListNode206* head = new ListNode206(1);
	//head->next = new ListNode206(2);
	//head->next->next = new ListNode206(3);
	//head->next->next->next = new ListNode206(4);
	//head->next->next->next->next = new ListNode206(5);
	//head->next->next->next->next->next = new ListNode206(6);
	ListNode206* ret = reverseList(head);
	cout << "main：ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}