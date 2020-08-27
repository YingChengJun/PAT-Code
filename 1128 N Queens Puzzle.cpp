#include <cstdio>
#include <algorithm>
using namespace std;

bool Judge(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) return false;
            if (abs(a[j] - a[i]) == abs(j - i)) {
                return false;
            }
        }
    }
}

int main() {
    int r, n;
    int a[1024];
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        printf("%s\n", Judge(a, n) ? "YES": "NO");
    }
}
