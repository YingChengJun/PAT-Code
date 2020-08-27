#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    vector<int> vi;

    for (int i = 1; i <= 5; i++)
        vi.push_back(i);

    vector<int>::iterator it = vi.begin();
    for (int i = 0; i < 5; i++)
        printf("%d ", *(it + i));
    printf("\n");

    vi.insert(vi.begin() + 2, -1);
    for (it = vi.begin(); it != vi.end(); it++)
        printf("%d ", *it);
    printf("\n");

    vi.erase(vi.begin() + 2);
    for (it = vi.begin(); it != vi.end(); it++)
        printf("%d ", *it);
    printf("\n");

    vi.erase(vi.begin() + 3, vi.begin() + 4); //erase v[3] only because of [3,4)
    for (it = vi.begin(); it != vi.end(); it++)
        printf("%d ", *it);


    return 0;
}
