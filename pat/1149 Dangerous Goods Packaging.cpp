#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
const int maxn = 100000;
set<int> st[maxn];

int main() {
	scanf("%d%d", &n, &m);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		st[a].insert(b);
		st[b].insert(a);
	}
	while (m--) {
		int k, num;
		scanf("%d", &k);
		vector<int> v(k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
		}
		bool flag = true;
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (st[v[i]].find(v[j]) != st[v[i]].end()) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		printf("%s\n", flag ? "Yes": "No");
	}
}