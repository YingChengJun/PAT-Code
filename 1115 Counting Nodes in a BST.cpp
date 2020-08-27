#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxd = 0;

struct Node {
    int val;
    int depth;
    Node* left;
    Node* right;
    Node(int v): val(v), left(NULL), right(NULL) {};
};

void insert(Node* &root, int num) {
    if (!root) {
        root = new Node(num);
        return;
    } else if (num <= root->val) {
        insert(root->left, num);
    } else if (num > root->val) {
        insert(root->right, num);
    }
}

void dfs(Node* root, int d) {
    if (!root)
        return;
    root->depth = d;
    maxd = max(maxd, d);
    dfs(root->left, d + 1);
    dfs(root->right, d + 1);
}

void dfs2(Node* root, int &n1, int &n2) {
    if (!root)
        return;
    if (root->depth == maxd) {
        n1++;
    } else if (root->depth == maxd - 1) {
        n2++;
    }
    dfs2(root->left, n1, n2);
    dfs2(root->right, n1, n2);
}

int main() {
    int n, num;
    Node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(root, num);
    }
    dfs(root, 0);
    if (maxd == 0) {
        printf("1 + 0 = 1");
    } else {
        int n1 = 0, n2 = 0;
        dfs2(root, n1, n2);
        printf("%d + %d = %d", n1, n2, n1 + n2);
    }
}

