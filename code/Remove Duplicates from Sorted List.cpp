#include <iostream>
#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		for (ListNode* p = head; p;){
			if ( p->next && p->val == p->next->val){
				ListNode* q = p->next;
				p->next = q->next;
				delete q;
			}
			else
				p = p->next;
		}
		return head;
	
	}
};
class Solution1 {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr) return nullptr;
		for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next) {
			if (prev->val == cur->val) {
				prev->next = cur->next;
				delete cur;
			}
			else {
				prev = cur;
			}
		}
		return head;
	}
};

//void main(){
//	vector<int> v = { 1, 1, 1 };
//	ListNode dummy(-1);
//	ListNode* p = &dummy;
//	for (int i = 0; i < v.size(); i++){
//		p->next = new ListNode(v[i]);
//		p = p->next;
//	}
//	p->next = NULL;
//	Solution s;
//	s.deleteDuplicates(dummy.next);
//}