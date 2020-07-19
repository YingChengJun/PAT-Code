#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int g[256][256] = { 0 };

int main() {
	int n, m, uu, vv;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &uu, &vv);
		g[uu][vv] = g[vv][uu] = 1;
	}
	int query;
	scanf("%d", &query);
	while (query--) {
		int k;
		scanf("%d", &k);
		vector<int> v(k);
		int mp[256] = { 0 };
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
			mp[v[i]] = 1;
		}
		bool isClique = true, isMaxClique = true;
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (!g[v[i]][v[j]]) {
					isClique = false;
					break;
				}
				if (!isClique) break;
			}
		}
		if (!isClique) {
			printf("Not a Clique\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (mp[i]) continue;
			bool flag = true;
			for (int j = 0; j < k; j++) {
				if (!g[i][v[j]]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				isMaxClique = false;
				break;
			}
		}
		if (isMaxClique) {
			printf("Yes\n");
		} else {
			printf("Not Maximal\n");
		}
	}
}
