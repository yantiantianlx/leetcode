#include <iostream>
#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next || k == 1) return head;
		ListNode* p = head;
		int i = 0;
		for (; p && i < k; i++)
			p = p->next;
		if (i < k)
			return head;
		ListNode* next_group_new_head = reverseKGroup(p, k);
		ListNode* pre = nullptr; ListNode* cur = head;
		while (cur != p){
			ListNode* next = cur->next;
			cur->next = pre == nullptr ? next_group_new_head : pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};

//void main(){
//	vector<int> v = { 1,2,3};
//	ListNode dummy(-1);
//	ListNode* p = &dummy;
//	for (int i = 0; i < v.size(); i++){
//		p->next = new ListNode(v[i]);
//		p = p->next;
//	}
//	p->next = NULL;
//	Solution s;
//	s.reverseKGroup(dummy.next,2);
//}