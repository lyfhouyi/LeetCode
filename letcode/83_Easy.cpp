#include<iostream>

using namespace std;

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct ListNode83 {
	int val;
	ListNode83 *next;
	ListNode83() : val(0), next(nullptr) {}
	ListNode83(int x) : val(x), next(nullptr) {}
	ListNode83(int x, ListNode83 *next) : val(x), next(next) {}
};


//单指针遍历链表。若当前指针的后继节点与当前指针的值相同，则持续删除当前指针的后继节点。
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
	cout << "main：ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}