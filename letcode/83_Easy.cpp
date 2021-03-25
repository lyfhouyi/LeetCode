#include<iostream>

using namespace std;

//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct ListNode83 {
	int val;
	ListNode83 *next;
	ListNode83() : val(0), next(nullptr) {}
	ListNode83(int x) : val(x), next(nullptr) {}
	ListNode83(int x, ListNode83 *next) : val(x), next(next) {}
};


//��ָ�������������ǰָ��ĺ�̽ڵ��뵱ǰָ���ֵ��ͬ�������ɾ����ǰָ��ĺ�̽ڵ㡣
ListNode83* deleteDuplicates(ListNode83* head)
{
	if (head == nullptr)
		return head;
	ListNode83* ret = head;
	while (head->next != nullptr)
	{
		if (head->next->val != head->val)
		{
			head = head->next;
		}
		else
		{
			while (head->next != nullptr && head->next->val == head->val)
			{
				head->next = head->next->next;
			}
		}
	}
	return ret;
}


int main83()
{
	ListNode83* head = nullptr;
	//ListNode83* head = new ListNode83(1);
	//head->next = new ListNode83(3);
	//head->next->next = new ListNode83(3);
	//head->next->next->next = new ListNode83(3);
	//head->next->next->next->next = new ListNode83(3);
	//head->next->next->next->next->next = new ListNode83(3);
	ListNode83* ret = deleteDuplicates(head);
	cout << "main��ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}