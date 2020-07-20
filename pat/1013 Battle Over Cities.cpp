#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int g[1024][1024] = { 0 };
int vis[1024];
int n, m, k;
int inv;

void dfs(int root) {
	vis[root] = 1;
	for (int i = 1; i <= n; i++) {
		if (i == root || i == inv) continue;
		if (g[root][i] && !vis[i]) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	while (k--) {
		int component = 0;
		scanf("%d", &inv);
		fill(vis, vis + 1024, 0);
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && i != inv) {
				component++;
				dfs(i);
			}
		}
		printf("%d\n", component - 1);
	}
}