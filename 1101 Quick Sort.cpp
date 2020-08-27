#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n), dp(n), dp2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        dp[i] = i > 0 ? max(dp[i - 1], v[i]): v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        dp2[i] = i < n - 1 ? min(dp2[i + 1], v[i]): v[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (dp[i] == v[i] && dp2[i] == v[i]) {
            ans.push_back(v[i]);
        }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
