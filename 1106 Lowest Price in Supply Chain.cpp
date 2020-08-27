#include <cstdio>
#include <vector>
#include <cmath>
#define MAXN 100000
using namespace std;

int cnt = 1;
int MIN = 9999999;

vector<int> node[MAXN];

void dfs(int root, int depth) {
    if (node[root].size() == 0) {
        if (depth < MIN) {
            MIN = depth;
            cnt = 1;
        } else if (depth == MIN) {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < node[root].size(); i++) {
        dfs(node[root][i], depth + 1);
    }
}

int main() {
    int n, m, id;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &id);
            node[i].push_back(id);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r / 100.0, MIN), cnt);
}
