#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		vector<TreeLinkNode*> node;
		if(root)
			node.push_back(root);
		while (!node.empty()) {
			vector<TreeLinkNode*> node1;
			int i;
			for (i = 0; i < node.size()-1; i++) {
				node[i]->next = node[i + 1];
				if(node[i]->left)
					node1.push_back(node[i]->left);
				if (node[i]->right)
					node1.push_back(node[i]->right);
			}
			node[i]->next = nullptr;
			if (node[i]->left)
				node1.push_back(node[i]->left);
			if (node[i]->right)
				node1.push_back(node[i]->right);
			node = node1;
		}
	}
};

class Solution1 {
public:
	void connect(TreeLinkNode *root) {
		return connect(root, nullptr);
	}
	void connect(TreeLinkNode* root, TreeLinkNode* next) {
		if (!root)
			return;
		else
			root->next = next;

		connect(root->left, root->right);
		if (next)
			connect(root->right, next->left);
		else
			connect(root->right, nullptr);
	}
};