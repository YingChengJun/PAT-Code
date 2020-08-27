#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, i, j;
    int len = 9999;
    string ss[100];
    cin >> n;
    getchar();
    for (i = 0; i < n; i++) {
        getline(cin, ss[i]);
        int sz = ss[i].size();
        len = min(len, sz);
        reverse(ss[i].begin(), ss[i].end());
    }
    for (i = 0; i < len; i++) {
        for (j = 1; j < n; j++) {
            if (ss[j][i] != ss[0][i]) break;
        }
        if (j < n) break;
    }
    if (i == 0) {
        cout << "nai";
    } else {
        for (j = i - 1; j >= 0; j--) {
            printf("%c", ss[0][j]);
        }
    }
}
