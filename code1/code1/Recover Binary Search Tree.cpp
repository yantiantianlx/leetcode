#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

///大大的教训，大傻叉，大大傻叉

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> res;
		traverse(root, res);
		int n = res.size();
		int i = 0;
		for (; i < n - 1; i++) {
			if (res[i]->val > res[i + 1]->val)
				break;
		}
		int j = i + 2;
		for (; j < n; j++) {
			if (res[j]->val < res[j - 1]->val)
				break;
		}
		if (j<n)
			swap(res[i]->val, res[j]->val);
		else
			swap(res[i]->val, res[i + 1]->val);
	}
	void traverse(TreeNode* root, vector<TreeNode*>& res) {
		if (!root) return;
		traverse(root->left, res);
		res.push_back(root);
		traverse(root->right, res);
	}
};
