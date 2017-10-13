#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2) return nullptr;
		if (!l1 && l2) return l2;
		if (l1 && !l2) return l1;
		ListNode* head = nullptr;
		if (l1->val < l2->val) {
			head = l1;
			head->next = mergeTwoLists(l1->next, l2);
		}
		else {
			head = l2;
			head->next = mergeTwoLists(l1, l2->next);
		}
		return head;		
	}
};