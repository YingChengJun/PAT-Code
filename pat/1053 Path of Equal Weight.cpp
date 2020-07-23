#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int  maxn = 100;
int n, m;
long long S;
struct Node
{
	int w;
	vector<int> childs;
} nodes[maxn];
vector<int> path;

bool cmp(int u, int v) {
	return nodes[u].w > nodes[v].w;
}

void dfs(int root, long long curSum) {
	if (curSum + nodes[root].w == S && nodes[root].childs.size() == 0) {
		path.push_back(root);
		for (int i = 0; i < path.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", nodes[path[i]].w);
		}
		printf("\n");
		path.pop_back();
		return;
	}
	if (curSum >= S) return;
	path.push_back(root);
	for (int i = 0; i < nodes[root].childs.size(); i++) {
		dfs(nodes[root].childs[i], curSum + nodes[root].w);
	}
	path.pop_back();
}

int main() {
	scanf("%d %d %lld", &n, &m, &S);
	for (int i = 0; i < n; i++) scanf("%d", &nodes[i].w);
	for (int i = 0; i < m; i++) {
		int id, k;
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			int num;
			scanf("%d", &num);
			nodes[id].childs.push_back(num);
		}
		sort(nodes[id].childs.begin(), nodes[id].childs.end(), cmp);
	}
	dfs(0, 0);
}