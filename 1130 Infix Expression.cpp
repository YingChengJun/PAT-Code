#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 32
#define MAXL 16
using namespace std;


int n;
struct Node {
    char data[MAXL];
    int left = -1;
    int right = -1;
    Node() {};
    Node(char *s) {
        strcpy(data, s);
    }
} node[MAXN];

int getSize(int root) {
    if (root == -1) return 0;
    return getSize(node[root].left) + getSize(node[root].right) + 1;
}

string inorder(int root) {
    if (root == -1) return "";
    if (node[root].left == -1 && node[root].right == -1) return node[root].data;
    string left, right;
    if (getSize(node[root].left) > 1) {
        left = "(" + inorder(node[root].left) + ")";
    } else {
        left = inorder(node[root].left);
    }
    if (getSize(node[root].right) > 1) {
        right = "(" + inorder(node[root].right) + ")";
    } else {
        right = inorder(node[root].right);
    }
    return left + node[root].data + right;
}

int main() {
    scanf("%d", &n);
    bool vis[MAXN] = {0};
    for (int i = 1; i <= n; i++){
        scanf("%s %d %d", node[i].data, &node[i].left, &node[i].right);
        if (node[i].left > 0) vis[node[i].left] = 1;
        if (node[i].right > 0) vis[node[i].right] = 1;
    }
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    string ans = inorder(root);
    printf("%s", ans.c_str());
}
