#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#define maxn 512
using namespace std;

const int inf = 1 << 30;
int n, m, c1, c2;
int g[maxn][maxn];
vector<int> nums(maxn, 0);
vector<int> paths(maxn, 0);
vector<int> rescures(maxn, 0);
vector<int> vis(maxn, 0);
vector<int> dist(maxn, inf);


int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	dist[c1] = 0;
	rescures[c1] = nums[c1];
	paths[c1] = 1;
	for (int i = 0; i < n; i++) {
		int u = -1, minD = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dist[j] < minD) {
				u = j;
				minD = dist[j];
			}
		}
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (!vis[v] && g[u][v] != inf) {
				if (dist[u] + g[u][v] < dist[v]) {
					dist[v] = dist[u] + g[u][v];
					paths[v] = paths[u];
					rescures[v] = rescures[u] + nums[v];
				} else if (dist[u] + g[u][v] == dist[v]) {
					paths[v] += paths[u];
					if (rescures[u] + nums[v] > rescures[v]) {
						rescures[v] = rescures[u] + nums[v];
					}
				}
			}
		}
	}
	printf("%d %d", paths[c2], rescures[c2]);
}