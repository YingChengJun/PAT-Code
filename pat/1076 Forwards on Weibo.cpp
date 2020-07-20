#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> g[1024];
int n, k, level;

int bfs(int root) {
	int ans = 0;
	vector<int> layer(1024, -1);
	queue<int> q;
	q.push(root);
	layer[root] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (layer[v] == -1 && layer[u] + 1 <= level) {
				layer[v] = layer[u] + 1;
				q.push(v);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &level);
	for (int u = 1; u <= n; u++) {
		int m;
		scanf("%d", &m);
		while (m--) {
			int v;
			scanf("%d", &v);
			g[v].push_back(u);
		}
	}
	scanf("%d", &k);
	while (k--) {
		int root;
		scanf("%d", &root);
		printf("%d\n", bfs(root));
	}
}