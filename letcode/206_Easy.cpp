#include<iostream>

using namespace std;

//��תһ��������
//
//
//���� :
//	����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/reverse-linked-list
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct ListNode206
{
	int val;
	ListNode206 *next;
	ListNode206() : val(0), next(nullptr) {}
	ListNode206(int x) : val(x), next(nullptr) {}
	ListNode206(int x, ListNode206 *next) : val(x), next(next) {}
};


//��ת�� headNode Ϊ�׽ڵ��ȫ��������ת��������׽ڵ㱣���� headNode �У�β�ڵ㱣���� lastNode �С�
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


//�ⷨһ����������ָ�������������ǰ�ڵ���Ϊ�׽ڵ㡣
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


//�ⷨ�����ݹ顣�ݹ鷴ת�ڶ����ڵ�֮�������
//ListNode206* reverseList(ListNode206* head)
//{
//	if (head == nullptr)
//		return nullptr;
//	ListNode206* newLast;
//	reverseListRecursion(head, newLast);
//	return head;
//}


//�ⷨ������������ָ�������������ǰ�ڵ�ĺ�̽ڵ���Ϊ��ǰ���ڵ㡣
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
	cout << "main��ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}