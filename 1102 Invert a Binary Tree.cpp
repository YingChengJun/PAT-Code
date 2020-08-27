#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
const int MAXN = 10;
struct Node {
    int left = -1;
    int right = -1;
    bool isRoot = true;
} node[MAXN];
vector<int> inorder, leorder;

int getRoot() {
    for (int i = 0; i < N; i++) {
        if (node[i].isRoot) return i;
    }
    return -1;
}

void inorder_traversal(int root) {
    if (node[root].left != -1) {
        inorder_traversal(node[root].left);
    }
    inorder.push_back(root);
    if (node[root].right != -1) {
        inorder_traversal(node[root].right);
    }
}

void levelorder_traversal(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        leorder.push_back(v);
        if (node[v].left != -1) {
            q.push(node[v].left);
        }
        if (node[v].right != -1) {
            q.push(node[v].right);
        }
    }
}

void output(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) printf(" %d", v[i]);
        else printf("%d", v[0]);
    }
}

int reverse_tree(int root) {
    if (root == -1) return -1; //a null node
    if (node[root].left == -1 && node[root].right == -1) return root;  //a leaf node return itself
    int newLeft = reverse_tree(node[root].right);  //swap left and right node
    int newRight = reverse_tree(node[root].left);
    node[root].left = newLeft;
    node[root].right = newRight;
    return root;  //return root itself
}

int main() {
    char l, r;
    scanf("%d%*c", &N);
    for (int i = 0; i < N; i++) {
        scanf("%c %c%*c", &l, &r);
        if (l >= '0' && l <= '9') {
            node[i].left = l - '0';
            node[l - '0'].isRoot = false;
        }
        if (r >= '0' && r <= '9') {
            node[i].right = r - '0';
            node[r - '0'].isRoot = false;
        }
    }
    int root = getRoot();
    reverse_tree(root);
    inorder_traversal(root);
    levelorder_traversal(root);
    output(leorder);
    printf("\n");
    output(inorder);
}
