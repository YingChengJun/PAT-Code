#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1024;
vector<int> s(maxn, 0);
vector<int> hob;

int Find(int x) {
	if (s[x] == 0) {
		return x;
	} else {
		return s[x] = Find(s[x]);
	}
}

void Union(int a, int b) {
	int fa = Find(a);
	int fb = Find(b);
	if (fa != fb) {
		s[fa] = fb;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k = 0, first = -1, val;
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &val);
			if (j == 0) first = val;
			else Union(first, val);
		}
		hob.push_back(first);
	}
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[Find(hob[i])]++;
	}
	vector<int> ans;
	printf("%d\n", mp.size());
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans.push_back(it->second);
	}
	sort(ans.begin(), ans.end());
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d", ans[i]);
		if (i != 0) printf(" ");
	}
}