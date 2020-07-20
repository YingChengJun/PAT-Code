#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

const int inf = 1 << 30;
const int maxn = 512;
int n, m, c1, c2;
int nums[maxn] = { 0 };
int g[maxn][maxn];
int vis[maxn] = { 0 };
int dist[maxn];

int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	fill(g, g + maxn * maxn, inf);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	fill(dist, dist + maxn, inf);
	for (int i = 0; i < n; i++) {

	}
}