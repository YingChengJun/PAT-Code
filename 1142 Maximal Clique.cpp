#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 201
using namespace std;

int n, m;
int G[MAXN][MAXN] = {0};
int mp[MAXN];

bool isClique(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (!G[v[i]][v[j]]) return false;
        }
    }
    return true;
}

bool isMaxClique(vector<int> &v) {
    for (int i = 1; i <= n; i++) {
        if (mp[i]) continue;
        bool flag = true;
        for (int j = 0; j < v.size(); j++) {
            if (!G[i][v[j]]) {
                flag = false;
                break;
            }
        }
        if (flag) return false;
    }
    return true;
}


int main() {
    int query, src, des, nums, vv;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &src, &des);
        G[src][des] = 1;
        G[des][src] = 1;
    }
    scanf("%d", &query);
    while (query--) {
        vector<int> v;
        fill(mp, mp + MAXN, 0);
        scanf("%d", &nums);
        while (nums--) {
            scanf("%d", &vv);
            v.push_back(vv);
            mp[vv] = 1;
        }
        if (!isClique(v)) {
            printf("Not a Clique\n");
        } else if (!isMaxClique(v)){
            printf("Not Maximal\n");
        } else {
            printf("Yes\n");
        }
    }
}
