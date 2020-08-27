#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
    int id;
    char name[16];
    int grade;
};

bool cmp1(struct Node &a, struct Node &b) {
    return a.id < b.id;
}

bool cmp2(struct Node &a, struct Node &b) {
    return strcmp(a.name, b.name) == 0 ? a.id < b.id : strcmp(a.name, b.name) < 0;
}

bool cmp3(struct Node &a, struct Node &b) {
    return a.grade == b.grade ? a.id < b.id : a.grade < b.grade;
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &v[i].id, v[i].name ,&v[i].grade);
    }
    if (c == 1) sort(v.begin(), v.end(), cmp1);
    else if (c == 2) sort(v.begin(), v.end(), cmp2);
    else if (c == 3) sort(v.begin(), v.end(), cmp3);
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", v[i].id, v[i].name ,v[i].grade);
    }
}
