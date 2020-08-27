#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;

bool cmp(int x, int y) {
    return x > y;
}

void init() {
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            n = k / i;
            m = i;
        }
    }
}

int main() {
    scanf("%d", &k);
    init();
    vector<int> v(k);
    for (int i = 0; i < k; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), cmp);
    vector<vector<int> > ans(n, vector<int>(m));
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int j = 0;
    while (j < k) {
        for (int i = left; i <= right; i++) {
            ans[top][i] = v[j++];
        }
        if (j >= k) break;
        top++;
        for (int i = top; i <= bottom; i++) {
            ans[i][right] = v[j++];
        }
        if (j >= k) break;
        right--;
        for (int i = right; i >= left; i--) {
            ans[bottom][i] = v[j++];
        }
        if (j >= k) break;
        bottom--;
        for (int i = bottom; i >= top; i--) {
            ans[i][left] = v[j++];
        }
        left++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
