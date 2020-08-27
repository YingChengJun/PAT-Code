#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 256
using namespace std;

int n;
int G[MAXN][MAXN] = {0};

int main() {
    int m, src, des, dist, nums;
    int ans = 1 << 30, index = -1;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &src, &des, &dist);
        G[src][des] = G[des][src] = dist;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &nums);
        vector<int> path(nums);
        for (int j = 0; j < nums; j++) {
            scanf("%d", &path[j]);
        }
        int dist = 0;
        int vis[MAXN] = {0};
        bool isSimple = true, isTS = true;
        vis[path[0]] = 1;
        for (int j = 1; j < nums; j++) {
            src = path[j - 1];
            des = path[j];
            if (!G[src][des]) {
                dist = -1;
                isTS = false;
                break;
            } else {
                dist += G[src][des];
                if (vis[des] && j < nums - 1) {
                    isSimple = false;
                } else {
                    vis[des] = 1;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                isTS = false;
                break;
            }
        }
        if (dist == -1) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else if (!isTS || path[0] != path[path.size() - 1]) {
            printf("Path %d: %d (Not a TS cycle)\n", i, dist);
        } else if (!isSimple) {
            printf("Path %d: %d (TS cycle)\n", i, dist);
        } else if (isSimple) {
            printf("Path %d: %d (TS simple cycle)\n", i, dist);
        }
        if (dist != -1 && isTS && dist < ans) {
            ans = dist;
            index = i;
        }
    }
    printf("Shortest Dist(%d) = %d", index, ans);
}
