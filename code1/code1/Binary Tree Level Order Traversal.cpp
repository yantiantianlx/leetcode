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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		vector<TreeNode*> buf1;
		buf1.push_back(root);
		while (!buf1.empty()) {
			vector<TreeNode*> buf2;
			vector<int> r;
			for (auto b : buf1) {
				r.push_back(b->val);
				if (b->left)
					buf2.push_back(b->left);
				if (b->right)
					buf2.push_back(b->right);
			}
			result.push_back(r);
			buf1 = buf2;
		}
		//reverse(result.begin(), result.end());
		return result;
	}
};