#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, bool> mp;

int main() {
    int m, n, x, y, val;
    vector<int> pre;
    scanf("%d %d", &m, &n);
    while (n--) {
        scanf("%d", &val);
        mp[val] = true;
        pre.push_back(val);
    }
    while (m--) {
        int ans;
        scanf("%d %d", &x, &y);
        for (int i = 0; i < pre.size(); i++) {
            if (pre[i] >= min(x, y) && pre[i] <= max(x, y)) {
                ans = pre[i];
                break;
            }
        }
        if (mp[x] == 0 && mp[y] == 0)
            printf("ERROR: %d and %d are not found.\n", x, y);
        else if (mp[x] == 0)
            printf("ERROR: %d is not found.\n", x);
        else if (mp[y] == 0)
            printf("ERROR: %d is not found.\n", y);
        else if (ans == x || ans == y)
            printf("%d is an ancestor of %d.\n", ans == x ? x : y, ans == x ? y : x);
        else
            printf("LCA of %d and %d is %d.\n", x, y, ans);
    }
}
