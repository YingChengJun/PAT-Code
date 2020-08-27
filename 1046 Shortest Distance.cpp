#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    int m, d, src, des;
    int tot = 0;
    int dis[100001];
    scanf("%d", &n);
    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d);
        dis[i + 1] = dis[i] + d;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &src, &des);
        if (des < src) swap(src, des);
        int ans = dis[des] - dis[src];
        ans = min(ans, dis[n + 1] - ans);
        printf("%d\n", ans);
    }
}
