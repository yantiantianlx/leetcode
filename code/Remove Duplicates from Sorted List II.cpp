#include <iostream>
#include "Header.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* pre = &dummy;
		int del = 0;
		for (ListNode* p = head; p;){
			//ɾ����ͬԪ��
			while (p->next && p->val == p->next->val){
				ListNode* q = p->next;
				p->next = p->next->next;
				delete q;
				del = 1;
			}
			//delɾ�����µ�һ����ͬԪ��
			if (del == 1){
				ListNode* q = p;
				pre->next = p->next;
				p = pre->next;
				delete q;
				del = 0;
			}
			//��������
			else{
				p = p->next;
				pre = pre->next;
			}	
		}
		return dummy.next;
	}
};

//void main(){
//		vector<int> v = {1,1,2,3,3,5};
//		ListNode dummy(-1);
//		ListNode* p = &dummy;
//		for (int i = 0; i < v.size(); i++){
//			p->next = new ListNode(v[i]);
//			p = p->next;
//		}
//		p->next = NULL;
//		Solution s;
//		s.deleteDuplicates(dummy.next);
//	
//}
