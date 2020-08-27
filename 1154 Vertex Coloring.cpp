#include <cstdio>
#include <vector>
#include <set>
#define MAXN 10000
using namespace std;

struct Edge {
    int u;
    int v;
    //Edge(int uu, int vv): u(uu), v(vv) {};
} edges[MAXN];
int color[MAXN];

int main() {
    int m, n, x, y, query;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        edges[i].u = x;
        edges[i].v = y;
    }
    scanf("%d", &query);
    while (query--) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            st.insert(color[i]);
        }
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (color[edges[i].u] == color[edges[i].v]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            printf("No\n");
        } else {
            printf("%d-coloring\n", st.size());
        }
    }
}
