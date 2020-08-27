#include <cstdio>
#include <set>
using namespace std;

int main() {
    int n, num, sum;
    set<int> st;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        st.insert(sum);
    }
    printf("%d\n", st.size());
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        if (it != st.begin()) printf(" ");
        printf("%d", *it);
    }
}
