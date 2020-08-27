#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int mp[100001];

void Swap(vector<int> &a, int px, int py) {
    int vx = a[px], vy = a[py];
    mp[vx] = py;
    mp[vy] = px;
    swap(a[px], a[py]);
}

int main() {
    int n;
    int ans = 0, pos = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i;
    }
    int j = 1;
    while (1) {
        int indexOfZero = mp[0];
        int indexOfValue = mp[indexOfZero];
        if (indexOfZero == 0) {
            for (; j < n; j++) {
                if (mp[j] != j) break;
            }
            if (j == n) break;
            else Swap(a, indexOfZero, j);
        }
        Swap(a, indexOfZero, indexOfValue);
        ans++;
    }
    printf("%d", ans);
}
