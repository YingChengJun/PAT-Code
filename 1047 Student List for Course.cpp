#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_COURSE = 2501;

bool cmp(string a, string b) {
    return a.compare(b) < 0;
}

int main() {
    int n, k;
    int i, j, num;
    char name[5];
    vector<string> course[MAX_COURSE];
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        int courseNum;
        scanf("%s %d", name, &num);
        for (j = 0; j < num; j++) {
            scanf("%d", &courseNum);
            course[courseNum].push_back(name);
        }
    }
    for (i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (j = 0; j < course[i].size(); j++)
            printf("%s\n", course[i][j].c_str());
    }
}
