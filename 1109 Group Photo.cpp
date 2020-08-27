#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 10000
#define MAXL 10
using namespace std;

int n, k;
struct USER {
    char name[MAXL];
    int height;
    USER(char* _name, int _height): height(_height) {
        strcpy(name, _name);
    }
    USER(const USER &u) {
        height = u.height;
        strcpy(name, u.name);
    }
};
vector<USER> user;

bool cmp(USER a, USER b) {
    if (a.height == b.height) {
        return strcmp(a.name, b.name) > 0;
    } else {
        return a.height < b.height;
    }
}

void solve(int left, int right) {
    bool flag = 0;
    vector<USER> ans;
    for (int i = right; i >= left; i--) {
        if (flag) {
            ans.insert(ans.begin(), user[i]);
        } else {
            ans.push_back(user[i]);
        }
        flag = !flag;
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) {
            printf("%s", ans[i].name);
        } else {
            printf(" %s", ans[i].name);
        }
    }
    printf("\n");
}

int main() {
    int height, each;
    char name[MAXL];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name, &height);
        user.push_back(USER(name, height));
    }
    sort(user.begin(), user.end(), cmp);
    each = n / k;
    for (int i = k - 1; i >= 0; i--) {
        if (i == k - 1) {
            solve(i * each, n - 1);
        } else {
            solve(i * each, (i + 1) * each - 1);
        }
    }
}
