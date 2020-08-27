#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int i;
    int number[20] = {29, 23, 20, 22, 17, 15, 26, 51, 19, 12, 35, 40};
    for(i = 0; i < 12; i++)
        printf("%d ", number[i]);
    printf("\n");
    make_heap(&number[0], &number[12], cmp);
    for(i = 0; i < 12; i++)
        printf("%d ", number[i]);
    printf("\n");
    number[12] = 8;
    push_heap(&number[0], &number[13], cmp);
    for(i = 0; i < 13; i++)
        printf("%d ", number[i]);
    printf("\n");
    pop_heap(&number[0], &number[13], cmp);  //delete min
    for(i = 0; i < 12; i++)
        printf("%d ", number[i]);
    printf("\n");
    sort_heap(&number[0], &number[12], cmp);
    for(i = 0; i < 12; i++)
        printf("%d ", number[i]);
}
