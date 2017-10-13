#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return nullptr;
		ListNode* slow1 = head;
		ListNode* slow2 = head;
		ListNode* fast = head;
		while (fast && fast->next){
			slow1 = slow1->next;
			fast = fast->next->next;
			//有环则两个慢指针共同走知道相遇
			if (slow1 == fast){
				while (slow1 != slow2){
					slow1 = slow1->next;
					slow2 = slow2->next;
				}
				return slow1;
			}
		}
		return nullptr;
	}
};