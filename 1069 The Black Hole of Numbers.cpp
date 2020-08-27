#include <cstdio>
#include <algorithm>
using namespace std;

int getMax(int n) {
    int num = 0;
    int a[4] = {0};
    while (n > 0) {
        a[num++] = n % 10;
        n /= 10;
    }
    sort(a, a + 4);
    return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

int getMin(int n) {
    int num = 0;
    int a[4] = {0};
    while (n > 0) {
        a[num++] = n % 10;
        n /= 10;
    }
    sort(a, a + 4);
    return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 6174) {
        printf("7641 - 1467 = 6174\n");
        return 0;
    }
    while (n != 6174 && n != 0) {
        int x = getMin(n);
        int y = getMax(n);
        printf("%04d - %04d = %04d\n", y, x, y - x);
        n = y - x;
    }
}
