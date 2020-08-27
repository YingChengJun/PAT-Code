#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 20
using namespace std;

int n;
struct Node {
    int id = -1;
    int number = -1;
    int left = -1;
    int right = -1;
} node[MAXN];
vector<Node> v;

int findRoot(int isRoot[]) {
    for (int i = 0; i < n; i++) {
        if (isRoot[i])
            return i;
    }
    return -1;
}

bool cmp(Node a, Node b) {
    return a.id < b.id;
}

void dfs(int root, int id) {
    if (root == -1) return;
    node[root].id = id;
    v.push_back(node[root]);
    dfs(node[root].left, 2 * id);
    dfs(node[root].right, 2 * id + 1);
}

int toInt(char *a) {
    int ans = 0;
    for (int i = 0; i < strlen(a); i++) {
        ans = ans * 10 + a[i] - '0';
    }
    return ans;
}

int main() {
    char left[3], right[3];
    int isRoot[MAXN], i;
    scanf("%d%*c", &n);
    fill(isRoot, isRoot + MAXN, 1);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", left, right);
        if (left[0] != '-') {
            int l = toInt(left);
            node[i].left = l;
            isRoot[l] = 0;
        }
        if (right[0] != '-') {
            int r = toInt(right);
            node[i].right = r;
            isRoot[r] = 0;
        }
        node[i].number = i;
    }
    if (n == 1) {
        printf("YES 0");
        return 0;
    }
    int root = findRoot(isRoot);
    dfs(root, 1);
    sort(v.begin(), v.end(), cmp);
    for (i = 1; i < v.size(); i++) {
        if (v[i].id - v[i - 1].id != 1)
            break;
    }
    if (i == v.size()) {
        printf("YES %d", v[v.size() - 1].number);
    } else {
        printf("NO %d", root);
    }
}
