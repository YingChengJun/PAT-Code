#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n, m;
vector<int> v;
vector<int> save;
vector<int> buffer;

int main() {
	scanf("%d %d", &n, &m);
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	int i;
	for (i = 0; i < m; i++) {
		q.push(v[i]);
	}
	while (!q.empty()) {
		int minV = 0x80000000;
		buffer.clear();
		while (i < n && !q.empty()) {
			int out = q.top();
			q.pop();
			buffer.push_back(out);
			minV = out;
			if (v[i] < minV) {
				save.push_back(v[i]);
			} else {
				q.push(v[i]);
			}
			i++;
		}
		if (i == n) {
			while (!q.empty()) {
				buffer.push_back(q.top());
				q.pop();
			}
		}
		for (int j = 0; j < buffer.size(); j++) {
			if (j > 0) printf(" ");
			printf("%d", buffer[j]);
		}
		printf("\n");
		for (int j = 0; j < save.size(); j++) {
			q.push(save[j]);
		}
		save.clear();
	}
}