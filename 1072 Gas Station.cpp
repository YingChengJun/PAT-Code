#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 1011
#define MAXG 11
#define INF 99999999
#define MAXL 5
using namespace std;

int n, m, k, ds, N, maxD = 0, ansG;
int G[MAXN][MAXN];
int minDist[MAXG], totDist[MAXG];
int dist[MAXN], vis[MAXN];
bool flag = false;

int getID(char *s) {
    int id = 0;
    int i = s[0] == 'G' ? 1 : 0;
    while (i < strlen(s)) {
        id = id * 10 + (s[i] - '0');
        i++;
    }
    return s[0] == 'G' ? id + n : id;
}

void dijkstra(int src) {
    dist[src] = 0;
    for (int i = 1; i <= N; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= N; j++) {
            if (!vis[j] && dist[j] < MIN) {
                u = j;
                MIN = dist[j];
            }
        }
        if (u == -1) {
            printf("ERROR!\n");
            return;
        }
        vis[u] = 1;
        for (int v = 1; v <= N; v++) {
            if (G[u][v] != INF && !vis[v] && dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
            }
        }
    }
    int i, gid = src - n;
    for (i = 1; i <= n; i++) {
        if (dist[i] <= ds) {
            if (dist[i] < minDist[gid]) {
                minDist[gid] = dist[i];
            }
            totDist[gid] += dist[i];
        } else {
            minDist[gid] = -1;
            totDist[gid] = -1;
            break;
        }
    }
    if (i > n) {
        flag = true;
        if (minDist[gid] > maxD) {
            maxD = minDist[gid];
            ansG = gid;
        } else if (minDist[gid] == maxD && totDist[gid] < totDist[ansG]) {
            ansG = gid;
        }
    }
}

int main() {
    int weight;
    char src[5], des[5];
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    N = n + m;
    fill(G[0], G[0] + MAXN * MAXN, INF);
    fill(totDist, totDist + MAXG, 0);
    fill(minDist, minDist + MAXG, INF);
    for (int i = 0; i < k; i++) {
        scanf("%s %s %d", src, des, &weight);
        int s = getID(src);
        int d = getID(des);
        G[s][d] = G[d][s] = weight;
    }
    for (int i = 1; i <= m; i++) {
        fill(dist, dist + MAXN, INF);
        fill(vis, vis + MAXN, 0);
        dijkstra(i + n);
    }
    if (!flag) {
        printf("No Solution");
    } else {
        printf("G%d\n", ansG);
        printf("%.1f %.1f", 1.0 * maxD, 1.0 * totDist[ansG] / n);
    }
}
