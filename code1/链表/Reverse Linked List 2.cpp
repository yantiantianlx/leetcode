#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		if (!head || !head->next || m == n) return head;
//		ListNode dummy(-1);
//		dummy.next = head;
//		ListNode* pre = &dummy;
//		n -= m;
//		while (--m) {
//			head = head->next;
//			pre = pre->next;
//		}
//		pre->next = reverseBetween(head->next, 1, n);
//		pre = pre->next;
//		while (pre && --n)
//			pre = pre->next;
//		head->next = pre->next;
//		pre->next = head;
//
//		return dummy.next;
//	}
//};
//
//ListNode* getList(vector<int> vec) {
//	ListNode dummy(-1);
//	ListNode* node = nullptr;
//	for (int i = 0; i < vec.size(); i++) {
//		if (i == 0) {
//			node = new ListNode(vec[i]);
//			dummy.next = node;
//		}
//		else {
//			node->next = new ListNode(vec[i]);
//			node = node->next;
//		}
//
//	}
//	return dummy.next;
//}
