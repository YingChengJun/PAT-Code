#include <cstdio>
#include <vector>
#include <set>
#define MAXN 10000
using namespace std;

vector<set<int> > G;

bool check(vector<set<int> > G, vector<int> &vertexs) {
    for (int i = 0; i < vertexs.size(); i++) {
        int v = vertexs[i];
        for (set<int>::iterator it = G[v].begin(); it != G[v].end(); it++) {
            int u = *it;
            G[u].erase(v);
        }
        G[v].clear();
    }
    for (int i = 0; i < G.size(); i++) {
        if (!G[i].empty()) return false;
    }
    return true;
}

int main() {
    int n, m;
    int src, des;
    scanf("%d %d", &n, &m);
    G.resize(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &src, &des);
        G[src].insert(des);
        G[des].insert(src);
    }
    int query, nums;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        vector<int> vertexs;
        scanf("%d", &nums);
        vertexs.resize(nums);
        for (int j = 0; j < nums; j++) {
            scanf("%d", &vertexs[j]);
        }
        printf("%s\n", check(G, vertexs)? "Yes": "No");
    }
}
