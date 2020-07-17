#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> pre, in;
unordered_map<int, int> pos;
int ans = 0;

void search(int a, int b, int preL, int inL, int inR) {
	if (inL > inR) return;
	int inRoot = pos[pre[preL]], inA = pos[a], inB = pos[b];
	if (inA < inRoot && inB < inRoot) {
		search(a, b, preL + 1, inL, inRoot - 1);
	} else if (inA > inRoot && inB > inRoot) {
		search(a, b, preL + inRoot - inL + 1, inRoot + 1, inR);
	} else if ((inA < inRoot && inB > inRoot) || (inA > inRoot && inB < inRoot)) {
		printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
	} else if (inA == inRoot) {
		printf("%d is an ancestor of %d.\n", a, b);
	} else if (inB == inRoot) {
		printf("%d is an ancestor of %d.\n", b, a);
	}
}

int main() {
	int m, n, val;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		in.push_back(val);
		pos[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		pre.push_back(val);
	}
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (pos.find(a) == pos.end() && pos.find(b) == pos.end()) {
			printf("ERROR: %d and %d are not found.\n", a, b);
		} else if (pos.find(a) == pos.end() || pos.find(b) == pos.end()) {
			printf("ERROR: %d is not found.\n", pos.find(a) == pos.end() ? a : b);
		} else {
			search(a, b, 0, 0, n - 1);
		}
	}
}