#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		max_sum = INT_MIN;
		maxPathSum_root(root);
		return max_sum;
	}
	int max_sum;
	int maxPathSum_root(TreeNode* root) {
		if (!root) return 0;
		int a = root->val;
		int b = maxPathSum_root(root->left);
		int c = maxPathSum_root(root->right);
		if (b > 0)
			a += b;
		if (c > 0)
			a += c;
		max_sum = max(max_sum, a);
		return max(b, c) > 0 ? max(b, c) + root->val : root->val;
	}
};


//int main() {
//	TreeNode* root = new TreeNode(5);
//	root->left = new TreeNode(4);
//	root->right = new TreeNode(8);
//	root->left->left = new TreeNode(11);
//	root->left->left->left = new TreeNode(7);
//	root->left->left->right = new TreeNode(2);
//	root->right->left = new TreeNode(13);
//	root->right->right = new TreeNode(4);
//	root->right->right->right = new TreeNode(1);
//	Solution s;
//	
//	cout<<s.maxPathSum(root);
//	cin.get();
//	return 0;
//}
