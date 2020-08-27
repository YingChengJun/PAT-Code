#include <iostream>
#include <queue>
using namespace std;

struct mouse {
    int r;
    int w;
} mouse[1000];

int main() {
    int np, ng, order, temp;
    queue<int> q;
    cin >> np >> ng;
    for (int i = 0; i < np; i++)
        cin >> mouse[i].w;
    for (int i = 0; i < np; i++) {
        cin >> order;
        q.push(order);
    }
    temp = np;
    while (q.size() > 1) {
        int lastg = temp % ng;
        int groups = (lastg == 0) ? (temp / ng) : (temp / ng + 1);
        for (int i = 0; i < groups; i++) {
            int k = q.front(); //the number of the mouse with maximum weight
            for (int j = 0; j < ng; j++) {
                if (i * ng + j >= temp) break;
                int front = q.front();
                if (mouse[front].w > mouse[k].w) k = front;
                //when in this turn we have g groups
                //it implies there are g mouses can go into the next turn
                //all the other mouses are ranked with g+1
                mouse[front].r = groups + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = groups;  //in the next turn the number of mouses
    }
    mouse[q.front()].r = 1; //the last one will be the 1st
    for (int i = 0; i < np; i++) {
        cout << mouse[i].r;
        if (i < np - 1) cout << " ";
    }

}
