#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
struct Node {
    int addr;
    int data;
    int next;
    bool valid;
} node[MAXN];

bool cmp(Node a, Node b) {
    if (!a.valid || !b.valid) {
        return a.valid > b.valid;
    } else {
        return a.data < b.data;
    }
}

int main() {
    int cnt = 0;
    int n, head, addr, data, next;
    scanf("%d %d", &n, &head);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].addr = addr;
        node[addr].data = data;
        node[addr].next = next;
        node[addr].valid = false;
    }
    for (int p = head; p != -1; p = node[p].next) {
        node[p].valid = true;
        cnt++;
    }
    if (cnt == 0) {
        printf("0 -1");  //prevent the case of -00001
    } else {
        sort(node, node + MAXN, cmp);
        printf("%d %05d\n", cnt, node[0].addr);
        for (int i = 0; i < cnt; i++) {
            if (i < cnt - 1) {
                printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
            } else {
                printf("%05d %d -1\n", node[i].addr, node[i].data);
            }
        }
    }
}
