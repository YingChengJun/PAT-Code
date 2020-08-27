#include <cstdio>
using namespace std;

int main() {
    char c[3] = {'W', 'T', 'L'};
    double a[3][3];
    double profit = 0.65;
    for (int i = 0; i < 3; i++) {
        int index = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &a[i][j]);
            if (a[i][index] < a[i][j])
                index = j;
        }
        printf("%c ", c[index]);
        profit *= a[i][index];
    }
    printf("%.2f", (profit - 1) * 2);
}
