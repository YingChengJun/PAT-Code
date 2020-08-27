#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 10000
#define INF 99999999
using namespace std;

int N;
int src, des;
int Line[MAXN][MAXN];
vector<int> G[MAXN];
int vis[MAXN] = {0};
int minSum, minTransfer;
set<int> st;
vector<int> path;
vector<int> tempPath;

void output() {
    int preLine = 0, preTransfer = path[0];
    for (int i = 1; i < path.size(); i++) {
        if (Line[path[i - 1]][path[i]] != preLine) {
            if (preLine != 0)
                printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[i - 1]);
            preLine = Line[path[i - 1]][path[i]];
            preTransfer = path[i - 1];
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[path.size() - 1]);
}

void dfs(int u, int preu, int curSum, int curTransfer) {
    //printf("visit %d, preu = %d, curSum = %d, curTransfer = %d, minSum = %d, minTransfer = %d\n", u,preu, curSum, curTransfer, minSum, minTransfer);
    if (u == des) {
        if ((curSum < minSum) || (curSum == minSum && curTransfer < minTransfer)) {
            if (curSum < minSum) {
                minSum = curSum;
                minTransfer = curTransfer;
            } else if (curSum == minSum && curTransfer < minTransfer) {
                minTransfer = curTransfer;
            }
            tempPath.push_back(u);
            path = tempPath;
            tempPath.pop_back();
        }
        return;
    }
    if (curSum >= minSum) return;
    vis[u] = 1;
    tempPath.push_back(u);
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v]) {
            if (preu >= 0 && Line[preu][u] != Line[u][v]) {
                dfs(v, u, curSum + 1, curTransfer + 1);
            } else {
                dfs(v, u, curSum + 1, curTransfer);
            }
        }
    }
    vis[u] = 0;
    tempPath.pop_back();
}

int main() {
    int n, id, m, last, query;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &id);
            if (j > 0) {
                G[last].push_back(id);
                G[id].push_back(last);
                Line[last][id] = Line[id][last] = i;
            }
            last = id;
        }
    }
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        scanf("%d %d", &src, &des);
        minSum = minTransfer = INF;
        dfs(src, -1, 0, 0);
        printf("%d\n", minSum);
        output();
        fill(vis, vis + MAXN, 0);
        tempPath.clear();
    }
}
