#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m, l;
vector<int> seq, dp;
map<int, int> mp;

int main() {
    int ans = 0;
    int k, cnt = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        mp[k] = cnt++;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &k);
        if (mp[k] > 0) {
            seq.push_back(mp[k]);
        }
    }
    for (int i = 0; i < seq.size(); i++) {
        dp.push_back(1);
        for (int j = 0; j < i; j++) {
            if (seq[j] <= seq[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
}
