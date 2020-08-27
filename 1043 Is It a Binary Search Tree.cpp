#include <cstdio>
#include <vector>
using namespace std;

int N;
bool isMirror = false;
vector<int> pre;
vector<int> post;

bool solve(int start, int close) {
    int i, j;
    bool checkLeft, checkRight;
    if (start > close) return true; //a null tree
    if (start == close) { //one element must be a BST or a mirror BST
        //because the post order traversal is left - right - root
        //thus the leftest element must be put into vector first
        post.push_back(pre[start]);
        return true;
    }
    if (isMirror) {
        for (i = start + 1; i <= close; i++) {
            if (pre[i] < pre[start])
                break;
        }
        for (j = i; j <= close; j++) {
            if (pre[j] >= pre[start])
                return false;
        }
        checkLeft = solve(start + 1, i - 1);
        checkRight = solve(i, close);
        if (checkLeft && checkRight) {
            post.push_back(pre[start]);
            return true;
        } else
            return false;
        return false;
    } else {
        //case of a simple BST
        for (i = start + 1; i <= close; i++) {  //find the first element at right child
            if (pre[i] >= pre[start])
                break;
        }
        for (j = i; j <= close; j++) {  //check all the last elements is no less than root
            if (pre[j] < pre[start])
                return false;
        }
        checkLeft = solve(start + 1, i - 1);  //recursively traversal left child
        checkRight = solve(i, close);  //recursively traversal right child
        if (checkLeft && checkRight) {
            post.push_back(pre[start]);  //that is ok and finally push the root
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        pre.push_back(num);
    }
    //Determine whether it is a mirrored BST based on the comparison of the two elements
    //When it is a normal BST, because of root-left-right, pre[1] < pre[0]
    //When it is a mirror BST, pre[1] >= pre[0]
    //We assume that if pre[1] == pre[0], BST will divide pre[1] to the right child
    if (N > 1 && pre[1] >= pre[0])
        isMirror = true;
    bool ans = solve(0, N - 1);
    if (ans) {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++) {
            if (i > 0)
                printf(" %d", post[i]);
            else
                printf("%d", post[i]);
        }
    } else {
        printf("NO\n");
    }
}
