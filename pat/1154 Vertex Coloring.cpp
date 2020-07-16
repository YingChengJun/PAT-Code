#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

struct Edge
{
	int u;
	int v;
	Edge() {};
	Edge(int uu, int vv) : u(uu), v(vv) {};
};

int main() {
	int n, m, k;
	int uu, vv;
	scanf("%d %d", &n, &m);
	vector<Edge> v(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &uu, &vv);
		v[i] = Edge(uu, vv);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		set<int> st;
		vector<int> a(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
			st.insert(a[j]);
		}
		int ans = st.size();
		for (int j = 0; j < m; j++) {
			if (a[v[j].u] == a[v[j].v]) {
				ans = -1;
				break;
			}
		}
		if (ans == -1) {
			printf("No\n");
		} else {
			printf("%d-coloring\n", ans);
		}
	}
}