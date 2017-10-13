#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		if (lists.size() == 1) return lists[0];
		int min_index = find_min(lists);
		if (min_index == -1) return nullptr;
		ListNode* head = lists[min_index];
		if (!head->next)
			lists.erase(lists.begin() + min_index);
		else
			lists[min_index] = lists[min_index]->next;
		head->next = mergeKLists(lists);
		return head;
	}
	int find_min(vector<ListNode*>& lists) {
		int min = INT_MAX;
		int min_index = -1;
		for(int i = 0; i < lists.size(); i++)
			if (lists[i] && lists[i]->val < min) {
				min_index = i;
				min = lists[i]->val;
			}
		return min_index;
	}
};