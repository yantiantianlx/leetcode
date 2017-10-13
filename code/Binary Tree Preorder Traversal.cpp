#include "Header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//跟所在的位置：
//前序：根左右
//中序：左根右
//后序：左右根
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		result.push_back(root->val);
		vector<int> r;
		if (root->left){
			r = preorderTraversal(root->left);
			result.insert(result.end(), r.begin(), r.end());
		}
		if (root->right){
			r = preorderTraversal(root->right);
			result.insert(result.end(), r.begin(), r.end());
		}
		return result;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		
		vector<int> r;
		if (root->left){
			r = inorderTraversal(root->left);
			result.insert(result.end(), r.begin(), r.end());
		}
		result.push_back(root->val);
		if (root->right){
			r = inorderTraversal(root->right);
			result.insert(result.end(), r.begin(), r.end());
		}
		return result;
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;

		vector<int> r;
		if (root->left){
			r = postorderTraversal(root->left);
			result.insert(result.end(), r.begin(), r.end());
		}	
		if (root->right){
			r = postorderTraversal(root->right);
			result.insert(result.end(), r.begin(), r.end());
		}
		result.push_back(root->val);

		return result;
	}
};

void main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	Solution s;
	s.preorderTraversal(root);
}