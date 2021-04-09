#include<iostream>

using namespace std;

//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//
//
//提示：
//
//	链表中节点的数目在范围[0, 500] 内
//	- 100 <= Node.val <= 100
//	0 <= k <= 2 * 10^9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/rotate-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


struct ListNode61 {
	int val;
	ListNode61 *next;
	ListNode61() : val(0), next(nullptr) {}
	ListNode61(int x) : val(x), next(nullptr) {}
	ListNode61(int x, ListNode61 *next) : val(x), next(next) {}
};


//单指针遍历链表。首先将链表的尾部与头部连接，构成环状链表，并记录节点总数 N ；随后将从 head 向后移动 N - k % N 步的节点设为新的头节点，并将从 head 向后移动 N - 1 - k % N 步的节点的 next 指针置空以作为尾节点即可。
ListNode61* rotateRight(ListNode61* head, int k)
{
	if (head == nullptr)
		return head;
	ListNode61* curNode = head;
	int nodeCnt = 1; //节点总数
	while (curNode->next != nullptr)
	{
		nodeCnt++;
		curNode = curNode->next;
	}
	curNode->next = head; //构成环状链表

	k %= nodeCnt;
	int step = 0;
	while (true) //设置新的头节点及相应的尾节点
	{
		curNode = head;
		head = head->next;
		step++;
		if (step == nodeCnt - k)
		{
			curNode->next = nullptr;
			break;
		}
	}
	return head;
}


int main61()
{
	//ListNode61* head = nullptr;
	ListNode61* head = new ListNode61(1);
	head->next = new ListNode61(2);
	head->next->next = new ListNode61(3);
	head->next->next->next = new ListNode61(4);
	head->next->next->next->next = new ListNode61(5);
	head->next->next->next->next->next = new ListNode61(6);
	ListNode61* ret = rotateRight(head, 2);
	cout << "main：ret = ";
	while (ret != nullptr)
	{
		cout << ret->val << ",";
		ret = ret->next;
	}
	return 0;
}