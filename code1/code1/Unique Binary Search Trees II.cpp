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
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> r;
		if (n < 1) return r;
		return generate_tree(1, n);
	}
	vector<TreeNode*> generate_tree(int begin, int end) {
		vector<TreeNode*> result;
		if (begin > end) {
			result.push_back(nullptr);
			return result;
		}
		if (begin == end) {
			result.push_back(new TreeNode(begin));
			return result;
		}
		for (int i = begin; i <= end; i++) {
			vector<TreeNode*> left = generate_tree(begin, i - 1);
			vector<TreeNode*> right = generate_tree(i + 1, end);
			for (auto l : left) {
				for (auto r : right) {
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					result.push_back(root);
				}
			}
		}
		return result;
	}
};

