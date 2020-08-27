#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    scanf("%d", &m);
    a.resize(m + n);
    for (int i = n; i < m + n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());

    printf("%lld", a[ceil((m+n)/2.0)-1]);
}
