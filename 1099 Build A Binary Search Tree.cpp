#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 100
using namespace std;

int n;
struct Node {
    int val;
    int left = -1;
    int right = -1;
} node[MAXN];
vector<int> v;
vector<int> in;

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
    printf("%d", node[root].val);
    while (!q.empty()) {
        int r = q.front();
        q.pop();
        if (node[r].left != -1) {
            printf(" %d", node[node[r].left].val);
            q.push(node[r].left);
        }
        if (node[r].right != -1) {
            printf(" %d", node[node[r].right].val);
            q.push(node[r].right);
        }
    }
}

int main() {
    int num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &node[i].left, &node[i].right);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    inorder_traversal(0);
    for (int i = 0; i < in.size(); i++) {
        node[in[i]].val = v[i];
    }
    level_traversal(0);
}
