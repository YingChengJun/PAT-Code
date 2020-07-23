#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 512;
const int inf = 1 << 30;
int g[maxn][maxn];
int vis[maxn];
int dist[maxn];
int c[maxn][maxn];
int cost[maxn];
int pre[maxn];
int n, m, src, des;

int main() {
	fill(g[0], g[0] + maxn * maxn, inf);
	fill(c[0], c[0] + maxn * maxn, inf);
	fill(vis, vis + maxn, 0);
	fill(dist, dist + maxn, inf);
	fill(cost, cost + maxn, inf);
	fill(pre, pre + maxn, -1);
	scanf("%d%d%d%d", &n, &m, &src, &des);
	for (int i = 0; i < m; i++) {
		int u, v, w, cc;
		scanf("%d%d%d%d", &u, &v, &w, &cc);
		g[u][v] = g[v][u] = w;
		c[u][v] = c[v][u] = cc;
	}
	dist[src] = 0;
	cost[src] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minD = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dist[j] < minD) {
				minD = dist[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (!vis[v] && g[u][v] != inf) {
				if (dist[u] + g[u][v] < dist[v]) {
					dist[v] = dist[u] + g[u][v];
					cost[v] = cost[u] + c[u][v];
					pre[v] = u;
				} else if (dist[u] + g[u][v] == dist[v] && cost[u] + c[u][v] < cost[v]) {
					cost[v] = cost[u] + c[u][v];
					pre[v] = u;
				}
			}
		}
	}
	vector<int> path;
	int ansD = dist[des], ansC = cost[des];
	while (des != -1) {
		path.push_back(des);
		des = pre[des];
	}
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d", ansD, ansC);
}