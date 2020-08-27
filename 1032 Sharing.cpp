#include <cstdio>
#include <map>
using namespace std;

typedef struct {
    char data;
    int next;
    bool flag;
} Node;
map<int, Node> mp; //time consuming, can be replaced with structure array

int main() {
    int x, y, n, p;
    int addr, next;
    char data;
    scanf("%d %d %d", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &addr, &data, &next);
        mp[addr].data = data;
        mp[addr].next = next;
        mp[addr].flag = false;
    }
    for (p = x; p != -1; p = mp[p].next) {
        mp[p].flag = true;
    }
    for (p = y; p != -1; p = mp[p].next) {
        if (mp[p].flag) break;
    }
    if (p == -1) {
        printf("-1");
    } else {
        printf("%05d", p);
    }
}
