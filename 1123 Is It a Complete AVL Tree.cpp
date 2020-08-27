#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> ans;
vector<int> v;

struct Node {
    int val;
    int height = 1;
    int id;
    Node* left = NULL;
    Node* right = NULL;
    Node(int v): val(v) {};
};

int getHeight(Node* node) {
    return node == NULL ? 0 : node->height;
}

void LL(Node* &root) {
    Node* child = root->left;
    root->left = child->right;
    child->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = max(getHeight(child->left), root->height) + 1;
    root = child;
}

void RR(Node* &root) {
    Node* child = root->right;
    root->right = child->left;
    child->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = max(getHeight(child->right), root->height) + 1;
    root = child;
}

void insert(Node* &root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }
    if (val < root->val) {
        insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (val < root->left->val) {
                LL(root);
            } else {
                RR(root->left);
                LL(root);
            }
        }
    } else if (val > root->val) {
        insert(root->right, val);
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (val > root->right->val) {
                RR(root);
            } else {
                LL(root->right);
                RR(root);
            }
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void level_order(Node* root) {
    queue<Node*> q;
    root->id = 1;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        ans.push_back(node->val);
        v.push_back(node->id);
        if (node->left) {
            node->left->id = node->id * 2;
            q.push(node->left);
        }
        if (node->right) {
            node->right->id = node->id * 2 + 1;
            q.push(node->right);
        }
    }
}


int main() {
    int n, num;
    Node* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(root, num);
    }
    level_order(root);
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", ans[i]);
    }
    sort(v.begin(), v.end());
    int i;
    for (i = 0; i < v.size(); i++) {
        if (v[i] != i + 1) break;
    }
    printf("\n%s", i == v.size() ? "YES": "NO");
}
