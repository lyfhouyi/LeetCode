#include<iostream>

using namespace std;

//存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
//
//返回同样按升序排列的结果链表。
//
//
//提示：
//
//	链表中节点数目在范围[0, 300] 内
//	- 100 <= Node.val <= 100
//	题目数据保证链表已经按升序排列
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct ListNode82 {
	int val;
	ListNode82 *next;
	ListNode82() : val(0), next(nullptr) {}
	ListNode82(int x) : val(x), next(nullptr) {}
	ListNode82(int x, ListNode82 *next) : val(x), next(next) {}
};


//单指针遍历链表。使用辅助指针记录当前指针的前缀节点。若当前指针的后继节点与当前指针的值相同，则持续删除当前指针的后继节点后，删除当前指针节点。
ListNode82* deleteDuplicates(ListNode82* head) 
{
	ListNode82* ret = new ListNode82(0, head);
	ListNode82* preNode = ret;
	ListNode82* curNode = head;
	while (curNode != nullptr && curNode->next != nullptr)
	{
		if (curNode->next->val != curNode->val)
		{
			preNode = curNode;
			curNode = curNode->next;
		}
		else
		{
			while (curNode->next != nullptr && curNode->next->val == curNode->val)
			{
				curNode->next = curNode->next->next;
			}
			curNode = curNode->next;
			preNode->next = curNode;
		}
	}
	return ret->next;
}


int main82()
{
	ListNode82* head = new ListNode82(3);
	head->next = new ListNode82(3);
	head->next->next = new ListNode82(3);
	head->next->next->next = new ListNode82(3);
	head->next->next->next->next = new ListNode82(3);
	head->next->next->next->next->next = new ListNode82(6);
	ListNode82* ret = deleteDuplicates(head);
	cout << "main：ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}