#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long n, p;

int main() {
    scanf("%lld %lld", &n, &p);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        while (i + ans - 1 < n && a[i + ans - 1] <= p * a[i]) ans++;
    }
    printf("%d", ans - 1);
}
