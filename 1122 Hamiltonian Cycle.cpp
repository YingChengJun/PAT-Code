#include <cstdio>
#include <vector>
#define MAXN 256
using namespace std;
int n, m;
int G[MAXN][MAXN] = {0};

bool check(vector<int> &v) {
    int vis[MAXN] = {0};
    int src, des;
    for (int i = 0; i < v.size() - 1; i++) {
        src = v[i];
        des = v[i + 1];
        if (vis[src] || G[src][des] == 0) return false;
        vis[src] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return false;
    }
    return true;
}

int main() {
    int src, des, r, nums;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &src, &des);
        G[src][des] = 1;
        G[des][src] = 1;
    }
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        vector<int> v;
        scanf("%d", &nums);
        v.resize(nums);
        for (int j = 0; j < nums; j++) {
            scanf("%d", &v[j]);
        }
        if (nums <= n || v[0] != v[nums - 1]) {
            printf("NO\n", v[0], v[nums - 1]);
        } else {
            bool ans = check(v);
            printf("%s\n", ans ? "YES": "NO");
        }
    }
}
