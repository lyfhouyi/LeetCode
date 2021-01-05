#include<iostream>

using namespace std;


//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//	输出：7 -> 0 -> 8
//	原因：342 + 465 = 807

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-two-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。





struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int getVal(ListNode * pos,bool& emptyFlag)
{
	if (nullptr == pos)
	{
		emptyFlag = true;
		return 0;
	}
	return pos->val;
}

//带进位标志位的十进制数位加法
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int carryBit = 0; //进位标志符
	bool empty_l1 = false; //空位标志位
	bool empty_l2 = false; //空位标志位
	ListNode* pos = new ListNode;
	ListNode* lastPos = nullptr;
	ListNode* ret = pos;
	while (true)
	{
		empty_l1 = false;
		empty_l2 = false;
		pos->val = (carryBit + getVal(l1, empty_l1) + getVal(l2, empty_l2)) % 10;
		carryBit = (carryBit + getVal(l1, empty_l1) + getVal(l2, empty_l2)) / 10;
		if (nullptr != l1)
			l1 = l1->next;
		if (nullptr != l2)
			l2 = l2->next;
		if ((!pos->val) && (!carryBit) &&(empty_l1) && (empty_l2))
			break;
		pos->next = new ListNode;
		lastPos = pos;
		pos = pos->next;
	}
	lastPos->next = nullptr;
	delete pos;
	return ret;
}

int main2()
{
	ListNode* l1 = new ListNode(0);
	//l1->next = new ListNode(0);
	//l1->next->next = new ListNode(4);
	//l1->next->next->next = new ListNode(4);

	ListNode* l2 = new ListNode(0);
	//l2->next = new ListNode(0);
	//l2->next->next = new ListNode(6);
	//l2->next->next->next = new ListNode(6);
	//l2->next->next->next->next = new ListNode(9);

	ListNode* ret = addTwoNumbers(l1, l2);
	cout << "main：ret=";
	while (ret != nullptr)
	{
		cout << ret->val << "  ";
		ret = ret->next;
	}
	return 0;
}