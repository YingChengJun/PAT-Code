#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
double p, r;
double ans = 0;

struct Node
{
	vector<int> childs;
	int w = 0;
};
vector<Node> v;

void dfs(int root, int depth) {
	if (v[root].childs.size() == 0) {
		ans = ans + v[root].w * p * pow((100.0 + r) / 100.0, depth);
		return;
	}
	for (int i = 0; i < v[root].childs.size(); i++) {
		dfs(v[root].childs[i], depth + 1);
	}
}

int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		int k, num;
		scanf("%d", &k);
		Node node;
		if (k == 0) {
			scanf("%d", &node.w);
		} else {
			for (int j = 0; j < k; j++) {
				scanf("%d", &num);
				node.childs.push_back(num);
			}
		}
		v.push_back(node);
	}
	dfs(0, 0);
	printf("%.1f", ans);
}