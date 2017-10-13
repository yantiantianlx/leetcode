#include <iostream>
#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* p1 = &dummy, *p2 = &dummy;
		for (int i = 0; i < n; i++)
			p1 = p1->next;
		//p1��p2��n����p1��βʱ��p2ָ��ɾԪ�ص���һ��
		while (p1->next){
			p1 = p1->next;
			p2 = p2->next;
		}
		ListNode* del = p2->next;
		p2->next = p2->next->next;
		delete del;
		return dummy.next;
	}
};

//void main(){
//	vector<int> v = {1,2,3,4,5};
//	ListNode dummy(-1);
//	ListNode* p = &dummy;
//	for (int i = 0; i < v.size(); i++){
//		p->next = new ListNode(v[i]);
//		p = p->next;
//	}
//	p->next = NULL;
//	Solution s;
//	s.removeNthFromEnd(dummy.next,2);
//}
