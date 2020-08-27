#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, num;
    int ans = 0;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int left = 0, right = n;
    int mid, j;
    while (left <= right) {
        mid = (left + right) / 2;
        j = n - 1;
        while (v[j] > mid) { j--; }
        if (n - j <= mid) {
            right = mid - 1;
        } else if (n - j > mid) {
            left = mid + 1;
            ans = max(ans, mid);
        }
    }
    printf("%d", ans);
}
