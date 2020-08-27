#include <cstdio>
#include <cstring>
using namespace std;

char* num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char* wei[] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main() {
    char str[15];
    scanf("%s", str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if (str[0] == '-') {
        left++;
        printf("Fu");
    }
    while (left + 4 <= right) right -= 4;
    while (left < len) {
        bool flag = false;
        bool isPrint = false;
        while (left <= right) {
            if (left > 0 && str[left] == '0') {
                flag = true;
            } else {
                if (flag) {
                    printf(" ling");
                    flag = false;
                }
                if (left > 0) printf(" ");
                printf("%s", num[str[left] - '0']);
                isPrint = true;
                if (left != right) {
                    printf(" %s", wei[right - left - 1]);
                }
            }
            left++;
        }
        if (isPrint && right != len - 1) {
            printf(" %s", wei[(len - 1 - right) / 4 + 2]);
        }
        right += 4;
    }

}
