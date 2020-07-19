#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	v.resize(n);
	set<int> st;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		st.insert(v[i]);
	}
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (st.find(a) == st.end() && st.find(b) == st.end()) {
			printf("ERROR: %d and %d are not found.\n", a, b);
		} else if (st.find(a) == st.end()) {
			printf("ERROR: %d is not found.\n", a);
		} else if (st.find(b) == st.end()) {
			printf("ERROR: %d is not found.\n", b);
		} else {
			int ans;
			for (int i = 0; i < n; i++) {
				if (v[i] >= min(a, b) && v[i] <= max(a, b)) {
					ans = v[i];
					break;
				}
			}
			if (ans == a || ans == b) {
				printf("%d is an ancestor of %d.\n", ans == a ? a : b, ans == a ? b : a);
			} else {
				printf("LCA of %d and %d is %d.\n", a, b, ans);
			}
		}
	}
}