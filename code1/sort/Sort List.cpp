#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//超时
class Solution1 {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* next = head->next;
		head->next = nullptr;
		return mergeTwoLists(head, sortList(next));
	}
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

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		//快慢指针,找中间节点
		ListNode dummmy(-1);
		dummmy.next = head;
		ListNode* slow = &dummmy;
		ListNode* fast = head;
		while (fast && fast->next)
			slow = slow->next, fast = fast->next->next;
		//截断
		ListNode* right = slow->next;
		slow->next = nullptr;
		return mergeTwoLists(sortList(head), sortList(right));
	}
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
