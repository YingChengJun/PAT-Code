#include <cstdio>
#include <vector>
#define MAXN 1024
#define LEFT(x) (2*(x))
#define RIGHT(x) (2*(x)+1)
using namespace std;

int n;
int a[MAXN];
bool isMax = true, isMin = true;
vector<int> path;

void dfs(int cur) {
    path.push_back(a[cur]);
    if (RIGHT(cur) <= n && a[RIGHT(cur)] > a[cur]) isMax = false;
    if (LEFT(cur) <= n && a[LEFT(cur)] > a[cur]) isMax = false;
    if (RIGHT(cur) <= n && a[RIGHT(cur)] < a[cur]) isMin = false;
    if (LEFT(cur) <= n && a[LEFT(cur)] < a[cur]) isMin = false;
    if (LEFT(cur) > n && RIGHT(cur) > n) {
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
    } else {
        if (RIGHT(cur) <= n) {
            dfs(RIGHT(cur));
        }
        if (LEFT(cur) <= n) {
            dfs(LEFT(cur));
        }
    }
    path.pop_back();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    dfs(1);
    if (isMax) {
        printf("Max Heap");
    } else if (isMin) {
        printf("Min Heap");
    } else {
        printf("Not Heap");
    }
}
