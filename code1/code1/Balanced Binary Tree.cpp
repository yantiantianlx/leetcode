#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//shabi ,beiyeyaobeiguo, qiushugaoa ,jizhua, zuobile, shabi
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return is_balanced(root) >= 0;
	}
	int is_balanced(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right)
			return 1;
		int l = is_balanced(root->left);
		int r = is_balanced(root->right);
		if ( l == -1 || r == -1 ||
			abs(l - r )> 1 ) return -1;
		return max(l, r) + 1;
	}
};
