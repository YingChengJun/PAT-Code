#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int val;
	int height = 0;
	Node* left = NULL;
	Node* right = NULL;
	Node(int val) : val(val) {};
};

int height(Node* node) {
	if (node == NULL) return -1;
	return node->height;
}

void ll(Node*& root) {
	Node* child = root->left;
	root->left = child->right;
	child->right = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	child->height = max(height(child->left), height(child->right)) + 1;
	root = child;
}

void rr(Node*& root) {
	Node* child = root->right;
	root->right = child->left;
	child->left = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	child->height = max(height(child->left), height(child->right)) + 1;
	root = child;
}

void insert(Node*& root, int val) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}
	if (val < root->val) {
		insert(root->left, val);
		if (height(root->left) - height(root->right) == 2) {
			if (val < root->left->val) {
				ll(root);
			} else {
				rr(root->left);
				ll(root);
			}
		}
	} else if (val > root->val) {
		insert(root->right, val);
		if (height(root->right) - height(root->left) == 2) {
			if (val > root->right->val) {
				rr(root);
			} else {
				ll(root->right);
				rr(root);
			}
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
}

int main() {
	int n;
	cin >> n;
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		insert(root, num);
	}
	cout << root->val;
}