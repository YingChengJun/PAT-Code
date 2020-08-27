#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 501
#define INF 99999999
using namespace std;

int C, N, P, M;
int G[MAXN][MAXN];
int nums[MAXN] = {0};
int minNeed = INF, minRemain = INF;
vector<int> pre[MAXN];
vector<int> tempPath, path;

void Dijkstra(int src) {
    int vis[MAXN], dis[MAXN];
    fill(vis, vis + MAXN, 0);
    fill(dis, dis + MAXN, INF);
    dis[src] = 0;
    for (int i = 0; i <= N; i++) {
        int u = -1, minD = INF;
        for (int j = 0; j <= N; j++) {
            if (!vis[j] && dis[j] < minD) {
                u = j;
                minD = dis[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v <= N; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (dis[u] + G[u][v] < dis[v]) {
                    pre[v].clear();
                    pre[v].push_back(u);
                    dis[v] = dis[u] + G[u][v];
                } else if (dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == 0) {
        tempPath.push_back(v);
        int need = 0, remain = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if (nums[id] > 0) {
                remain += nums[id];
            } else {
                if (remain > abs(nums[id])) {
                    remain -= abs(nums[id]);
                } else {
                    need += abs(nums[id]) - remain;
                    remain = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if (need == minNeed && remain < minRemain) {
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}


int main() {
    int src, des, w;
    scanf("%d %d %d %d", &C, &N, &P, &M);
    fill(G[0], G[0] + MAXN * MAXN, INF);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nums[i]);
        nums[i] -= C / 2;
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d", &src, &des, &w);
        G[src][des] = w;
        G[des][src] = w;
    }
    Dijkstra(0);
    DFS(P);
    printf("%d ", minNeed);
    for (int i = path.size() - 1; i >= 0 ; i--) {
        printf("%d", path[i]);
        if (i > 0) printf("->");
    }
    printf(" %d", minRemain);
}
