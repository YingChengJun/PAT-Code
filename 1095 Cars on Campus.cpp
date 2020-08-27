#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#define MAXR 10000
#define Time(hh, mm, ss) (((hh) * 3600) + ((mm) * 60) + (ss))
using namespace std;

struct Record {
    char name[8];
    char status[4];
    int time;
} rec[MAXR], valid[MAXR];
map<string, int> parkTime;
int num = 0;
int maxTime = 0;

bool cmp(const Record &a, const Record &b) {
    int d = strcmp(a.name, b.name);
    return d != 0 ? d < 0 : a.time < b.time;
}

bool cmp2(const Record &a, const Record &b) {
    return a.time < b.time;
}

int main() {
    int n, k, hh, mm, ss;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", rec[i].name, &hh, &mm, &ss, rec[i].status);
        rec[i].time = Time(hh, mm, ss);
    }
    sort(rec, rec + n, cmp);
    for (int i = 0; i < n - 1; i++) {
        if (!strcmp(rec[i].name, rec[i + 1].name) && !strcmp(rec[i].status, "in")
                && !strcmp(rec[i + 1].status, "out")) {
            valid[num++] = rec[i];
            valid[num++] = rec[i + 1];
            parkTime[rec[i].name] += rec[i + 1].time - rec[i].time;
            maxTime = max(maxTime, parkTime[rec[i].name]);
            i++;
        }
    }
    sort(valid, valid + num, cmp2);
    int now = 0, ans = 0;
    for (int j = 0; j < k; j++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = Time(hh, mm, ss);
        while (now < num && valid[now].time <= time) {
            if (!strcmp(valid[now].status, "in")) ans++;
            else ans--;
            now++;
        }
        printf("%d\n", ans);
    }
    for (auto it = parkTime.begin(); it != parkTime.end(); it++) {
        if (it->second == maxTime) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
}
