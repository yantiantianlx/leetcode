#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode dummy(-1);
		for (TreeLinkNode* cur = root, *pre = &dummy; cur; cur = cur->next) {
			if (cur->left) {
				pre->next = cur->left;
				pre = pre->next;
			}if (cur->right) {
				pre->next = cur->right;
				pre = pre->next;
			}
		}
		connect(dummy.next);
	}
};