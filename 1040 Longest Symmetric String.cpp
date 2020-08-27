#include <iostream>
#include <string>
#define MAXN 1001
using namespace std;

int dp[MAXN][MAXN] = {0};

int main() {
    int ans = 1;
    string s;
    getline(cin, s);
    int len = s.size();
    if (len == 0 || len == 1) {
        cout << len;
        return 0;
    }
    for (int i = len - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < len; j++) {
            if (j == i + 1) {
                dp[i][j] = s[i] == s[j];
            } else {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }
            if (dp[i][j] && (j - i + 1 > ans)) {
                ans = j - i + 1;
            }
        }
    }
    cout << ans;
}
