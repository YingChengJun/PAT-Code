#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1001
using namespace std;

int n;
int father[MAXN] = {0};
int cnt[MAXN] = {0};
vector<vector<int> > v;

int Find(int x) {
    if (father[x] == 0) {
        return x;
    } else {
        return father[x] = Find(father[x]);
    }
}

int Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy) father[fy] = fx;
    return fx;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        vector<int> hs;
        int k, first, hobby;
        scanf("%d: ", &k);
        scanf("%d", &first);
        hs.push_back(first);
        for (int j = 1; j < k; j++) {
            scanf("%d", &hobby);
            Union(first, hobby);
            hs.push_back(hobby);
        }
        v.push_back(hs);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        int root = Find(v[i][0]);
        if (cnt[root] == 0) count++;
        cnt[root]++;
    }
    printf("%d\n", count);
    sort(cnt, cnt + MAXN);
    printf("%d", cnt[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        if (cnt[i] == 0) break;
        printf(" %d", cnt[i]);
    }
}
