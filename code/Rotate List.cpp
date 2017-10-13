#include <iostream>
#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		int n = 0;
		ListNode* tail = NULL;
		//求链表长度，并找尾巴
		for (ListNode* p = head; p; p = p->next){
			n++;
			if (!p->next)
				tail = p;
		}
		k = k % n;
		if(!k)
			return head;
		else{
			ListNode dummy(-1);
			dummy.next = head;
			ListNode* pre = &dummy;
			ListNode* p = head;
			int l = n - k;
			//找到断开处，并连接
			while (l--){
				p = p->next;
				pre = pre->next;
			}
			ListNode* new_head = p;
			tail->next = head;
			pre->next = nullptr;
			return new_head;
		}
	}
};

class Solution1 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || k == 0) return head;
		int n = 1;
		ListNode* p = head;
		//length为链表长度，p为链表尾节点
		while (p->next){
			n++;
			p = p->next;
		}
		k = k % n;

		//首尾相接
		p->next = head;
		for (int i = n - k; i > 0; i--){
			p = p->next;
		}
		ListNode* new_head = p->next;
		p->next = nullptr;
		return new_head;
	}
};

//void main(){
//	vector<int> v = { 1,2,3};
//	ListNode dummy(-1);
//	ListNode* p = &dummy;
//	for (int i = 0; i < v.size(); i++){
//		p->next = new ListNode(v[i]);
//		p = p->next;
//	}
//	p->next = NULL;
//	Solution s;
//	s.rotateRight(dummy.next,2000000000);
//}
