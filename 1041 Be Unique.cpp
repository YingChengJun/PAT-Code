#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int mp[10001] = {0};

int main() {
    int n;
    int ans = -1;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 1) {
            ans = a[i];
            break;
        }
    }
    if (ans >= 0) {
        printf("%d", ans);
    } else {
        printf("None");
    }
}
