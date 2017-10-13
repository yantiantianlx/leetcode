#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return true;
		if (root->left && !root->right) {
			if (root->val > max(root->left))
				return isValidBST(root->left);
			else
				return false;
		}
		else if (!root->left && root->right) {
			if (root->val < min(root->right))
				return isValidBST(root->right);
			else
				return false;
		}
		else if(root->left && root->right) {
			if ((root->val < min(root->right)) && (root->val > max(root->left)) )
				return isValidBST(root->left) && isValidBST(root->right);
			else
				return false;
		}
	}

	int min(TreeNode* root) {
		while (root->left) {
			root = root->left;
		}
		return root->val;
	}
	int max(TreeNode* root) {
		while (root->right) {
			root = root->right;
		}
		return root->val;
	}
};

class Solution1 {
public:
	TreeNode* pre = nullptr;
	bool isValidBST(TreeNode* root) {
		return isValidInorder(root);
	}
	bool isValidInorder(TreeNode* root) {
		if (!root) return true;
		if (!isValidInorder(root->left))
			return false;
		if (pre && pre->val >= root->val)
			return false;
		pre = root;
		return isValidInorder(root->right);
	}
};
class Solution3 {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* pre = nullptr;
		return traverse(root, pre);
	}
	bool traverse(TreeNode* root, TreeNode* &pre) {
		if (!root) return true;
		if (!traverse(root->left, pre)) return false;
		if (!pre && pre->val >= root->val) return false;
		pre = root;
		return traverse(root->right, pre);
	}
};
