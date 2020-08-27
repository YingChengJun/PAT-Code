#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int c = 0, p;
    string s;
    vector<int> a, b, ans;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        p = s[i] - '0';
        a.push_back(p);
        p = p * 2 + c;
        c = 0;
        if (p >= 10) {
            p -= 10;
            c = 1;
        }
        b.push_back(p);
    }
    if (c == 1) b.push_back(1);
    ans = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
}
