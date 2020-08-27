#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, target;
int v[10010];
int flag[10010] = {0};
int dp[110] = {0};
int choose[10010][110] = {0};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d %d", &n, &target);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int C = target; C >= v[i]; C--) {
            if (dp[C] <= dp[C-v[i]] + v[i]) {
                dp[C] = dp[C-v[i]] + v[i];
                choose[i][C] = 1;
            } else {
                choose[i][C] = 0;
            }
        }
    }
    if (dp[target] != target) printf("No Solution");
    else {
        int k = n, j = target, cnt = 0;
        while (k >= 0) {
            if (choose[k][j]) {
                flag[k] = 1;
                j -= v[k];
                cnt++;
            }
            k--;
        }
        for (int i = n; i >= 1; i--) {
            if (flag[i]) {
                printf("%d", v[i]);
                cnt--;
                if (cnt > 0) printf(" ");
            }
        }
    }
}
