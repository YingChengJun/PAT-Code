#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 512;
const int inf = 1 << 30;
int cmax, n, sp, m;
int nums[maxn];
int g[maxn][maxn];
int vis[maxn];
int dist[maxn];
vector<int> pre[maxn];
vector<int> tempPath, path;
int minNeed = inf, minRemain = inf;

void dfs(int v) {
	if (v == 0) {
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int u = tempPath[i];
			if (nums[u] > 0) {
				remain += nums[u];
			} else if (nums[u] < 0) {
				if (remain + nums[u] > 0) {
					remain += nums[u];
				} else {
					need -= remain + nums[u];
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
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	fill(g[0], g[0] + maxn * maxn, inf);
	fill(nums, nums + maxn, 0);
	fill(vis, vis + maxn, 0);
	fill(dist, dist + maxn, inf);
	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
		nums[i] -= cmax / 2;
	}
	for (int i = 0; i < m; i++) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		g[u][v] = g[v][u] = t;
	}
	dist[0] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, minD = inf;
		for (int j = 0; j <= n; j++) {
			if (!vis[j] && dist[j] < minD) {
				u = j;
				minD = dist[j];
			}
		}
		if (u == -1) {
			return 1;
		}
		vis[u] = 1;
		for (int v = 0; v <= n; v++) {
			if (!vis[v] && g[u][v] != inf) {
				if (dist[u] + g[u][v] < dist[v]) {
					pre[v].clear();
					pre[v].push_back(u);
					dist[v] = dist[u] + g[u][v];
				} else if (dist[u] + g[u][v] == dist[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(sp);
	printf("%d ", minNeed);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i > 0) printf("->");
	}
	printf(" %d", minRemain);
}