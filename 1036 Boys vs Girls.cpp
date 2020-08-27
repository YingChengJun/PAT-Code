#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int grade;
    char gender;
    char name[16];
    char id[16];
};
vector<Node> v;

int main() {
    int n;
    int maxi = -1, mini = -1, maxg = -1, ming = 101;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Node node;
        scanf("%s %c %s %d", &node.name, &node.gender, &node.id, &node.grade);
        v.push_back(node);
        if (node.gender == 'M' && node.grade < ming) {
            mini = i;
            ming = node.grade;
        }
        if (node.gender == 'F' && node.grade > maxg) {
            maxi = i;
            maxg = node.grade;
        }
    }
    if (maxi == -1) printf("Absent\n");
    else printf("%s %s\n", v[maxi].name, v[maxi].id);
    if (mini == -1) printf("Absent\n");
    else printf("%s %s\n", v[mini].name, v[mini].id);
    if (maxi == -1 || mini == -1) printf("NA");
    else printf("%d", maxg - ming);
}
