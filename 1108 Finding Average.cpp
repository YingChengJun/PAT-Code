#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int n, flag, index, cnt = 0, i;
    double sum = 0, ans = 0;
    char num[100];
    scanf("%d%*c", &n);
    for (int j = 0; j < n; j++) {
        scanf("%s", num);
        ans = 0;
        flag = 1;
        index = -1;
        for (i = 0; i < strlen(num); i++) {
            if (i == 0 && num[0] == '-') {
                flag = -1;
                continue;
            }
            if (num[i] >= '0' && num[i] <= '9') {
                if (index == -1) {
                    ans = ans * 10 + num[i] - '0';
                } else if (i - index == 1) {
                    ans += (num[i] - '0') * 0.1;
                } else if (i - index == 2) {
                    ans += (num[i] - '0') * 0.01;
                } else {
                    break;
                }
            } else if (num[i] == '.'){
                if (index == -1) index = i;
                else break;
            } else {
                break;
            }
        }
        if (i < strlen(num) || ans * flag < -1000 || ans * flag > 1000) {
            printf("ERROR: %s is not a legal number\n", num);
        } else {
            cnt++;
            sum += ans * flag;
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (cnt == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    } else {
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    }
}
