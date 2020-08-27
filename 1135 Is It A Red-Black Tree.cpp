#include <cstdio>
#include <algorithm>
using namespace std;

typedef enum {BLACK, RED} Color;
struct TreeNode {
    Color color;
    int val;
    int bh = 0;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v) {
        if (v < 0) {
            color = RED;
            val = -v;
        } else {
            color = BLACK;
            val = v;
        }
    }
};

Color getColor(TreeNode* root) {
    if (root == NULL)
        return BLACK;
    return root->color;
}

void makeTree(TreeNode* &root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return;
    } else if (abs(val) < root->val) {
        makeTree(root->left, val);
    } else if (abs(val) > root->val) {
        makeTree(root->right, val);
    }
}

void dfs(TreeNode* root, int curBlack, int &totBlack, bool &flag) {
    if (!flag)
        return;
    if (root == NULL) {
        if (totBlack == -1) {
            totBlack = curBlack;
        } else if (totBlack != curBlack) {
            flag = false;
        }
        return;
    }
    if (root->color == RED && (getColor(root->left) == RED || getColor(root->right) == RED)) {
        flag = false;
        return;
    }
    curBlack = root->color == BLACK ? curBlack + 1 : curBlack;
    dfs(root->left, curBlack, totBlack, flag);
    dfs(root->right, curBlack, totBlack, flag);
}

bool isRBTree(TreeNode* root) {
    if (root->color == RED)
        return false;
    int totBlack = -1;
    bool flag = true;
    dfs(root, 0, totBlack, flag);
    return flag;
}

int main() {
    int query, n, num;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        scanf("%d", &n);
        TreeNode* root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            makeTree(root, num);
        }
        printf("%s\n", isRBTree(root) ? "Yes" : "No");
    }
}
