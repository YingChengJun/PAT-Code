#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> pre, in;
struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v): val(v) {};
};

void makeTree(TreeNode* &root, int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return;
    root = new TreeNode(pre[preL]);
    int pos = inL;
    while (pos <= inR && in[pos] != pre[preL]) {
        pos++;
    }
    int leftNum = pos - inL;
    makeTree(root->left, preL + 1, preL + leftNum, inL, pos - 1);
    makeTree(root->right, preL + leftNum + 1, preR, pos + 1, inR);
}

void post_order(TreeNode* root) {
    while (root->left || root->right) {
        if (root->left) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if (root) printf("%d", root->val);
}

int main() {
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    TreeNode* root = NULL;
    makeTree(root, 0, n - 1, 0, n - 1);
    post_order(root);
}
