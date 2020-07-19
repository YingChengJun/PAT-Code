#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> g[1024];
vector<int> temp(1024, 0);
vector<int> ans;

int main() {
	int m, n, k;
	cin >> n >> m;
	int src, des;
	while (m--) {
		cin >> src >> des;
		temp[des]++;
		g[src].push_back(des);
	}
	cin >> k;
	for (int l = 0; l < k; l++) {
		vector<int> deg = temp;
		vector<int> input(n);
		for (int i = 0; i < n; i++) cin >> input[i];
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (deg[input[i]] != 0) {
				ans.push_back(l);
				break;
			}
			for (int j = 0; j < g[input[i]].size(); j++) {
				deg[g[input[i]][j]]--;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
}