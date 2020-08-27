#include <cstdio>
#include <vector>
#include <set>
#define MAXN 10001
using namespace std;

int S[MAXN];
set<int> st;

int Find(int x) {
    if (S[x] == x) {
        return x;
    } else {
        return S[x] = Find(S[x]);
    }
}

void Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy) {
        S[fx] = fy;
    }
}

int main() {
    int n, m, id, temp;
    for (int i = 0; i < MAXN; i++) S[i] = i;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &id);
            if (i == 0) temp = id;
            else Union(temp, id);
            st.insert(id);
        }
    }
    int ans = 0;
    for (int i = 1; i < MAXN; i++) {
        if (st.find(i) != st.end() && S[i] == i) {
            ans++;
        }
    }
    printf("%d %d\n", ans, st.size());
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &id);
        if (Find(m) == Find(id)) {
            printf("Yes");
        } else {
            printf("No");
        }
        if (i != n - 1) printf("\n");
    }
}
