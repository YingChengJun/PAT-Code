#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#define MAXN 100
using namespace std;

int N, M;
struct Node {
    int level = 0;
    vector<int> child;
} node[MAXN];
map<int, int> ans;

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int root = q.front();
        q.pop();
        if (ans.find(node[root].level) == ans.end()) {
            ans[node[root].level] = 0;
        }
        if (node[root].child.size() == 0) {
            ans[node[root].level]++;
        }
        for (int i = 0; i < node[root].child.size(); i++) {
            node[node[root].child[i]].level = node[root].level + 1;
            q.push(node[root].child[i]);
        }
    }
}

int main() {
    int id, cnum, cid;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &id, &cnum);
        for (int j = 0; j < cnum; j++) {
            scanf("%d", &cid);
            node[id].child.push_back(cid);
        }
    }
    bfs();
    for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++) {
        if (it != ans.begin()) printf(" %d", it->second);
        else printf("%d", it->second);
    }
}
