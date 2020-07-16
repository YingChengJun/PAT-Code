#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#define LEFT(x) (2*(x)+1)
#define RIGHT(x) (2*(x)+2)
using namespace std;

int n;
int isMax = 1, isMin = 1;
vector<int> v;
vector<int> path;

void dfs(int root) {
	path.push_back(v[root]);
	if (LEFT(root) < n && v[LEFT(root)] > v[root]) isMax = false;
	if (LEFT(root) < n && v[LEFT(root)] < v[root]) isMin = false;
	if (RIGHT(root) < n && v[RIGHT(root)] > v[root]) isMax = false;
	if (RIGHT(root) < n && v[RIGHT(root)] < v[root]) isMin = false;
	if (LEFT(root) >= n && RIGHT(root) >= n) {
		for (int i = 0; i < path.size(); i++) {
			if (i > 0) cout << " ";
			cout << path[i];
		}
		cout << "\n";
	} else {
		if (RIGHT(root) < n) {
			dfs(RIGHT(root));
		}
		if (LEFT(root) < n) {
			dfs(LEFT(root));
		}
	}
	path.pop_back();
}

int main() {
	int t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	dfs(0);
	if (isMax) {
		printf("Max Heap");
	} else if (isMin) {
		printf("Min Heap");
	} else {
		printf("Not Heap");
	}
}