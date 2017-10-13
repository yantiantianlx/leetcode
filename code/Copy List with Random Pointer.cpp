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
		//插入新节点
		for (RandomListNode* p = head; p; ){
			RandomListNode* node = new RandomListNode(p->label);//注意值的复制
			node->next = p->next;
			p->next = node;
			p = node->next;//注意
		}
		//建立随机连接关系
		for (RandomListNode* p = head; p; p = p->next->next){//注意
			if (p->random)//注意非空才赋值
				p->next->random = p->random->next;
		}
		//拆分链表
		RandomListNode* new_head = head->next;
		RandomListNode* p1 = head->next;
		RandomListNode* p = head;
		while (p){
			p->next = p1->next;
			p = p->next;
			p1->next = p ? p->next : nullptr;//注意
			p1 = p1->next;
		}
		return new_head;
	}
};