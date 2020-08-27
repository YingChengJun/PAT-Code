#include <cstdio>
#include <vector>
#define MAXN 10000
using namespace std;

vector<int> G[MAXN]; //G[v] means the set of edges adjacent to the node v
vector<int> edges;

int main() {
    int n, m;
    int src, des;
    scanf("%d %d", &n, &m);
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &src, &des);
        G[src].push_back(i);
        G[des].push_back(i);
    }
    int query, nums, vertex;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        fill(edges.begin(), edges.end(), 0);
        scanf("%d", &nums);
        for (int j = 0; j < nums; j++) {
            scanf("%d", &vertex);
            for (int k = 0; k < G[vertex].size(); k++) {
                edges[G[vertex][k]] = 1;
            }
        }
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (!edges[j]) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag? "Yes": "No");
    }
}

