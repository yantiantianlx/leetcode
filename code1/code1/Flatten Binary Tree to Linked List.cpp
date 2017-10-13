#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		flat(root);
	}
	//·µ»ØÎ²½Úµã
	TreeNode* flat(TreeNode* root) {
		if (!root || (!root->left && !root->right) )
			return root;
		if (!root->left && root->right) 
			return flat(root->right);
		if (root->left && !root->right) {
			root->right = root->left;
			root->left = nullptr;
			return flat(root->right);
		}
		if(root->left && root->right){
			TreeNode* right = root->right;
			flat(root->left)->right = right;
			root->right = root->left;
			root->left = nullptr;
			return flat(right);
		}
	}
};

