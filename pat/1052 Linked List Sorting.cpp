#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100000;
struct Node
{
	int addr;
	int data;
	int next = -1;
	int valid = 0;
} node[maxn];

bool cmp(Node& a, Node& b) {
	if (!a.valid || !b.valid) {
		return a.valid > b.valid;
	} else {
		return a.data < b.data;
	}
}

int main() {
	int addr, key, next;
	int head, n, cnt = 0;
	scanf("%d%d", &n, &head);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &addr, &key, &next);
		node[addr].addr = addr;
		node[addr].data = key;
		node[addr].next = next;
	}
	for (int p = head; p != -1; p = node[p].next) {
		node[p].valid = 1;
		cnt++;
	}
	sort(node, node + maxn, cmp);
	if (cnt == 0) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", cnt, node[0].addr);
	for (int i = 0; i < cnt; i++) {
		if (i == cnt - 1) {
			printf("%05d %d -1\n", node[i].addr, node[i].data);
		} else {
			printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
		}
	}
}