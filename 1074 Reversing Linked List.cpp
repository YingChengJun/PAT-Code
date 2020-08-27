#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
struct Node {
    int addr;
    int data;
    int next;
    int order;
} node[MAXN];

bool cmp(struct Node a, struct Node b) {
    if (a.order == 0 || b.order == 0) {
        return a.order - b.order > 0;
    } else {
        return a.order < b.order;
    }
}

int main() {
    int count = 0;
    int head, n, k;
    int addr, data, next;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].addr = addr;
        node[addr].data = data;
        node[addr].next = next;
    }
    for (int p = head; p != -1; p = node[p].next) {
        node[p].order = ++count;
    }
    sort(node, node + MAXN, cmp);
    int groups = count / k;
    for (int i = 0; i < groups; i++) {
        reverse(node + i * k, node + i * k + k);
    }
    for (int i = 0; i < count; i++) {
        if (i == count - 1) {
            printf("%05d %d -1\n", node[i].addr, node[i].data);
        } else {
            printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
        }
    }
}
