#include <cstdio>
#include <cstring>
using namespace std;

int isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int pow(int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) ans *= 10;
    return ans;
}

void output(int n, int k) {
    int temp = n;
    int digit = 0;
    while (temp > 0) {
        temp /= 10;
        k--;
    }
    for (int i = 0; i < k; i++) printf("0");
    printf("%d", n);
}

int main() {
    int n, k, ans = 0;
    char c;
    scanf("%d %d%*c", &n, &k);
    if (n < k) {
        printf("404");
        return 0;
    }
    for (int i = 0; i < k; i++) {
        scanf("%c", &c);
        ans = ans * 10 + (c - '0');
        n--;
    }
    if (isPrime(ans)) {
        output(ans, k);
        return 0;
    }
    int base = pow(k - 1);
    while (n--) {
        scanf("%c", &c);
        ans = (ans % base) * 10 + (c - '0');
        if (isPrime(ans)) {
            output(ans, k);
            return 0;
        }
    }
    printf("404");
}
