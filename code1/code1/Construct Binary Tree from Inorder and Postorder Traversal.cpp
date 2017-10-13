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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build_tree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}

	template<typename iterator>
	TreeNode* build_tree(iterator in_first, iterator in_last, iterator pos_first, iterator pos_last) {
		if (in_first == in_last) return nullptr;
		if (pos_first == pos_last) return nullptr;

		TreeNode* root = new TreeNode(*(pos_last - 1));
		iterator left_end = find(in_first, in_last, *(pos_last - 1));
		int left_size = left_end - in_first;

		root->left = build_tree(in_first, left_end, pos_first, pos_first + left_size);
		root->right = build_tree(left_end + 1, in_last, pos_first + left_size, pos_last-1);

		return root;
	}
};
