#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct fraction {
    long long up, down;
} a, b;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

fraction reduct(fraction res) {
    if (res.down < 0) {
        res.down *= -1;
        res.up *= -1;
    }
    if (res.up == 0) res.down = 1;
    else {
        long long d = gcd(abs(res.up), res.down);
        res.up /= d;
        res.down /= d;
    }
    return res;
}

fraction add(fraction x, fraction y) {
    fraction res;
    res.up = x.up * y.down + x.down * y.up;
    res.down = x.down * y.down;
    return reduct(res);
}

fraction minu(fraction x, fraction y) {
    fraction res;
    res.up = x.up * y.down - x.down * y.up;
    res.down = x.down * y.down;
    return reduct(res);
}

fraction mult(fraction x, fraction y) {
    fraction res;
    res.up = x.up * y.up;
    res.down = x.down * y.down;
    return reduct(res);
}

fraction div(fraction x, fraction y) {
    fraction res;
    res.up = x.up * y.down;
    res.down = x.down * y.up;
    return reduct(res);
}

void print(fraction res) {
    res = reduct(res);
    if (res.up < 0) printf("(");
    if (res.down == 1) printf("%lld", res.up);
    else if (abs(res.up) > res.down) {
        printf("%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down);
    } else {
        printf("%lld/%lld", res.up, res.down);
    }
    if (res.up < 0) printf(")");
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

    print(a);
    printf(" + ");
    print(b);
    printf(" = ");
    print(add(a, b));
    printf("\n");

    print(a);
    printf(" - ");
    print(b);
    printf(" = ");
    print(minu(a, b));
    printf("\n");

    print(a);
    printf(" * ");
    print(b);
    printf(" = ");
    print(mult(a, b));
    printf("\n");

    print(a);
    printf(" / ");
    print(b);
    printf(" = ");
    if (b.up == 0) printf("Inf");
    else print(div(a, b));
}
