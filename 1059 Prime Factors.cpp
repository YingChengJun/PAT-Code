#include <cstdio>

long long nextPrime(long long p) {
    while (++p) {
        bool flag = true;
        for (long long i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) return p;
    }
}

int main() {
    long long n;
    long long p = 2;
    bool flag = false;
    scanf("%lld", &n);
    if (n == 1) {
        printf("1=1");
        return 0;
    }
    printf("%lld=", n);
    while (n > 1) {
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        if (cnt > 0) {
            if (flag) printf("*");
            else flag = true;
            if (cnt == 1) printf("%lld", p);
            else printf("%lld^%d", p, cnt);
        }
        p = nextPrime(p);
    }
}
