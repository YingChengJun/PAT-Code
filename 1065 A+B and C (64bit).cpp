#include <cstdio>

int main() {
    int r;
    long long a, b, c, res;
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        bool flag = true;
        scanf("%lld %lld %lld", &a, &b, &c);
        res = a + b;
        if (a > 0 && b > 0 && res < 0) flag = true;
        else if (a < 0 && b < 0 && res >= 0) flag = false;
        else if (res > c) flag = true;
        else flag = false;
        if (flag) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
}
