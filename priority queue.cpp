#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> q1;
    priority_queue<int, vector<int>, less<int> > q2;
    priority_queue<int, vector<int>, greater<int> > q3;
    q1.push(3);
    q1.push(4);
    q1.push(1);

    q2.push(3);
    q2.push(4);
    q2.push(1);

    q3.push(3);
    q3.push(4);
    q3.push(1);

    printf("q1.top() = %d\n", q1.top());  //4
    printf("q2.top() = %d\n", q2.top());  //4
    printf("q3.top() = %d\n", q3.top());  //1
}
