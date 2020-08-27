#include <cstdio>
#include <algorithm>
#define MAXN 100000
#define INF 99999999
using namespace std;

int head, n, k;
struct Node {
    int id = INF;
    int addr;
    int data;
    int next = -1;
    bool operator < (const Node &node) const {
        if (id == INF || node.id == INF) {
            return id < node.id;
        }
        if ((data < 0 && node.data < 0) ||
                (data >= 0 && node.data >= 0 && data <= k && node.data <= k) ||
                (data > k && node.data > k)) {
            return id < node.id;
        }
        return data < node.data;
    }
} node[MAXN];

int main() {
    int addr, data, next;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].data = data;
        node[addr].next = next;
        node[addr].addr = addr;
    }
    int id = 0;
    for (int p = head; p != -1; p = node[p].next) {
        node[p].id = id++;
    }
    sort(node, node + MAXN);
    for (int i = 0; i < id; i++) {
        if (i != id - 1)
            printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
        else
            printf("%05d %d -1\n", node[i].addr, node[i].data);
    }
}
