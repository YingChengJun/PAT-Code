#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 1024
using namespace std;

int n;
struct Node {
    int v;
    int left = -1;
    int right = -1;
} node[MAXN];
vector<int> v;
vector<int> in;

void dfs(int root) {
    if (2 * root <= n) {
        node[root].left = 2 * root;
        dfs(2 * root);
    }
    if (2 * root + 1 <= n) {
        node[root].right = 2 * root + 1;
        dfs(2 * root + 1);
    }
}

void inorder_traversal(int root) {
    if (node[root].left != -1) {
        inorder_traversal(node[root].left);
    }
    in.push_back(root);
    if (node[root].right != -1) {
        inorder_traversal(node[root].right);
    }
}

void level_traversal(int root) {
    queue<int> q;
    q.push(root);
    printf("%d", node[root].v);
    while (!q.empty()) {
        int r = q.front();
        q.pop();
        if (node[r].left != -1) {
            printf(" %d", node[node[r].left].v);
            q.push(node[r].left);
        }
        if (node[r].right != -1) {
            printf(" %d", node[node[r].right].v);
            q.push(node[r].right);
        }
    }
}

int main() {
    int num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    dfs(1);
    inorder_traversal(1);
    for (int i = 0; i < in.size(); i++) {
        node[in[i]].v = v[i];
    }
    level_traversal(1);
}
