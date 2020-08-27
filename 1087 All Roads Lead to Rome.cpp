#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#define MAXN 256
#define INF 99999999
using namespace std;

int n, k;
int mid = 0;
int G[MAXN][MAXN], w[MAXN];
int pre[MAXN], dist[MAXN], diff[MAXN], hap[MAXN], vis[MAXN], nums[MAXN];
map<string, int> strToInt;
map<int, string> intToStr;

int getID(string name) {
    map<string, int>::iterator it = strToInt.find(name);
    if (it != strToInt.end()) {
        return it->second;
    } else {
        strToInt[name] = mid;
        intToStr[mid] = name;
        return mid++;
    }
}

void dijkstra(int src) {
    dist[src] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dist[j] < MIN) {
                u = j;
                MIN = dist[j];
            }
        }
        if (u == -1) {
            printf("ERROR!\n");
            return;
        }
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (dist[u] + G[u][v] < dist[v]) {
                    dist[v] = dist[u] + G[u][v];
                    pre[v] = u;
                    diff[v] = diff[u];
                    hap[v] = hap[u] + w[v];
                    nums[v] = nums[u] + 1;
                } else if (dist[u] + G[u][v] == dist[v]) {
                    if (hap[u] + w[v] > hap[v]) {
                        pre[v] = u;
                        hap[v] = hap[u] + w[v];
                        nums[v] = nums[u] + 1;
                    } else if (hap[u] + w[v] == hap[v] && nums[u] + 1 < nums[v]) {
                        pre[v] = u;
                        nums[v] = nums[u] + 1;
                    }
                    diff[v] += diff[u];
                }
            }
        }
    }
    int des = getID("ROM");
    printf("%d %d %d %d\n", diff[des], dist[des], hap[des], hap[des] / nums[des]);
    string out = "ROM";
    des = pre[des];
    while (des != -1) {
        out = (intToStr.find(des))->second + "->" + out;
        des = pre[des];
    }
    cout << out;
}

int main() {
    fill(G[0], G[0] + MAXN * MAXN, INF);
    fill(w, w + MAXN, 0);
    fill(pre, pre + MAXN, -1);
    fill(dist, dist + MAXN, INF);
    fill(diff, diff + MAXN, 1);
    fill(hap, hap + MAXN, 0);
    fill(vis, vis + MAXN, 0);
    fill(nums, nums + MAXN, 0);
    string place, from, to;
    cin >> n >> k >> place;
    int src = getID(place), happy, cost, fid, tid;
    for (int i = 0; i < n - 1; i++) {
        cin >> place >> happy;
        w[getID(place)] = happy;
    }
    for (int i = 0; i < k; i++) {
        cin >> from >> to >> cost;
        fid = getID(from);
        tid = getID(to);
        G[fid][tid] = cost;
        G[tid][fid] = cost;
    }
    dijkstra(src);
}
