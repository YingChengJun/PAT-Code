#include <cstdio>
#include <vector>
#define MAXN 1024
using namespace std;

int n;
vector<int> G[MAXN];
vector<int> ans;

int main() {
    int query, m, num, src, des;
    vector<int> deg;
    scanf("%d %d", &n, &m);
    deg.resize(n + 1);
    for (int i = 0; i < m; i++) {
       scanf("%d %d", &src, &des);
       G[src].push_back(des);
       deg[des]++;
    }
    scanf("%d", &query);
    for (int k = 0; k < query; k++) {
        bool flag = true;
        vector<int> temp = deg;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            if (!flag) continue;
            if (temp[num] == 0) {
                for (int j = 0; j < G[num].size(); j++) {
                    temp[G[num][j]]--;
                }
            } else {
                ans.push_back(k);
                flag = false;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", ans[i]);
    }
}
