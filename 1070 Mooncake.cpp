#include <cstdio>
#include <algorithm>
using namespace std;

struct Cake {
    double remain;
    double cost;
    double price;
} cakes[1000];
int n, D;

bool cmp(Cake &a, Cake &b) {
    return a.price > b.price;
}

int main() {
    scanf("%d %d", &n, &D);
    for (int i = 0; i < n; i++) scanf("%lf", &cakes[i].remain);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cakes[i].cost);
        cakes[i].price = cakes[i].cost / cakes[i].remain;
    }
    sort(cakes, cakes + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (cakes[i].remain <= D) {
            D = D - cakes[i].remain;
            ans += cakes[i].cost;
        } else {
            ans += cakes[i].price * D;
            break;
        }
    }
    printf("%.2f", ans);
}
