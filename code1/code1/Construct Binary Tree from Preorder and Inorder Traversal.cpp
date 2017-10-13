
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build_tree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	template<typename iterator>
	TreeNode* build_tree(iterator pre_first, iterator pre_last, iterator in_first, iterator in_last) {
		if(pre_first == pre_last) return nullptr;
		if(in_first == in_last) return nullptr;

		TreeNode* root = new TreeNode(*pre_first);
		iterator left_end = find(in_first, in_last, *pre_first);
		int left_size = left_end - in_first;

		root->left = build_tree(pre_first + 1, pre_first + 1 + left_size, in_first, left_end);
		root->right = build_tree(pre_first + 1 + left_size, pre_last, left_end+1, in_last);
		return root;
	}
};

