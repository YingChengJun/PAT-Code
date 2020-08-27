#include <cstdio>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int reverse(int x, int base) {
    if (x == 0) return 0;
    int r, ans = 0;
    while (x > 0) {
        r = x % base;
        x /= base;
        ans = ans * base + r;
    }
    return ans;
}

int main() {
    int n, r;
    scanf("%d", &n);
    while (n >= 0) {
        scanf("%d", &r);
        if (isPrime(n) && isPrime(reverse(n, r))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        scanf("%d", &n);
    }

}
