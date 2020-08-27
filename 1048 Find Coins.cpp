#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    int v1 = 999;
    map<int, bool> mp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        map<int, bool>::iterator it = mp.find(m - k);
        if (it != mp.end()) {
            int v = min(k, m - k);
            if (v < v1)
                v1 = v;
        } else
            mp[k] = true;
    }
    if (v1 == 999) {
        printf("No Solution");
    } else {
        printf("%d %d", v1, m - v1);
    }
}
