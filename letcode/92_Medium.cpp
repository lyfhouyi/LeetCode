#include<iostream>

using namespace std;

//给你单链表的头节点 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//
//
//提示：
//
//	链表中节点数目为 n
//	1 <= n <= 500
//	- 500 <= Node.val <= 500
//	1 <= left <= right <= n
//
//
//进阶： 你可以使用一趟扫描完成反转吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-linked-list-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct ListNode92 {
	int val;
	ListNode92 *next;
	ListNode92() : val(0), next(nullptr) {}
	ListNode92(int x) : val(x), next(nullptr) {}
	ListNode92(int x, ListNode92 *next) : val(x), next(next) {}
};


//单指针遍历链表。使用辅助指针实时记录正序的最后位置 lastNode ，逆序的首位置 reverseNode ，已操作的尾位置 currentNode 。
ListNode92* reverseBetween(ListNode92* head, int left, int right)
{
	ListNode92* ret = new ListNode92(0,head); //链表头
	ListNode92* currentNode = head; //尾节点
	ListNode92* lastNode = ret; //正序尾节点
	ListNode92* reverseNode = head; //逆序首节点
	int currentPos = 2; //当前位置
	head = head->next;
	ListNode92* tmp = nullptr; //记录原始链表中当前位置的下一节点
	while (head != nullptr && currentPos <= right)
	{
		tmp = head->next;
		if (currentPos > left) //交换节点
		{
			currentNode->next = tmp; //更新尾节点的下一节点

			//将当前节点插入至逆序首节点之前
			lastNode->next = head;
			head->next = reverseNode;

			reverseNode = lastNode->next; //更新逆序首节点（正序尾节点及尾节点无需更新）
		}
		else //非交换节点
		{
			//更新三个辅助指针
			reverseNode = head;
			currentNode = currentNode->next;
			lastNode = lastNode->next;
		}
		currentPos++;
		head = tmp;
	}
	return ret->next;
}


int main92()
{
	ListNode92* head = new ListNode92(1);
	head->next = new ListNode92(2);
	head->next->next = new ListNode92(3);
	head->next->next->next = new ListNode92(4);
	head->next->next->next->next = new ListNode92(5);
	head->next->next->next->next->next = new ListNode92(6);
	ListNode92* ret = reverseBetween(head, 1, 6);
	cout << "main：ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}