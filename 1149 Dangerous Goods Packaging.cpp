#include <cstdio>
#include <vector>
#include <set>
#define MAXN 100000
using namespace std;

set<int> S[MAXN];

int main() {
    int n, k, a, b, nums, p, q;
    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d %d", &a, &b);
        S[a].insert(b);
        S[b].insert(a);
    }
    while (k--) {
        bool flag = true;
        scanf("%d", &nums);
        vector<int> v;
        for (int i = 0; i < nums; i++) {
            scanf("%d", &p);
            v.push_back(p);
        }
        for (int i = 0; i < nums; i++) {
            for (int j = i + 1; j < nums; j++) {
                a = v[i], b = v[j];
                if (S[a].find(b) != S[a].end()) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        printf("%s\n", flag ? "Yes": "No");
    }
}
