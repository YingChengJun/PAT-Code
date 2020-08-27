#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int sqr = sqrt(1.0 * n), ansIndex = 0, ansLen = 0;
    for (int i = 2; i <= sqr; i++) {
        long long temp = 1;
        int j = i;
        while (1) {
            temp *= j;
            if (n % temp != 0) break;
            if (j - i + 1 > ansLen) {
                ansIndex = i;
                ansLen = j - i + 1;
            }
            j++;
        }
    }
    if (ansLen == 0) {
        printf("1\n%d", n);
    } else {
        printf("%d\n", ansLen);
        for (int i = 0; i < ansLen; i++) {
            printf("%d", ansIndex + i);
            if (i < ansLen - 1) {
                printf("*");
            }
        }
    }
}
