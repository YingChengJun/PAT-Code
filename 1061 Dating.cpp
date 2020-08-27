#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

char* dates[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int pos = 0, type = 0;
    int dd, hh, mm;
    while (pos < min(a.size(), b.size())) {
        if (a[pos] == b[pos]) {
            if (type == 0 && a[pos] >= 'A' && a[pos] <= 'G') {
                dd = a[pos] - 'A';
                type = 1;
            } else if (type == 1 && ((a[pos] >= '0' && a[pos] <= '9') || (a[pos] >= 'A' && a[pos] <= 'N'))) {
                hh = a[pos] >= '0' && a[pos] <= '9' ? a[pos] - '0' : a[pos] - 'A' + 10;
                break;
            }
        }
        pos++;
    }
    pos = 0;
    while (pos < min(c.size(), d.size())) {
        if (c[pos] == d[pos] && ((c[pos] >= 'a' && c[pos] <= 'z') || (c[pos] >= 'A' && c[pos] <= 'Z'))) break;
        pos++;
    }
    printf("%s %02d:%02d", dates[dd], hh, pos);
}
