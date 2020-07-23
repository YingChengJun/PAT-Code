#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int val;
	Node* left = NULL;
	Node* right = NULL;
	Node(int val) : val(val) {};
};
int n;
vector<int> v1, v2, v3, v4;

void insert(Node* &root, int val) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}
	if (val < root->val) {
		insert(root->left, val);
	} else if (val >= root->val) {
		insert(root->right, val);
	}
}

void preorder(Node* root) {
	if (root == NULL) return;
	v2.push_back(root->val);
	preorder(root->left);
	preorder(root->right);
}

void premirror(Node* root) {
	if (root == NULL) return;
	v3.push_back(root->val);
	premirror(root->right);
	premirror(root->left);
}

void postorder(Node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	v4.push_back(root->val);
}

void postmirror(Node* root) {
	if (root == NULL) return;
	postmirror(root->right);
	postmirror(root->left);
	v4.push_back(root->val);
}

int main() {
	cin >> n;
	int val;
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		cin >> val;
		insert(root, val);
		v1.push_back(val);
	}
	preorder(root);
	premirror(root);
	if (v1 == v2 || v1 == v3) {
		printf("YES\n");
		if (v1 == v2) {
			postorder(root);
		} else {
			postmirror(root);
		}
		for (int i = 0; i < v4.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", v4[i]);
		}
	} else {
		printf("NO\n");
	}
}