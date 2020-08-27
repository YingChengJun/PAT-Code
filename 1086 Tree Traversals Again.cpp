#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int n;
vector<int> pre, in, post;
struct Node {
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int v): val(v) {};
};

void makeTree(Node* &root, int preL, int preR, int inL, int inR) {
    if (preL > preR) return;
    root = new Node(pre[preL]);
    int i, leftNum;
    for (i = inL; i <= inR; i++) {
        if (in[i] == pre[preL]) break;
    }
    leftNum = i - inL;
    makeTree(root->left, preL + 1, preL + leftNum, inL, i - 1);
    makeTree(root->right, preL + leftNum + 1, preR, i + 1, inR);
}

void traversal(Node* root) {
    if (root == NULL) return;
    traversal(root->left);
    traversal(root->right);
    post.push_back(root->val);
}

int main() {
    stack<int> st;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int num;
        string s;
        cin >> s;
        if (s == "Push") {
            cin >> num;
            pre.push_back(num);
            st.push(num);
        } else {
            in.push_back(st.top());
            st.pop();
        }
    }
    Node* root = NULL;
    makeTree(root, 0, n - 1, 0, n - 1);
    traversal(root);
    for (int i = 0; i < post.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}
