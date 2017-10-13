#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return pathSum_root(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
	int pathSum_root(TreeNode* root, int sum) {
		if (!root) return 0;
		if (root->val == sum)
			return 1 + pathSum_root(root->left, sum - root->val) + pathSum_root(root->right, sum - root->val);
		else
			return pathSum_root(root->left, sum - root->val) + pathSum_root(root->right, sum - root->val);

	}
};