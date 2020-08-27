#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128

long long toBase10(char* x, int radix);
void itoa(char* x, long long v, int radix);

int main() {
    int tag, radix, i;
    char x[MAXLEN] = {0}, y[MAXLEN] = {0};
    scanf("%s %s %d %d", x, y, &tag, &radix);
    //char* itoa ( int value, char * str, int base );
    //int atoi(const char *str)
    if (tag == 1) {
        long long v = toBase10(x, radix);
        for (i = 2; i <= 36; i++) {
            itoa(x, v, i);
            if (strcmp(x, y) == 0) {
                printf("%d", i);
                break;
            }
        }
        if (i > 36) printf("Impossible");
    } else {
        long long v = toBase10(y, radix);
        for (i = 2; i <= 36; i++) {
            itoa(y, v, i);
            if (strcmp(x, y) == 0) {
                printf("%d", i);
                break;
            }
        }
        if (i > 36) printf("Impossible");
    }
}

long long toBase10(char* x, int radix) {
    long long sum = 0;
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] >= '0' && x[i] <= '9')
            sum = sum * radix + x[i] - '0';
        else if (x[i] >= 'a' && x[i] <= 'z')
            sum = sum * radix + x[i] - 'a' + 10;
    }
    return sum;
}

void itoa(char* x, long long v, int radix) {
    int len = 0;
    int r;
    char ch, temp;
    while (v > 0) {
        r = v % radix;
        v /= radix;
        if (r >= 0 && r <= 9) {
            ch = r + '0';
        } else if (r >= 10 && r <= 35) {
            ch = r - 10 + 'a';
        }
        x[len++] = ch;
    }
    x[len] = '\0';
    int i = 0, j = len - 1;
    while (i < j) {  //reverse the string
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        i++; j--;
    }
}
