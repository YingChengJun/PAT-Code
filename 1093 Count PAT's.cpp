#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long ans = 0;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    vector<int> dp1(len), dp2(len);
    dp1[0] = s[0] == 'P' ? 1 : 0;
    dp2[len - 1] = s[len - 1] == 'T' ? 1 : 0;
    for (int i = 1; i < len; i++) {
        dp1[i] = s[i] == 'P' ? dp1[i - 1] + 1 : dp1[i - 1];
    }
    for (int i = len - 2; i >= 0; i--) {
        dp2[i] = s[i] == 'T' ? dp2[i + 1] + 1 : dp2[i + 1];
    }
    for (int i = 1; i < len - 1; i++) {
        if (s[i] == 'A') {
            ans = (ans + dp1[i - 1] * dp2[i + 1]) % 1000000007;
        }
    }
    cout << ans;
}
