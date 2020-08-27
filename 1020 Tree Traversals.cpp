#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 30;
struct Node {
    int v;
    int left = -1;
    int right= -1;
} node[MAXN];
int post[MAXN] = {0};
int in[MAXN] = {0};
int n, cnt = -1;

int makeTree(int pl, int pr, int il, int ir) {
    int i;
    int id = ++cnt;
    node[id].v = post[pr];
    if (pl < pr && il < ir) {
        for (i = il; i <= ir; i++) {
            if (in[i] == post[pr]) break;
        }
        int leftNum = i - il;
        int rightNum = ir - i;
        if (leftNum > 0) {
            node[id].left = makeTree(pl, pl + leftNum -1, il, i - 1);
        }
        if (rightNum > 0) {
            node[id].right = makeTree(pl + leftNum, pl + leftNum + rightNum - 1, i + 1, ir);
        }
    }
    return id;
}

void traversal(int root) {
    queue<int> q;
    printf("%d", node[root].v);
    q.push(root);
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
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    int root = makeTree(0, n-1, 0, n-1);
    traversal(root);
}
