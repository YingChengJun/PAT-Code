#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;

int getID(char* name) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    int n, k;
    int courseID, studentNum;
    char name[5];
    vector<int> choose[M];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &courseID, &studentNum);
        for (int j = 0; j < studentNum; j++) {
            scanf("%s", name);
            choose[getID(name)].push_back(courseID);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getID(name);
        sort(choose[id].begin(), choose[id].end());
        printf("%s %d", name, choose[id].size());
        for (int j = 0; j < choose[id].size(); j++) {
            printf(" %d", choose[id][j]);
        }
        printf("\n");
    }
}
