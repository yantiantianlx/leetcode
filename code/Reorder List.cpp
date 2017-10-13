#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;
		ListNode* slow = head;
		ListNode* fast = head;
		//����ָ���м䣬ż��ָ���м��ǰһ��
		while (fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		//��slow�ĺ�߿�ʼ��
		ListNode* head2 = reverse(slow->next);
		slow->next = nullptr;
		//�ϲ���������
		for (ListNode *p1 = head, *p2 = head2; p2;){
			ListNode* temp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p1 = p2->next;
			p2 = temp;
		}
	}

private:
	ListNode* reverse(ListNode* head){
		if (!head || !head->next) return head;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur){
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};