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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums.begin(), nums.end());

	}
	template<typename iterator>
	TreeNode* sortedArrayToBST(iterator begin, iterator end) {
		if (begin >= end) return nullptr;
		int mid = (end - begin) / 2;
		TreeNode* root = new TreeNode(*(begin + mid));
		root->left = sortedArrayToBST(begin, begin + mid);
		root->right = sortedArrayToBST(begin + mid + 1, end);
		return root;
	}
};

