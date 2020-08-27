#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int m, n, num;
    int maxcnt = 0, maxindex = -1;
    map<int, int> mp;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &num);
            mp[num]++;
            if (mp[num] > maxcnt) {
                maxindex = num;
                maxcnt = mp[num];
            }
        }
    cout << maxindex;
}
