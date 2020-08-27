#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    int flag = 1;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v): val(v) {};
};
vector<int> in, post, ans;

void makeTree(TreeNode* &root, int inL, int inR, int posL, int posR) {
    if (inL <= inR) {
        root = new TreeNode(post[posR]);
        int j = inL;
        while (j <= inR && in[j] != post[posR]) {
            j++;
        }
        int leftNum = j - inL;
        makeTree(root->left, inL, j - 1, posL, posL + leftNum - 1);
        makeTree(root->right, j + 1, inR, posL + leftNum, posR - 1);
    }
}

void zigzag(TreeNode* root) {
    queue<TreeNode*> q;
    vector<TreeNode*> temp;
    q.push(root);
    while (!q.empty()) {
        TreeNode* ft = q.empty()? NULL: q.front();
        temp.clear();
        while (!q.empty() && ft->flag) {
            temp.push_back(ft);
            q.pop();
            if (ft->left) {
                ft->left->flag = 0;
                q.push(ft->left);
            }
            if (ft->right) {
                ft->right->flag = 0;
                q.push(ft->right);
            }
            ft = q.front();
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]->val);
        }
        if (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if (node->left) {
                node->left->flag = 1;
                q.push(node->left);
            }
            if (node->right) {
                node->right->flag = 1;
                q.push(node->right);
            }
        }
    }
}

int main() {
    int n;
    TreeNode* root = NULL;
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    makeTree(root, 0, n - 1, 0, n - 1);
    zigzag(root);
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", ans[i]);
    }
}
