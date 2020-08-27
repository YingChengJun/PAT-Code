#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int v;
    int height = 1;
    Node* left = NULL;
    Node* right = NULL;
};

int getHeight(Node* node) {
    return node == NULL ? 0 : node->height;
}

Node* RR(Node* root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(root->height, getHeight(temp->right)) + 1;
    return temp;
}

Node* LL(Node* root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(root->height, getHeight(temp->left)) + 1;
    return temp;
}

Node* RL(Node* root) {
    root->right = LL(root->right);
    return RR(root);
}

Node* LR(Node* root) {
    root->left = RR(root->left);
    return LL(root);
}

Node* insert(Node* root, int num) {
    if (root == NULL) {
        root = new Node;
        root->v = num;
    } else if (num < root->v) {
        root->left = insert(root->left, num);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (num <= root->left->v) {
                root = LL(root);
            } else {
                root = LR(root);
            }
        }
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    } else if (num > root->v) {
        root->right = insert(root->right, num);
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (num >= root->right->v) {
                root = RR(root);
            } else {
                root = RL(root);
            }
        }
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    return root;
}

int main() {
    int n, num;
    Node* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        root = insert(root, num);
    }
    printf("%d\n", root->v);
}
