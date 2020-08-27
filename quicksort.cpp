#include <cstdio>
#include <vector>
#include <algorithm>
#define GAP 3
using namespace std;

void iSort(int a[], int left, int right) {
    int j, temp;
    for (int i = left + 1; i <= right; i++) {
        j = i;
        temp = a[i];
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

int getPivot(int a[], int left, int right) {
    int mid = (left + right) / 2;
    if (a[left] > a[mid]) {
        swap(a[left], a[mid]);
    }
    if (a[left] > a[right]) {
        swap(a[left], a[right]);
    }
    if (a[mid] > a[right]) {
        swap(a[mid], a[right]);
    }
    swap(a[mid], a[right - 1]);
    return right - 1;
}


void qSort(int a[], int left, int right) {
    if (left > right)
        return;
    if (right - left < GAP) {
        iSort(a, left, right);
        return;
    }
    int pivot = getPivot(a, left, right);
    int i = left, j = right - 1;
    while (1) {
        while (a[++i] < a[pivot]);
        while (a[--j] > a[pivot]);
        if (i < j) {
            swap(a[i], a[j]);
        } else {
            break;
        }
    }
    swap(a[i], a[right - 1]);  //一定要找第一个大于a[pivot]的数进行交换
    qSort(a, left, i - 1);
    qSort(a, i + 1, right);
}


int main() {
    int a[12] = {6, 1, 14, 14, 4, 16, 8, 4, 5, 3, 17, 21};
    qSort(a, 0, 12);
    for (int i = 0; i < 12; i++) {
        printf("%d ", a[i]);
    }
}
