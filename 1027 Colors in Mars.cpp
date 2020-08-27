#include <cstdio>
using namespace std;

void output(int x, int y) {
    if (x >= 0 && x <= 9) printf("%d", x);
    else {
        printf("%c", 'A' + x - 10);
    }
    if (y >= 0 && y <= 9) printf("%d", y);
    else {
        printf("%c", 'A' + y - 10);
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("#");
    output(a / 13, a % 13);
    output(b / 13, b % 13);
    output(c / 13, c % 13);
}
