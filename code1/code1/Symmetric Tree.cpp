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
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		else return isSym(root->left, root->right);
	}
private:
	bool isSym(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if (!p && q || p && !q) return false;
		else return p->val == q->val &&
			isSym(p->left, q->right) &&
			isSym(p->right, q->left);
	}
};