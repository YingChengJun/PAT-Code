#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10001
using namespace std;

int N;
int nums;
int S[MAXN] = {0};
int maxmaxd = 0;
vector<int> G[MAXN];
vector<int> ans;

int Find(int x) {
    if (S[x] == 0) {
        return x;
    } else {
        return S[x] = Find(S[x]);
    }
}

void Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy) {
        S[fy] = x;
    }
}

int dfs(int root, bool vis[]) {
    int maxd = 0;
    vis[root] = 1;
    for (int i = 0; i < G[root].size(); i++) {
        if (!vis[G[root][i]]) {
            maxd = max(maxd, dfs(G[root][i], vis) + 1);
        }
    }
    return maxd;
}

int main() {
    int src, des, comp = 0;
    scanf("%d", &N);
    if (N == 1) {
        printf("1");
        return 0;
    }
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &src, &des);
        G[src].push_back(des);
        G[des].push_back(src);
        Union(des, src);
    }
    for (int i = 1; i <= N; i++) {
        if (S[i] == 0) comp++;
    }
    if (comp != 1) {
        printf("Error: %d components", comp);
        return 0;
    }
    ans.push_back(0);
    for (int i = 1; i <= N; i++) {
        bool vis[MAXN] = {0};
        int maxd = dfs(i, vis);
        ans.push_back(maxd);
        maxmaxd = max(maxd, maxmaxd);
    }
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] == maxmaxd) {
            printf("%d\n", i);
        }
    }
}
