#include <cstdio>

int a[55] = {0};
int ans[55];
int temp[55];

void shuffle() {
    for (int i = 1; i <= 54; i++) {
        temp[a[i]] = ans[i];
    }
    for (int i = 1; i <= 54; i++) {
        ans[i] = temp[i];
    }
}

void print(int k, bool blank) {
    if (blank)
        printf(" ");
    int q = (k - 1) / 13;
    int r = (k - 1) % 13;
    if (q == 0) {
        printf("S");
    } else if (q == 1) {
        printf("H");
    } else if (q == 2) {
        printf("C");
    } else if (q == 3) {
        printf("D");
    } else if (q == 4) {
        printf("J");
    }
    printf("%d", r + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 54; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= 54; i++) {
        ans[i] = i;
    }
    for (int i = 0; i < n; i++) {
        shuffle();
    }
    for (int i = 1; i <= 54; i++) {
        print(ans[i], i != 1);
    }
}
