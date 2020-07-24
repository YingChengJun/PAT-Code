#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100000;
struct Node
{
	char val;
	int next = -1;
	int count = 0;
} v[maxn];

int main() {
	int w1, w2, n;
	scanf("%d %d %d", &w1, &w2, &n);
	for (int i = 0; i < n; i++) {
		int addr, next;
		char data;
		scanf("%d %c %d", &addr, &data, &next);
		v[addr].val = data;
		v[addr].next = next;
	}
	for (int p = w1; p != -1; p = v[p].next) {
		v[p].count = 1;
	}
	int ans = -1;
	for (int p = w2; p != -1; p = v[p].next) {
		if (v[p].count) {
			ans = p;
			break;
		}
	}
	if (ans == -1) {
		printf("-1");
	} else {
		printf("%05d", ans);
	}

}