#include <cstdio>
#include <map>
#include <string>
using namespace std;

char str[3][16] = {"Mystery Award", "Minion", "Chocolate"};
map<int, int> mp;

bool isPrime(int x) {
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, id;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        if (i == 1) {
            mp[id] = 0;
        } else if (isPrime(i)) {
            mp[id] = 1;
        } else {
            mp[id] = 2;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        map<int, int>::iterator it = mp.find(id);
        printf("%04d: ", id);
        if (it != mp.end()) {
            if (it->second != -1) {
                printf("%s", str[it->second]);
                it->second = -1;
            } else {
                printf("Checked");
            }
        } else {
            printf("Are you kidding?");
        }
        if (i != n) printf("\n");
    }
}
