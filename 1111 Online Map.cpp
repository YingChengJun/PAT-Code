#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 512
#define INF 99999999
using namespace std;

int n, m;
int G[MAXN][MAXN], T[MAXN][MAXN];
int pre[MAXN], dist[MAXN], time[MAXN], node[MAXN], vis[MAXN];
vector<int> ans1, ans2;

int dijkstra1(int src, int des) {
    dist[src] = 0;
    time[src] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dist[j] < MIN) {
                MIN = dist[j];
                u = j;
            }
        }
        if (u == -1) {
            printf("ERROR\n");
            return -1;
        }
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (dist[u] + G[u][v] < dist[v]) {
                    dist[v] = dist[u] + G[u][v];
                    pre[v] = u;
                    time[v] = time[u] + T[u][v];
                } else if (dist[u] + G[u][v] == dist[v] && time[u] + T[u][v] < time[v]) {
                    pre[v] = u;
                    time[v] = time[u] + T[u][v];
                }
            }
        }
    }
    int pos = des;
    while (pos != -1) {
        ans1.push_back(pos);
        pos = pre[pos];
    }
    return dist[des];
}

int dijkstra2(int src, int des) {
    node[src] = 0;
    time[src] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && time[j] < MIN) {
                MIN = time[j];
                u = j;
            }
        }
        if (u == -1) {
            printf("ERROR\n");
            return -1;
        }
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && T[u][v] != INF) {
                if (time[u] + T[u][v] < time[v]) {
                    node[v] = node[u] + 1;
                    pre[v] = u;
                    time[v] = time[u] + T[u][v];
                } else if (time[u] + T[u][v] == time[v] && node[u] + 1 < node[v]) {
                    pre[v] = u;
                    node[v] = node[u] + 1;
                }
            }
        }
    }
    int pos = des;
    while (pos != -1) {
        ans2.push_back(pos);
        pos = pre[pos];
    }
    return time[des];
}

int main() {
    int src, des;
    int from, to, ow, len, t;
    scanf("%d %d", &n, &m);
    fill(G[0], G[0] + MAXN * MAXN, INF);
    fill(T[0], T[0] + MAXN * MAXN, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &from, &to, &ow, &len, &t);
        G[from][to] = len;
        T[from][to] = t;
        if (!ow) {
            G[to][from] = len;
            T[to][from] = t;
        }
    }
    scanf("%d %d", &src, &des);
    fill(pre, pre + MAXN, -1);
    fill(vis, vis + MAXN, 0);
    fill(dist, dist + MAXN, INF);
    fill(time, time + MAXN, INF);
    int v1 = dijkstra1(src, des);
    fill(pre, pre + MAXN, -1);
    fill(vis, vis + MAXN, 0);
    fill(time, time + MAXN, INF);
    fill(node, node + MAXN, INF);
    int v2 = dijkstra2(src, des);
    if (ans1 != ans2) {
        printf("Distance = %d: %d", v1, src);
        for (int i = ans1.size() - 2; i >= 0; i--) {
            printf(" -> %d", ans1[i]);
        }
        printf("\n");
        printf("Time = %d: %d", v2, src);
        for (int i = ans2.size() - 2; i >= 0; i--) {
            printf(" -> %d", ans2[i]);
        }
    } else {
        printf("Distance = %d; Time = %d: %d", v1, v2, src);
        for (int i = ans1.size() - 2; i >= 0; i--) {
            printf(" -> %d", ans1[i]);
        }
    }
}
