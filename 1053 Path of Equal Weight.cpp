#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100
using namespace std;

int N, M, S;
struct Node {
    int w;
    vector<int> child;
} node[MAXN];
vector<int> path;

bool cmp(int a, int b) {
    return node[a].w > node[b].w;
}

void dfs(int root, int curSum) {
    if (curSum > S) return;
    if (node[root].child.size() == 0 && curSum == S) {
        for (int i = 0; i < path.size() - 1; i++) {
            printf("%d ", node[path[i]].w);
        }
        printf("%d\n", node[root].w);
        return;
    }
    for (int i = 0; i < node[root].child.size(); i++) {
        path.push_back(node[root].child[i]);
        dfs(node[root].child[i], curSum + node[node[root].child[i]].w);
        path.pop_back();
    }
}

int main() {
    int id, cnum, cid;
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &node[i].w);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &id, &cnum);
        for (int j = 0; j < cnum; j++) {
            scanf("%d", &cid);
            node[id].child.push_back(cid);
        }
        sort(node[id].child.begin(), node[id].child.end(), cmp);
    }
    path.push_back(0);
    dfs(0, node[0].w);
}
