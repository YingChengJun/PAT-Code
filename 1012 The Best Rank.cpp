#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
struct Stud {
    int id;
    int c;
    int m;
    int e;
    int a;
    int r;
};
int cScore[101] = {0}, cRank[101] = {0};
int mScore[101] = {0}, mRank[101] = {0};
int eScore[101] = {0}, eRank[101] = {0};
int aScore[101] = {0}, aRank[101] = {0};
map<int, Stud> stu;

void makeRank(int* score, int* rank) {
    int r = 1;
    for (int i = 100; i >= 0; i--) {
        if (score[i] == 0)
            continue;
        rank[i] = r;
        r += score[i];
    }
}

int main() {
    int sid;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int id, c, m, e, a;
        Stud s;
        scanf("%d %d %d %d", &s.id, &s.c, &s.m, &s.e);
        s.a = (s.c + s.m + s.e) / 3;
        cScore[s.c]++;
        mScore[s.m]++;
        eScore[s.e]++;
        aScore[s.a]++;
        stu[s.id] = s;
    }
    makeRank(cScore, cRank);
    makeRank(mScore, mRank);
    makeRank(eScore, eRank);
    makeRank(aScore, aRank);
    for (int i = 0; i < M; i++) {
        scanf("%d", &sid);
        map<int, Stud>::iterator it = stu.find(sid);
        if (it == stu.end()) {
            printf("N/A\n");
        } else {
            int cr = cRank[(it->second).c];
            int mr = mRank[(it->second).m];
            int er = eRank[(it->second).e];
            int ar = aRank[(it->second).a];
            if (ar <= mr && ar <= er && ar <= cr) {
                printf("%d A\n", ar);
            } else if (cr <= er && cr <= mr && cr < ar) {
                printf("%d C\n", cr);
            } else if (mr <= er && mr < ar && mr < cr) {
                printf("%d M\n", mr);
            } else if (er < ar && er < cr && er < mr) {
                printf("%d E\n", er);
            }

        }
    }

}
