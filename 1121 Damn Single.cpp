#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define MAXN 100000
using namespace std;

map<int, int> mp;
int a[MAXN];
vector<int> ans;

int main() {
    int n, m, x, y;
    fill(a, a + MAXN, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        mp[x] = y;
        mp[y] = x;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int i = 0; i < MAXN; i++) {
        if (a[i] && !a[mp[i]]) {
            ans.push_back(i);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) printf(" ");
        printf("%05d", ans[i]);
    }
}
