#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int N;
double unitPrice, rate;
double sum = 0;
struct Node {
    int val = 0;  //price
    vector<int> child;
};
vector<Node> tree;
map<int, bool> isChild;

int getRoot() {
    for (int i = 0; i < N; i++) {
        if (isChild[i] == false) return i;
    }
    return -1;
}

void dfs(int root, int depth) {
    if (tree[root].child.size() == 0) {
        sum = sum + tree[root].val * pow(1 + rate/100, depth);
    } else {
        for (int i = 0; i < tree[root].child.size(); i++) {
            dfs(tree[root].child[i], depth + 1);
        }
    }
}

int main() {
    int type, val, child;
    scanf("%d %lf %lf", &N, &unitPrice, &rate);
    for (int i = 0; i < N; i++) {
        Node node;
        scanf("%d", &type);
        if (type == 0) {
            scanf("%d", &val);
            node.val = val;
        } else {
            for (int j = 0; j < type; j++) {
                scanf("%d", &child);
                node.child.push_back(child);
                isChild[child] = true;
            }
        }
        tree.push_back(node);
    }
    int root = getRoot();
    dfs(root, 0);
    printf("%.1f", sum * unitPrice);
}
