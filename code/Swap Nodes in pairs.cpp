#include <iostream>
#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* new_head = head->next;
		head->next = swapPairs(new_head->next);
		new_head->next = head;
		return new_head;
	}
};

class Solution1 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head && head->next){
			ListNode* newH = head->next;
			head->next = head->next->next;
			newH->next = head;
			head->next = swapPairs(head->next);
			return newH;
		}
		else
			return head;
	}
};

//void main(){
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	ListNode dummy(-1);
//	ListNode* p = &dummy;
//	for (int i = 0; i < v.size(); i++){
//		p->next = new ListNode(v[i]);
//		p = p->next;
//	}
//	p->next = NULL;
//	Solution s;
//	s.swapPairs(dummy.next);
//}
