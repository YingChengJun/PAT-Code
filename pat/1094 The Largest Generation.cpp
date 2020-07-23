#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100;
struct Node
{
	int layer;
	vector<int> childs;
} nodes[maxn];
int n, m;
int map[maxn] = { 0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int p, k;
		scanf("%d %d", &p, &k);
		for (int j = 0; j < k; j++) {
			int c;
			scanf("%d", &c);
			nodes[p].childs.push_back(c);
		}
	}
	queue<int> q;
	q.push(1);
	nodes[1].layer = 1;
	while (!q.empty()) {
		int root = q.front();
		q.pop();
		map[nodes[root].layer]++;
		for (int i = 0; i < nodes[root].childs.size(); i++) {
			nodes[nodes[root].childs[i]].layer = nodes[root].layer + 1;
			q.push(nodes[root].childs[i]);
		}
	}
	int index = 0;
	for (int i = 1; i <= n; i++) {
		if (map[i] > map[index]) {
			index = i;
		}
	}
	printf("%d %d", map[index], index);
}