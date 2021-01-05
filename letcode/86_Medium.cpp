#include<iostream>

using namespace std;


//给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/partition-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



//单指针遍历链表
ListNode* partition(ListNode* head, int x)
{
	ListNode* lessList = nullptr;
	ListNode* greaterList = nullptr;
	ListNode* ret = nullptr;
	ListNode* greaterHead = nullptr;
	while (head != nullptr)
	{
		if (head->val < x)
		{
			if (lessList == nullptr)
			{
				lessList = head;
				ret = lessList;
			}
			else
			{
				lessList->next = head;
				lessList = lessList->next;
			}
		}
		else
		{
			if (greaterList == nullptr)
			{
				greaterList = head;
				greaterHead = greaterList;
			}
			else
			{
				greaterList->next = head;
				greaterList = greaterList->next;
			}
		}
		head = head->next;
	}
	if(greaterList!=nullptr)
		greaterList->next = nullptr;
	if (lessList != nullptr)
	{
		lessList->next = greaterHead;
		return ret;
	}
	return greaterHead;
}


int main86()
{
	ListNode* list = new ListNode(4);
	list->next = new ListNode(5);
	list->next->next = new ListNode(6);
	//list->next->next->next = new ListNode(2);
	//list->next->next->next->next = new ListNode(5);
	//list->next->next->next->next->next = new ListNode(2);



	ListNode* ret = partition(list, 3);
	cout << "main：ret=";
	while (ret != nullptr)
	{
		cout << ret->val << "  ";
		ret = ret->next;
	}
	return 0;
}