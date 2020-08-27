#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 10000
using namespace std;

struct Node {
    int x;
    int y;
    Node(int _x, int _y): x(_x), y(_y) {};
};
int n, m;
vector<int> G[MAXN];
map<int, bool> arr;

int atoi(char* s) {
    int i = (s[0] == '-') ? 1 : 0;
    return ((s[i] - '0') * 1000 + (s[i + 1] - '0') * 100 + (s[i + 2] - '0') * 10 + (s[i + 3] - '0'));
}

bool cmp(Node x, Node y) {
    return x.x != y.x ? x.x < y.x : x.y < y.y;
}

int main() {
    int a, b, query;
    int A, B;
    char aa[6], bb[6];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %s", aa, bb);
        a = atoi(aa);
        b = atoi(bb);
        if (strlen(aa) == strlen(bb)) {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        arr[a * 10000 + b] = arr[b * 10000 + a] = true;
    }
    scanf("%d", &query);
    while (query--) {
        vector<Node> ans;
        scanf("%d %d", &a, &b);
        A = abs(a);
        B = abs(b);
        for (int i = 0; i < G[A].size(); i++) {
            for (int j = 0; j < G[B].size(); j++) {
                int AA = G[A][i];
                int BB = G[B][j];
                if (AA == BB || AA == B || BB == A)
                    continue;
                if (arr[AA * 10000 + BB])
                    ans.push_back(Node(AA, BB));
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for(int j = 0; j < ans.size(); j++) {
            printf("%04d %04d\n", ans[j].x, ans[j].y);
        }
    }
}
