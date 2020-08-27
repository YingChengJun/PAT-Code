#include <cstdio>

int main() {
    long long n;
    double num ,ans = 0;
    scanf("%ld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lf", &num);
        ans = ans + (i * (1 + n - i)) * num;
    }
    printf("%.2f", ans);
}
