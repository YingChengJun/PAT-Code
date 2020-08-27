#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct fraction {
    long long up, down;
} v[100];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

fraction refact(fraction a) {
    if (a.up == 0) {
        a.down = 1;
    } else {
        if (a.down < 0) {
            a.up *= -1;
            a.down *= -1;
        }
        long long d = gcd(abs(a.up), a.down);
        a.up /= d;
        a.down /= d;
    }
    return a;
}

fraction add(fraction a, fraction b) {
    fraction res;
    res.up = a.up * b.down + b.up * a.down;
    res.down = a.down * b.down;
    return refact(res);
}

int main() {
    int n;
    scanf("%d", &n);
    fraction sum;
    sum.up = 0;
    sum.down = 1;
    for (int i = 0; i < n; i++) {
        fraction temp;
        scanf("%lld/%lld", &temp.up, &temp.down);
        sum = add(sum, temp);
    }
    if (sum.up % sum.down == 0) {
        printf("%lld", sum.up / sum.down);
    } else if (abs(sum.up) > sum.down) {
        printf("%lld %lld/%lld", sum.up / sum.down, abs(sum.up) % sum.down ,sum.down);
    } else {
        printf("%lld/%lld", sum.up, sum.down);
    }
}
