#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, in, post;

struct Node
{
	Node* left = NULL;
	Node* right = NULL;
	int val;
	Node(int v) : val(v) {};
};

void makeTree(Node* & root, int preL, int preR, int inL, int inR) {
	if (preL > preR) return;
	root = new Node(pre[preL]);
	int i;
	for (i = inL; i < inR; i++) {
		if (in[i] == pre[preL]) {
			break;
		}
	}
	makeTree(root->left, preL + 1, preL + i - inL, inL, i - 1);
	makeTree(root->right, preL + i - inL + 1, preR, i + 1, inR);
}

int main() {
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++) cin >> in[i];
	Node* root = NULL;
	makeTree(root, 0, n - 1, 0, n - 1);
	while (root->left || root->right) {
		if (root->left) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
	cout << root->val;
}