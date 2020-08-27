#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, num, sum = 0, s1 = 0;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        v.push_back(num);
        sum += num;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; i++) {
        s1 += v[i];
    }
    if (n % 2) {
        printf("%d %d", 1, sum - 2 * s1);
    } else {
        printf("%d %d", 0, sum - 2 * s1);
    }


}

