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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		if (!root) return result;
		if (!root->left && !root->right && root->val == sum) {
			vector<int> r = { root->val };
			result.push_back(r);
		}
		else {
			vector<vector<int>> left = pathSum(root->left, sum - root->val);
			vector<vector<int>> right = pathSum(root->right, sum - root->val);
			for (auto l : left) {
				l.insert(l.begin(), root->val);
				result.push_back(l);
			}
			for (auto r : right) {
				r.insert(r.begin(), root->val);
				result.push_back(r);
			}
			
		}
		return result;
	}
};
