 #include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1); // ???
		int c = 0;
		ListNode *sum = &dummy;
		for (ListNode *p1 = l1, *p2 = l2; p1 != NULL || p2 != NULL;
			p1 = p1 == NULL ? NULL : p1->next,
			p2 = p2 == NULL ? NULL : p2->next,
			sum = sum->next){
			int a = p1 == NULL ? 0 : p1->val;
			int b = p2 == NULL ? 0 : p2->val;
			sum->next = new ListNode((a+b+c)%10);
			c = (a + b + c) / 10;
		}
		if (c > 0){
			sum->next = new ListNode(c);
		}
		return dummy.next;
	}
};