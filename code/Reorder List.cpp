#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;
		ListNode* slow = head;
		ListNode* fast = head;
		//奇数指向中间，偶数指向中间的前一个
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		//从slow的后边开始拆
		ListNode* head2 = reverse(slow->next);
		slow->next = nullptr;
		//合并两个链表
		for (ListNode *p1 = head, *p2 = head2; p2;){
			ListNode* temp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p1 = p2->next;
			p2 = temp;
		}
	}

private:
	ListNode* reverse(ListNode* head){
		if (!head || !head->next) return head;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur){
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};