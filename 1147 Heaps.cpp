#include <cstdio>
using namespace std;

const int MAXN = 1024;
int m, n;
int heap[MAXN];

int getLeftChild(int root) {
    return (2 * root <= n) ? (2 * root) : -1;
}
int getRightChild(int root) {
    return (2 * root + 1 <= n) ? (2 * root + 1) : -1;
}

bool checkMaxHeap(int root) {
    if (root == -1) return true;
    int left = getLeftChild(root);
    int right = getRightChild(root);
    if (left != -1 && heap [left] > heap[root]) return false;
    if (right != -1 && heap[right] > heap[root]) return false;
    return checkMaxHeap(left) && checkMaxHeap(right);
}

bool checkMinHeap(int root) {
    if (root == -1) return true;
    int left = getLeftChild(root);
    int right = getRightChild(root);
    if (left != -1 && heap[left] < heap[root]) return false;
    if (right != -1 && heap[right] < heap[root]) return false;
    return checkMinHeap(left) && checkMinHeap(right);
}

void postOrderTraversal(int root) {
    if (root == -1) return;
    postOrderTraversal(getLeftChild(root));
    postOrderTraversal(getRightChild(root));
    if (root != 1) printf("%d ", heap[root]);
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &heap[j]);
        }
        if (checkMaxHeap(1)) {
            printf("Max Heap\n");
        } else if (checkMinHeap(1)) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        postOrderTraversal(1);
        printf("%d", heap[1]);
        printf("\n");
    }
}
