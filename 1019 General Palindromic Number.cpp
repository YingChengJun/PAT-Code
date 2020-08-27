#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> rv;

void output(vector<int>& vv) {
    for (int i = 0; i < vv.size(); i++) {
        if (i > 0)
            printf(" %d", vv[i]);
        else
            printf("%d", vv[i]);
    }
}

int main() {
    int n, base;
    scanf("%d %d", &n, &base);
    do {
        v.push_back(n % base);
        n /= base;
    } while (n > 0);
    rv = v;
    reverse(rv.begin(), rv.end());
    if (v == rv) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    output(rv);
}
