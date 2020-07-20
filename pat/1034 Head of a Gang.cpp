#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int g[2048][2048] = { 0 };
int tot[2048] = { 0 };
int vis[2048] = { 0 };
int m, k;
int n = 0;
unordered_map<string, int> stoimap;
unordered_map<int, string> itosmap;

int toi(string s) {
	if (stoimap.find(s) == stoimap.end()) {
		stoimap[s] = n;
		itosmap[n] = s;
		return n++;
	}
	return stoimap[s];
}

void dfs(int root, int& members, int& sums, int &gang) {
	vis[root] = 1;
	members++;
	sums += tot[root] / 2;
	if (tot[root] > tot[gang]) {
		gang = root;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i] && i != root && g[root][i] > 0) {
			dfs(i, members, sums, gang);
		}
	}
}

struct Node
{
	string name;
	int val;
	Node(string name, int val) : name(name), val(val) {};
};

bool cmp(Node& a, Node& b) {
	return a.name < b.name;
}

int main() {
	cin >> m >> k;
	while (m--) {
		int w;
		string s1, s2;
		cin >> s1 >> s2 >> w;
		int u = toi(s1), v = toi(s2);
		g[u][v] = w;
		tot[u] += w;
		tot[v] += w;
	}
	vector<Node> ans;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			int members = 0;
			int sums = 0;
			int gang = i;
			dfs(i, members, sums, gang);
			if (members > 2 && sums > k) {
				ans.push_back(Node(itosmap[gang], members));
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size();
	for (int i = 0; i < ans.size(); i++) {
		cout << endl << ans[i].name << " " << ans[i].val;
	}
}