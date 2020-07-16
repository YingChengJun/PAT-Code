#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct User {
	string t;
	int val;
	User() {};
	User(string s, int v) : t(s), val(v) {};
};

bool cmp(const User& a, const User& b) {
	return a.val == b.val ? a.t < b.t : a.val > b.val;
}

int main() {
	int n, m, score, type;
	cin >> n >> m;
	vector<User> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].t >> v[i].val;
	}
	string s;
	for (int i = 1; i <= m; i++) {
		cin >> type >> s;
		vector<User> ans;
		printf("Case %d: %d %s\n", i, type, s.c_str());
		if (type == 1) {
			for (int j = 0; j < n; j++) {
				if (v[j].t[0] == s[0]) {
					ans.push_back(v[j]);
				}
			}
		} else if (type == 2) {
			int num = 0, tot = 0;
			for (int j = 0; j < n; j++) {
				if (v[j].t.substr(1, 3) == s) {
					num++;
					tot += v[j].val;
				}
			}
			if (num != 0) printf("%d %d\n", num, tot);
			else printf("NA\n");
		} else if (type == 3) {
			unordered_map<string, int> mp;
			for (int j = 0; j < n; j++) {
				if (v[j].t.substr(4, 6) == s) {
					mp[v[j].t.substr(1, 3)]++;
				}
			}
			for (pair<string, int> p : mp) {
				ans.push_back(User(p.first, p.second));
			}
		}
		if (type == 1 || type == 3) {
			if (ans.size() == 0) {
				printf("NA\n");
			} else {
				sort(ans.begin(), ans.end(), cmp);
				for (int j = 0; j < ans.size(); j++) {
					printf("%s %d\n", ans[j].t.c_str(), ans[j].val);
				}
			}
		}
	}
}