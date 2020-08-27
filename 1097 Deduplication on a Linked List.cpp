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
map<int, bool> mp;

int findNext(int p, bool flag) {
    if (p == -1) return -1;
    p = node[p].next;
    for (; p != -1; p = node[p].next) {
        if (node[p].valid == flag) return p;
    }
    return -1;
}

int main() {
    int head, n;
    int addr, data, next;
    int validcnt = 0, invalidcnt = 0;
    scanf("%d %d", &head, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].addr = addr;
        node[addr].data = data;
        node[addr].next = next;
        node[addr].valid = false;
    }
    for (int p = head; p != -1; p = node[p].next) {
        data = abs(node[p].data);
        if (mp.find(data) == mp.end()) { //not exist
            mp[data] = true;
            node[p].valid = true;
            validcnt++;
        } else {
            node[p].valid = false;
            invalidcnt++;
        }
    }
    for (int p = head; p != -1 && validcnt > 0; p = node[p].next) {
        if (node[p].valid == false) continue;
        if (validcnt == 1) {
            printf("%05d %d -1\n", p, node[p].data);
        } else {
            printf("%05d %d %05d\n", p, node[p].data, findNext(p, true));
        }
        validcnt--;
    }
    for (int p = head; p != -1 && invalidcnt > 0; p = node[p].next) {
        if (node[p].valid == true) continue;
        if (invalidcnt == 1) {
            printf("%05d %d -1\n", p, node[p].data);
        } else {
            printf("%05d %d %05d\n", p, node[p].data, findNext(p, false));
        }
        invalidcnt--;
    }

}
