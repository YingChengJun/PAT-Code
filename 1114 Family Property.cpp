#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#define MAXN 10000
using namespace std;

int S[MAXN], est[MAXN] = {0}, area[MAXN] = {0};
bool valid[MAXN] = {0};
struct Node {
    int id;
    int num = 0;
    int estSum = 0;
    int areaSum = 0;
    Node(int _id): id(_id) {};
};
map<int, int> mp;

int Find(int x) {
    if (S[x] == x) {
        return x;
    } else {
        return S[x] = Find(S[x]);
    }
}

void Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx < fy) {
        S[fy] = fx;
    } else if (fx > fy) {
        S[fx] = fy;
    }
}

bool cmp(Node a, Node b) {
    double a1 = 1.0 * a.areaSum / a.num;
    double a2 = 1.0 * b.areaSum / b.num;
    if (a1 == a2) {
        return a.id < b.id;
    } else {
        return a1 > a2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < MAXN; i++) S[i] = i;
    for (int i = 0; i < n; i++) {
        int id, father, mother, k, child;
        scanf("%d %d %d %d", &id, &father, &mother, &k);
        if (father != -1) {
            Union(id, father);
            valid[father] = true;
        }
        if (mother != -1) {
            Union(id, mother);
            valid[mother] = true;
        }
        valid[id] = true;
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            Union(id, child);
            valid[child] = true;
        }
        scanf("%d %d", &est[id], &area[id]);
    }
    vector<Node> ans;
    map<int, int>::iterator it;
    for (int i = 0; i < MAXN; i++) {
        if (valid[i]) {
            int index;
            int root = Find(i);
            it = mp.find(root);
            if (it == mp.end()) {
                ans.push_back(Node(root));
                index = ans.size() - 1;
                mp[root] = index;
            } else {
                index = it->second;
            }
            ans[index].estSum += est[i];
            ans[index].areaSum += area[i];
            ans[index].num++;
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%04d %d %.3f %.3f", ans[i].id, ans[i].num, 1.0 * ans[i].estSum / ans[i].num, 1.0 * ans[i].areaSum / ans[i].num);
        if (i != ans.size() - 1) printf("\n");
    }
}

