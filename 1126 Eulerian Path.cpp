#include <cstdio>
#define MAXN 512

int deg[MAXN] = {0};
int G[MAXN][MAXN] = {0};
int vis[MAXN] = {0};

void dfs(int root, int n) {
    vis[root] = 1;
    for (int i = 1; i <= n; i++) {
        if (G[root][i] == 1 && !vis[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    int src, des;
    int odd = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &src, &des);
        deg[src]++;
        deg[des]++;
        G[src][des] = 1;
        G[des][src] = 1;
    }
    dfs(1, n);
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2) odd++;
        if (i > 1) printf(" ");
        printf("%d", deg[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            printf("Non-Eulerian");
            return 0;
        }
    }
    if (odd == 0) printf("Eulerian");
    else if (odd == 2)  printf("Semi-Eulerian");
    else printf("Non-Eulerian");
}
