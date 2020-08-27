#include <cstdio>
#include <vector>
#define MAXN 100
using namespace std;

int N, M;
struct Node {
    vector<int> child;
}node[MAXN];
int sum[MAXN] = {0};
int level = 1;
int ans = 1;

void dfs(int root, int depth) {
    sum[depth]++;
    for (int i = 0; i < node[root].child.size(); i++) {
        dfs(node[root].child[i], depth + 1);
    }
}

int main() {
    int fid, fnum, cid;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &fid, &fnum);
        for (int j = 0; j < fnum; j++) {
            scanf("%d", &cid);
            node[fid].child.push_back(cid);
        }
    }
    dfs(1, 1);
    for (int i = 1; i < MAXN; i++) {
        if (sum[i] > ans) {
            level = i;
            ans = sum[i];
        }
    }
    printf("%d %d", ans, level);
}
