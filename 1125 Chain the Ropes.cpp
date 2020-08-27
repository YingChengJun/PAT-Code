#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, num;
    double a, b;
    priority_queue<double, vector<double>, greater<double> > q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        q.push(num);
    }
    while (q.size() > 1) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push((a + b) / 2);
    }
    printf("%d", (int)q.top());
}
