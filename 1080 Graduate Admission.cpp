#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 40000
#define MAXM 100
#define MAXK 5
#define SCORE(x) (((x.Ge) + (x.Gi)) / 2)
using namespace std;

int n, m, k;
struct User {
    int id;
    int Ge;
    int Gi;
    int rank;
    vector<int> post;
};
struct School {
    int remain;
    int MIN = 9999; //minimum grade of all students
    int Ge = 9999; //the Ge of student who has the minimum grade
    set<int> usr;
};

bool cmp(User &a, User b) {
    return SCORE(a) != SCORE(b) ? SCORE(a) > SCORE(b) : a.Ge > b.Ge;
}

int main() {
    int num;
    scanf("%d %d %d", &n, &m, &k);
    vector<User> stu(n);
    vector<School> sch(m);
    for (int i = 0; i < n; i++) stu[i].id = i;
    for (int i = 0; i < m; i++) scanf("%d", &sch[i].remain);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &stu[i].Ge, &stu[i].Gi);
        for (int j = 0; j < k; j++) {
            scanf("%d", &num);
            stu[i].post.push_back(num);
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int post = stu[i].post[j];
            if (sch[post].remain > 0) {
                sch[post].usr.insert(stu[i].id);
                if (SCORE(stu[i]) < sch[post].MIN) {
                    sch[post].MIN = SCORE(stu[i]);
                    sch[post].Ge = stu[i].Ge;
                } else if (SCORE(stu[i]) == sch[post].MIN && stu[i].Ge < sch[post].Ge) {
                    sch[post].Ge = stu[i].Ge;
                }
                sch[post].remain--;
                break;
            } else if (SCORE(stu[i]) == sch[post].MIN && stu[i].Ge == sch[post].Ge) {
                sch[post].usr.insert(stu[i].id);
                sch[post].remain--;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (sch[i].usr.size() > 0) {
            for (auto it = sch[i].usr.begin(); it != sch[i].usr.end(); it++) {
                if (it != sch[i].usr.begin()) printf(" ");
                printf("%d", *it);
            }
        }
        printf("\n");
    }
}
