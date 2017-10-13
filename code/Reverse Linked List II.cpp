#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* pre = &dummy;
		for (int i = 0; i < m - 1; i++){
			pre = pre->next;
		}
		ListNode* head2 = pre;
		pre = pre->next;
		ListNode* cur = pre->next;
		for (int i = m; i < n; i++){
			pre->next = cur->next;
			cur->next = head2->next;
			head2->next = cur;
			cur = pre->next;
		}
		return dummy.next;
	}
};