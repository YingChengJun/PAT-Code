#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10001
#define MAXK 6
#define INF -2
using namespace std;

int n, k, m;
int full[MAXK];
struct User {
    int id;
    int grade[MAXK];
    int rank;
    User() {
        fill(grade, grade + MAXK, INF);
    }
    User(const User &a) {
        id = a.id;
        for (int i = 0; i < MAXK; i++) {
            grade[i] = a.grade[i];
        }
    }
    int getScore() {
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (grade[i] > 0) ans += grade[i];
        }
        return ans;
    }
    int getFullCount() {
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (grade[i] == full[i]) ans++;
        }
        return ans;
    }
    bool isValid() {
        for (int i = 1; i <= k; i++) {
            if (grade[i] >= 0) return true;
        }
        return false;
    }
} stu[MAXN], valid[MAXN];

bool cmp(User &a, User &b) {
    if (a.getScore() != b.getScore()) {
        return a.getScore() > b.getScore();
    } else {
        if (a.getFullCount() != b.getFullCount()) {
            return a.getFullCount() > b.getFullCount();
        }
        return a.id < b.id;
    }
}

int main() {
    int id, index, score;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i < MAXN; i++) {
        stu[i].id = i;
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &full[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &id, &index, &score);
        stu[id].grade[index] = max(score, stu[id].grade[index]);
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (stu[i].isValid()) {
            valid[num++] = stu[i];
        }
    }
    sort(valid, valid + num, cmp);
    int rank = 1;
    for (int i = 0; i < num; i++) {
        if (i > 0 && valid[i - 1].getScore() != valid[i].getScore()) {
            rank = i + 1;
        }
        printf("%d %05d %d", rank, valid[i].id, valid[i].getScore());
        for (int j = 1; j <= k; j++) {
            if (valid[i].grade[j] == INF) {
                printf(" -");
            } else {
                printf(" %d", valid[i].grade[j] >= 0 ? valid[i].grade[j] : 0);
            }
        }
        printf("\n");
    }
}
