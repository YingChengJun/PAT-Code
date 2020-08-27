#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

void calc(set<int> &a, set<int> &b) {
    int same = 0;
    int total = 0;
    //can replace with "auto ita = a.begin();"
    set<int>::iterator ita = a.begin();
    set<int>::iterator itb = b.begin();
    while (ita != a.end() && itb != b.end()) {
        if (*ita < *itb) {
            ita++;
        } else if (*ita > *itb) {
            itb++;
        } else {
            same++;
            ita++;
            itb++;
        }
        total++;
    }
    while (ita != a.end()) {
        total++;
        ita++;
    }
    while (itb != b.end()) {
        total++;
        itb++;
    }
    printf("%.1f%%\n", 1.0 * same / total * 100);
}

int main() {
    int n, m, k;
    int i, j;
    int num, rd;
    set<int> vs[51];
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &num);
        for (j = 0; j < num; j++) {
            scanf("%d", &rd);
            vs[i].insert(rd);
        }
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &m, &k);
        calc(vs[m], vs[k]);
    }
    return 0;
}

