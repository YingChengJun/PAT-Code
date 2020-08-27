#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct Node {
    int id;
    int cnt;
    Node(int i, int c): id(i), cnt(c) {};
    bool operator < (const Node &a) const {
        return cnt != a.cnt ? cnt > a.cnt: id < a.id;
    }
};
int mp[50001] = {0};

int main() {
    int n, m, id;
    scanf("%d %d", &n, &m);
    set<Node> st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (i > 0) {
            printf("%d:", id);
            int cnts = 0;
            for (set<Node>::iterator it = st.begin(); cnts < m && it != st.end(); it++) {
                printf(" %d", it->id);
                cnts++;
            }
            printf("\n");
        }
        set<Node>::iterator it = st.find(Node(id, mp[id]));
        if (it != st.end()) st.erase(it);
        mp[id]++;
        st.insert(Node(id, mp[id]));
    }
}
