#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
    int k, i, j, len, pos = 0;
    int mp[128] = {0};
    char str[1024];
    scanf("%d%*c%s", &k, str);
    i = 0;
    len = strlen(str);
    while (i < len) {
        j = i + 1;
        while (j < len && str[j] == str[i]) {
            j++;
        }
        if ((j - i) % k != 0) {
            mp[str[i]] = 1;
        }
        i = j;
    }
    for (i = 0; i < len; i++) {
        if (mp[str[i]] == 0) {
            printf("%c", str[i]);
            mp[str[i]] = -1;
        }
    }
    printf("\n");
    i = 0;
    while (i < len) {
        printf("%c", str[i]);
        if (mp[str[i]] == -1) {
            i += k;
        } else {
            i++;
        }
    }
}
