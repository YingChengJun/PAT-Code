#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 1001

int main() {
    int exp, m, n;
    double coef;
    double a[MAXN] = {0};
    double b[MAXN] = {0};
    double c[2*MAXN] = {0};
    int i, j;
    int exp_a, exp_b;
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> exp >> coef;
        a[exp] = coef;
        if (i == 0) exp_a = exp;
    }
    cin >> n;
    for (j = 0; j < n; j++) {
        cin >> exp >> coef;
        b[exp] = coef;
        if (j == 0) exp_b = exp;
        for (i = 0; i <= exp_a; i++) {
            if (a[i] != 0) {
                c[i+exp] += b[exp] * a[i];
            }
        }
    }
    int count = 0;
    for (i = exp_a + exp_b; i >= 0; i--) {
        if (c[i] != 0) count++;
    }
    cout << count;
    for (i = exp_a + exp_b; i >= 0; i--) {
        if (c[i] != 0) printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
