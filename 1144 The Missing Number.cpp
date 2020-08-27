#include <cstdio>
#include <set>
using namespace std;

int main() {
    int n, num;
    set<int> st;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &num);
        if (num > 0) st.insert(num);
    }
    int ans = 1;
    while (ans) {
        if (st.find(ans) == st.end()) break;
        ans++;
    }
    printf("%d", ans);
}
