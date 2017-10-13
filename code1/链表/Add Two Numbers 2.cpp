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

class Solution1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* node1 = l1;
		ListNode* node2 = l2;
		while (node1 && node2) {
			node1 = node1->next;
			node2 = node2->next;
		}
		if (node2) {
			ListNode* node = l1;
			l1 = l2;
			l2 = node;
			node1 = node2;
			node2 = nullptr;
		}
		ListNode* dummy = new ListNode(1);
		dummy->next = l1;
		ListNode* dummy2 = new ListNode(0);
		node2 = dummy2;
		while (node1) {
			node1 = node1->next;
			node2->next = new ListNode(0);
			node2 = node2->next;
		}
		node2->next = l2;
		int c = addTwo(dummy->next, dummy2->next);
		if (c == 0)
			return dummy->next;
		else
			return dummy;
	}
	int addTwo(ListNode* & l1, ListNode* & l2) {
		if (!l2) return 0;
		int c = addTwo(l1->next, l2->next);
		int num = l1->val + l2->val + c;
		l1->val = num % 10;
		return num / 10;
	}
};

ListNode* getList(vector<int> vec) {
	ListNode dummy(-1);
	ListNode* node = nullptr;
	for (int i = 0; i < vec.size(); i++) {
		if (i == 0) {
			node = new ListNode(vec[i]);
			dummy.next = node;
		}
		else {
			node->next = new ListNode(vec[i]);
			node = node->next;
		}

	}
	return dummy.next;
}


int main() {
	
}

