#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 20
#define MAXM 10
#define MAXK 1001
using namespace std;

int N, M, K, Q;
struct Person {
    int id;
    int pt;
    int ppt;
    int finish = -1;
    int start = -1;
} customer[MAXK];
queue<int> server[MAXN];
queue<int> wq;

int main() {
    int i, j, time = 0;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for (i = 1; i <= K; i++) {
        scanf("%d", &customer[i].pt);
        customer[i].id = i;
        customer[i].ppt = customer[i].pt;
        wq.push(i);
    }
    for (i = 0; i <= 540; i++) {
        int u = -1, MIN = 999999;
        for (j = 0; j < N; j++) {
            if (server[j].size() < M && server[j].size() < MIN) {
                MIN = server[j].size();
                u = j;
            }
            if (server[j].size() > 0) {
                int wid = server[j].front();
                if (customer[wid].pt == customer[wid].ppt) {
                    customer[wid].start = i;
                }
                //printf("Server %d now serve person %d\n", j, wid);
                if (--customer[wid].pt == 0) {
                    //printf("Person %d at Server %d Finished at time %d\n", wid, j, i);
                    server[j].pop();
                }
            }
        }
        while (u != -1 && wq.size() > 0) {
            //printf("Push waiting queue %d to server %d\n", wq.front(), u);
            server[u].push(wq.front());
            wq.pop();
            u = -1;
            MIN = 999999;
            for (j = 0; j < N; j++) {
                if (server[j].size() < M && server[j].size() < MIN) {
                    MIN = server[j].size();
                    u = j;
                }
            }
        }
    }
    int qid, hh, ss, finish;
    for (i = 1; i <= Q; i++) {
        scanf("%d", &qid);
        if (customer[qid].start == -1) {
            printf("Sorry\n");
        } else {
            finish = customer[qid].start + customer[qid].ppt - 1;
            hh = 8 + finish / 60;
            ss = finish % 60;
            printf("%02d:%02d\n", hh, ss);
        }
        //printf("Customer %d: %d\n", i, customer[i].finish);
    }
}
