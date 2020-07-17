#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int G[256][256] = { 0 };
int n, m, src, des;
int ans = 1 << 30, index = -1;

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int d;
		scanf("%d%d%d", &src, &des, &d);
		G[src][des] = G[des][src] = d;
	}
	int query, k, pos;
	scanf("%d", &query);
	for (int i = 1; i <= query; i++) {
		bool isSimple = true, isTs = true;
		int tot = 0;
		int vis[256] = { 0 };
		scanf("%d", &k);
		vector<int> path(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &path[j]);
		}
		vis[path[0]] = 1;
		for (int j = 1; j < k; j++) {
			src = path[j - 1];
			des = path[j];
			if (G[src][des] > 0) {
				tot += G[src][des];
				if (vis[des] && j < k - 1) {
					isSimple = false;
				} else {
					vis[des] = 1;
				}
			} else {
				tot = -1;
				isSimple = isTs = false;
				break;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				isTs = false;
				break;
			}
		}
		if (tot == -1) {
			printf("Path %d: NA (Not a TS cycle)\n", i);
		} else if (!isTs || path[0] != path[path.size() - 1]) {
			printf("Path %d: %d (Not a TS cycle)\n", i, tot);
		} else if (!isSimple) {
			printf("Path %d: %d (TS cycle)\n", i, tot);
		} else if (isSimple) {
			printf("Path %d: %d (TS simple cycle)\n", i, tot);
		}
		if (tot != -1 && isTs && tot < ans) {
			ans = tot;
			index = i;
		}
	}
	printf("Shortest Dist(%d) = %d", index, ans);
}