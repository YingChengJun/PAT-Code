#include <cstdio>
#include <vector>
using namespace std;

bool ans = true;
vector<int> pre, post, in;

void makeTree(int preL, int preR, int posL, int posR) {
    if (preL > preR) {
        ans = false;
        return;
    }
    if (preL == preR) {
        in.push_back(pre[preL]);
        return;
    }
    int i;
    for (i = posL; i <= posR; i++) {
        if (post[i] == pre[preL + 1])
            break;
    }
    int leftNum = i - posL;
    makeTree(preL + 1, preL + 1 + leftNum, posL, i);
    in.push_back(pre[preL]);
    makeTree(preL + leftNum + 2, preR, i + 1, posR - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    makeTree(0, n - 1, 0, n - 1);
    printf("%s\n", ans ? "Yes" : "No");
    for (int i = 0; i < n; i++) {
        if(i == 0) printf("%d", in[i]);
        else printf(" %d", in[i]);
    }
}
