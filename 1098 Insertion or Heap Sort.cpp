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

void nextSort(vector<int> &v) {
    int i = v.size() - 1;
    while (v[i] >= v[0]) i--;
    swap(v[0], v[i]);
    i--;
    int child;
    for (int j = 0; 2 * j + 1 <= i; j = child) {
        child = 2 * j + 1;
        if (child + 1 <= i && v[child + 1] > v[child]) child++;
        swap(v[j], v[child]);
    }
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
        printf("Heap Sort\n");
        nextSort(seq);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", seq[i]);
    }
}
