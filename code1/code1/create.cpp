#include <iostream>
#include <vector>
using namespace std;

//����
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getList() {
	int num = 0;
	cout << "�����ȣ�";
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}

	ListNode dummy(-1);
	ListNode* p = &dummy;
	for (int i = 0; i < v.size(); i++) {
		p->next = new ListNode(v[i]);
		p = p->next;
	}
	p->next = NULL;
	return dummy.next;
}

//������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//ͨ��ǰ������ͺ���������������  
TreeNode* ConstructCore(vector<int> preOrder, vector<int> inOrder,
	int startPreorder, int endPreorder,
	int startInorder, int endInorder) {
	if (startPreorder > endPreorder || startInorder > endInorder) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(preOrder[startPreorder]);
	int divider = 0;
	while (divider < endInorder && inOrder[divider] != root->val) {
		divider++;
	}
	int offSet = divider - startInorder - 1;
	root->left = ConstructCore(preOrder, inOrder,
		startPreorder + 1, startPreorder + 1 + offSet,
		startInorder, divider - 1);

	root->right = ConstructCore(preOrder, inOrder,
		startPreorder + offSet + 2, endPreorder,
		divider + 1, endInorder);

	return root;
}

TreeNode* getBinary_Tree() {
	int num = 0;
	cout << "�ڵ�����";
	cin >> num;
	cout << "ǰ��������ݣ�";
	vector<int> preoder(num);
	for (int i = 0; i < num; i++) {
		cin >> preoder[i];
	}
	cout << "����������ݣ�";
	vector<int> inoder(num);
	for (int i = 0; i < num; i++) {
		cin >> inoder[i];
	}

	TreeNode* root = ConstructCore(preoder, inoder,0, num-1,0,num-1);
	return root;
}
