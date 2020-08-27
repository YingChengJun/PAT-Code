#include <cstdio>
#include <algorithm>
using namespace std;

int pow(int c, int e) {
    int ans = 1;
    for (int i = 1; i <= e; i++) ans *= c;
    return ans;
}

bool isCut(int n) {
    int digit = 0;
    int temp = n;
    while (temp > 0) {
        temp /= 10;
        digit++;
    }
    int base = pow(10, digit / 2);
    if ((n / base) == 0 || (n % base) == 0) return false;
    return n % ((n / base) * (n % base)) == 0;
}

int main() {
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        printf("%s\n", isCut(num) ? "Yes": "No");
    }
}
