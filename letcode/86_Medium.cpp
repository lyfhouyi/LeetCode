#include<iostream>

using namespace std;


//����һ�������һ���ض�ֵ x �������������зָ���ʹ������С�� x �Ľڵ㶼�����ڴ��ڻ���� x �Ľڵ�֮ǰ��
//
//��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/partition-list
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



//��ָ���������
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
	cout << "main��ret=";
	while (ret != nullptr)
	{
		cout << ret->val << "  ";
		ret = ret->next;
	}
	return 0;
}