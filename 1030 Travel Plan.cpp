#include <cstdio>
#include <vector>
#define MAXN 500
#define INF 99999999
using namespace std;

int N, M, S, D;
struct Node {
    int id;
    int c;
    int w;
    Node(int _id, int _c, int _w): id(_id), c(_c), w(_w) {};
};
vector<Node> G[MAXN];
int pre[MAXN], dist[MAXN], cost[MAXN], vis[MAXN];


void dijkstra(int src, int des) {
    dist[src] = 0;
    cost[src] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dist[j] < MIN) {
                u = j;
                MIN = dist[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j < G[u].size(); j++) {
            Node &adj = G[u][j];
            int v = adj.id;
            if (!vis[v]) {
                if (dist[u] + adj.w < dist[v]) {
                    dist[v] = dist[u] + adj.w;
                    pre[v] = u;
                    cost[v] = cost[u] + adj.c;
                } else if (dist[u] + adj.w == dist[v]) {
                    if (cost[u] + adj.c < cost[v]) {
                        pre[v] = u;
                        cost[v] = cost[u] + adj.c;
                    }
                }
            }
        }
    }
    int p = des;
    vector<int> ans;
    while (p != -1) {
        ans.push_back(p);
        p = pre[p];
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
    printf("%d %d", dist[des], cost[des]);
}

int main() {
    int src, des, c, w;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &src, &des, &w, &c);
        G[src].push_back(Node(des, c, w));
        G[des].push_back(Node(src, c, w));
    }
    fill(pre, pre + MAXN, -1);
    fill(dist, dist + MAXN, INF);
    fill(vis, vis + MAXN, 0);
    fill(cost, cost + MAXN, INF);
    dijkstra(S, D);
}
