#include <iostream>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return head;
		//�����½ڵ�
		for (RandomListNode* p = head; p; ){
			RandomListNode* node = new RandomListNode(p->label);//ע��ֵ�ĸ���
			node->next = p->next;
			p->next = node;
			p = node->next;//ע��
		}
		//����������ӹ�ϵ
		for (RandomListNode* p = head; p; p = p->next->next){//ע��
			if (p->random)//ע��ǿղŸ�ֵ
				p->next->random = p->random->next;
		}
		//�������
		RandomListNode* new_head = head->next;
		RandomListNode* p1 = head->next;
		RandomListNode* p = head;
		while (p){
			p->next = p1->next;
			p = p->next;
			p1->next = p ? p->next : nullptr;//ע��
			p1 = p1->next;
		}
		return new_head;
	}
};