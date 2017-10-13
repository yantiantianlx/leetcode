#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	TreeNode* maxNode(TreeNode* root){
		if (!root || (!root->left && !root->right)) return root;
		else if (root->left && !root->right) {
			TreeNode* l = maxNode(root->left);
			return (l->val > root->val)? l : root;
		}
		else if (!root->left && root->right) {
			TreeNode* r = maxNode(root->right);
			return (r->val > root->val) ? r :  root;
		}
		else if (root->left && root->right) {
			TreeNode* l = maxNode(root->left);
			TreeNode* r = maxNode(root->right);
			return ((l->val > r->val) && (l->val > root->val)) ? l :
				   ((r->val > l->val) && (r->val > root->val)) ? r : root;
		}
	}
};


class Solution1 {
public:
	/**
	* @param root the root of binary tree
	* @return the max node
	*/
	TreeNode * result;
	TreeNode* maxNode(TreeNode* root) {
		// Write your code here
		if (!root)
			return nullptr;
		if ((root->left) && (root->right))
		{
			if (root->val >= maxNode(root->left)->val && root->val >= maxNode(root->right)->val)
				return root;
			if (maxNode(root->left)->val >= root->val && maxNode(root->left)->val >= maxNode(root->right)->val)
				return maxNode(root->left);
			if (maxNode(root->right)->val >= root->val && maxNode(root->right)->val >= maxNode(root->left)->val)
				return maxNode(root->right);
		}
		else if ((root->left) && !(root->right))
			return maxNode(root->left)->val >= root->val ? maxNode(root->left) : root;
		else if (!(root->left) && (root->right))
			return maxNode(root->right)->val >= root->val ? maxNode(root->right) : root;
		else
			return root;
	}
};
