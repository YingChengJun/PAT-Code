#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void nextSort(vector<int> &v, int p) {
    int temp = v[p];
    int i;
    for (i = p - 1; i >= 0; i--) {
        if (v[i] > temp) {
            v[i + 1] = v[i];
        } else {
            break;
        }
    }
    v[i + 1] = temp;
}

void nextSort(vector<int> &v, vector<int> &seq) {
    int gap = 1, flag = 1, n = v.size();
    while (flag) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != seq[i]) flag = 1;
        }
        gap *= 2;
        for (int i = 0; i < n / gap; i++) {
            sort(v.begin() + i * gap, v.begin() + (i + 1) * gap);
        }
        sort(v.begin() + n / gap * gap, v.begin() + n);
    }
    seq = v;
}


int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n), seq(n), temp(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++) scanf("%d", &seq[i]);
    int p = 1, index;
    while (p < n && seq[p - 1] <= seq[p]) p++;
    index = p;
    while (p < n && seq[p] == v[p]) p++;
    if (p == n) {
        printf("Insertion Sort\n");
        nextSort(seq, index);
    } else {
        printf("Merge Sort\n");
        nextSort(v, seq);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", seq[i]);
    }
}
