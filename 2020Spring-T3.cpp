#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Edge
{
	int u;
	int v;
};
vector<Edge> edges;
set<int> st;

int main() {
	int n, r, k;
	scanf("%d %d %d", &n, &r, &k);
	for (int i = 0; i < r; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		Edge e;
		e.u = u;
		e.v = v;
		edges.push_back(e);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		st.clear();
		vector<int> nums(n + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &nums[i]);
			st.insert(nums[i]);
		}
		if (st.size() > k) {
			printf("Error: Too many species.\n");
			continue;
		}
		if (st.size() < k) {
			printf("Error: Too few species.\n");
			continue;
		}
		bool flag = true;
		for (int j = 0; j < edges.size(); j++) {
			int u = edges[j].u;
			int v = edges[j].v;
			if (nums[u] == nums[v]) {
				flag = false;
				break;
			}
		}
		printf("%s\n", flag ? "Yes": "No");
	}
}