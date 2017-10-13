#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		return sumNumbers(root, 0);
	}
	int sumNumbers(TreeNode* root, int sum) {
		if (!root) return 0;
		if (!root->left && !root->right)
			return sum * 10 + root->val;
		return sumNumbers(root->left, sum * 10 + root->val) +
			sumNumbers(root->right, sum * 10 + root->val);
	}
};