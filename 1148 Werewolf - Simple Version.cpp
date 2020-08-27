#include <cstdio>
#include <vector>
#define MAXN 128
using namespace std;

int n;
int a[MAXN];

bool check(int p1, int p2) {
    int u = 0, w = 0;
    if ((a[p1] < 0 && -a[p1] != p1 && -a[p1] != p2)
        || (a[p1] > 0 && (a[p1] == p1 || a[p1] == p2))) {
        w++;
    }
    if ((a[p2] < 0 && -a[p2] != p1 && -a[p2] != p2)
        || (a[p2] > 0 && (a[p2] == p1 || a[p2] == p2))) {
        w++;
    }
    if (w != 1) return false;
    for (int i = 1; i <= n; i++) {
        if (i == p1 || i == p2) continue;
        if (a[i] < 0 && -a[i] != p1 && -a[i] != p2) u++;
        if (a[i] > 0 && (a[i] == p1 || a[i] == p2)) u++;
    }
    return u == 1;
}

int main() {
    int num;
    bool ans = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (ans)
            break;
        for (int j = i + 1; j <= n; j++) {
            if (check(i, j)) {
                ans = true;
                printf("%d %d", i, j);
                break;
            }
        }
    }
    if (!ans)
        printf("No Solution");
}
