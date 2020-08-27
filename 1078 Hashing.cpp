#include <cstdio>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    if (isPrime(n)) return n;
    while (true) {
        if (isPrime(++n)) return n;
    }
}

int insert(vector<int> &a, int num, int Size) {
    int r = num % Size;
    int i, pos;
    for (i = 0; i <= Size; i++) {
        pos = (r + i * i) % Size;
        if (a[pos] == -1) {
            a[pos] = num;
            return pos;
        }
    }
    return -1;
}

int main() {
    int n, m, num;
    scanf("%d %d", &n, &m);
    n = nextPrime(n);
    vector<int> a(n, -1);
    for (int i = 0; i < m; i++) {
        if (i > 0) printf(" ");
        scanf("%d", &num);
        int pos = insert(a, num, n);
        if (pos >= 0) {
            printf("%d", pos);
        } else {
            printf("-");
        }
    }
}
