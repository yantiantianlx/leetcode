#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	ListNode* list = nullptr;
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* node = head;
		while (node) {
			node = node->next;
			len++;
		}
		list = head;
		return sortedListToBST(0, len - 1);
	}

	TreeNode* sortedListToBST( int begin, int end) {
		if (begin > end) return nullptr;
		int mid = begin + (end - begin) / 2;
		TreeNode* left = sortedListToBST(begin, mid - 1);
		TreeNode* root = new TreeNode(list->val);
		root->left = left;
		list = list->next;
		root->right = sortedListToBST(mid + 1, end);
		return root;
	}
};