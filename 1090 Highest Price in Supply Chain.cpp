#include <cstdio>
#include <vector>
#include <cmath>
#define MAXN 100000
using namespace std;

int N;
double price, rate;
struct Node {
    int depth = 0;
    vector<int> child;
} node[MAXN];

void dfs(int root, int depth) {
    node[root].depth = depth;
    if (node[root].child.size() == 0)
        return;
    for (int i = 0; i < node[root].child.size(); i++) {
        dfs(node[root].child[i], depth + 1);
    }
}

int main() {
    int supplier;
    int root, depth = 0, cnt = 0;
    scanf("%d %lf %lf", &N, &price, &rate);
    for (int i = 0; i < N; i++) {
        scanf("%d", &supplier);
        if (supplier != -1) {
            node[supplier].child.push_back(i);
        } else {
            root = i;
        }
    }
    dfs(root, 0);
    for (int i = 0; i < N; i++) {
        if (node[i].depth > depth) {
            cnt = 1;
            depth = node[i].depth;
        } else if (node[i].depth == depth) {
            cnt++;
        }
    }
    printf("%.2f %d", price * pow((1 + rate / 100), depth), cnt);
}
