#include <cstdio>
#include <vector>
using namespace std;

struct Map {
    int Size;
    vector<int> v;
    Map(int n): Size(n) {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            v[i] = -1;
        }
    }
    bool Insert(int num) {
        int a = num % Size;
        int step = 0, pos;
        while (step < Size) {
            pos = (a + step * step) % Size;
            if (v[pos] == -1) {
                v[pos] = num;
                return true;
            } else {
                step++;
            }
        }
        return false;
    }
    int Find(int num) {
        int a = num % Size;
        int step = 0, pos;
        while (step < Size) {
            pos = (a + step * step) % Size;
            if (v[pos] == num || v[pos] == -1) {
                return step + 1;
            } else {
                step++;
            }
        }
        return step + 1;
    }
};

bool isPrime(int n) {
    if (n < 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}


int main() {
    int sz, n, m, num, ans = 0;
    scanf("%d %d %d", &sz, &n, &m);
    Map mp(nextPrime(sz));
    while (n--) {
        scanf("%d", &num);
        if (!mp.Insert(num)) {
            printf("%d cannot be inserted.\n", num);
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        ans += mp.Find(num);
    }
    printf("%.1f", 1.0 * ans / m);
}
