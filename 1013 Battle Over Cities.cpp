#include <cstdio>
#include <vector>
#define MAXN 1000
using namespace std;

int N, M, K;
int G[MAXN][MAXN] = {0};
int inv;

void dfs(int root, int vis[]) {
    vis[root] = true;
    for (int i = 1; i <= N; i++) {
        if (G[root][i] && !vis[i] && root != inv && i != inv) {
            dfs(i, vis);
        }
    }
}

int getComponent() {
    int vis[MAXN] = {0};
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i] && i != inv) {
            cnt++;
            dfs(i, vis);
        }
    }
    return cnt;
}

int main() {
    int src, des;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &src, &des);
        G[src][des] = 1;
        G[des][src] = 1;
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &inv);
        printf("%d\n", getComponent() - 1);
    }
}
