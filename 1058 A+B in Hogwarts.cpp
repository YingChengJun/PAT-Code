#include <cstdio>
using namespace std;

int main() {
    int ax, ay, az, bx, by, bz;
    scanf("%d.%d.%d %d.%d.%d", &ax, &ay, &az, &bx, &by, &bz);
    az += bz;
    if (az >= 29) {
        ay += az / 29;
        az %= 29;
    }
    ay += by;
    if (ay >= 17) {
        ax += ay / 17;
        ay %= 17;
    }
    ax += bx;
    printf("%d.%d.%d", ax, ay, az);

}
