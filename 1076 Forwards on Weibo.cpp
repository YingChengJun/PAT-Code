#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 1001
using namespace std;

int N, L;
struct Node {
    int id;
    int layer = 0;
    Node(int _id): id(_id) {};
};
vector<Node> G[MAXN];

int bfs(int root) {
    int ans = 0;
    bool inq[MAXN] = {0};
    queue<Node> q;
    q.push(Node(root));
    inq[root] = true;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i = 0; i < G[top.id].size(); i++) {
            Node next = G[top.id][i];
            next.layer = top.layer + 1;
            if (!inq[next.id] && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int nums, follow, r, query;
    scanf("%d %d", &N, &L);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nums);
        for (int j = 1; j <= nums; j++) {
            scanf("%d", &follow);
            G[follow].push_back(Node(i));
        }
    }
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        scanf("%d", &query);
        int ans = bfs(query);
        printf("%d\n", ans);
    }
}
