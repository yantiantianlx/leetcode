#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode dummy(INT_MIN);
		for (ListNode* cur = head; cur;) {
			ListNode* insert = find_pos(&dummy, cur->val);
			ListNode* next = cur->next;
			cur->next = insert->next;
			insert->next = cur;
			cur = next;
		}
		return dummy.next;

	}
	//寻找插入位置,相同时插入在最后一个相同元素的后边
	ListNode* find_pos(ListNode* dummy, int val) {
		ListNode* pre = nullptr;
		for (ListNode* cur = dummy; cur && cur->val <= val; pre = cur, cur = cur->next);
		return pre;
	}
};

