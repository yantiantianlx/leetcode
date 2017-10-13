#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode dummy1(-1), dummy2(-1);
		ListNode* left = &dummy1;
		ListNode* right = &dummy2;
		ListNode* node = head;
		while (node){
			if (node->val < x){
				left->next = node;
				left = left->next;
			}
			else{
				right->next = node;
				right = right->next;
			}	
			node = node->next;
		}
		left->next = dummy2.next;
		right->next = NULL;
		return dummy1.next;
	}
};