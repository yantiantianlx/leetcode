#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* left = head;
		ListNode dummy_left(-1);
		dummy_left.next = left;
		ListNode* right = head->next;
		ListNode dummy_right(-1);
		dummy_right.next = right;
		head = head->next->next;
		int k = 0;
		while (head) {
			if (k % 2 == 0) {
				left->next = head;
				left = left->next;
			}
			else {
				right->next = head;
				right = right->next;
			}
			head = head->next;
			k++;
		}
		right->next = nullptr;
		left->next = dummy_right.next;
		return dummy_left.next;
	}
};