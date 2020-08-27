#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#define NAMESIZE 4
#define MAXN 2000
#include <map>
using namespace std;

int N, K;
int num = 0;
int G[MAXN][MAXN] = {0};
int w[MAXN] = {0};
bool vis[MAXN] = {0};
map<string, int> smp;
map<int, string> imp;
map<string, int> mp;
int ans = 0;

int getVertextID(string s) {
    if (smp.find(s) == smp.end()) {
        smp[s] = num;
        imp[num] = s;
        return num++;
    } else {
        return smp[s];
    }
}

void dfs(int root, int &cnt, int &maxi, int &maxw, int &totw) {
    vis[root] = true;
    cnt++;
    totw += w[root];
    if (w[root] > maxw) {
        maxw = w[root];
        maxi = root;
    }
    for (int i = 0; i < num; i++) {
        if (G[root][i] && !vis[i]) {
            dfs(i, cnt, maxi, maxw, totw);
        }
    }
}

int main() {
    int time, cnt, maxi, maxw, totw;
    string src, des;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int sid, did;
        cin >> src >> des >> time;
        sid = getVertextID(src);
        did = getVertextID(des);
        G[sid][did] = 1;
        w[sid] += time;
        w[did] += time;
    }
    for (int i = 0; i < num; i++) {
        cnt = 0;
        maxw = 0;
        maxi = -1;
        totw = 0;
        if (!vis[i]) {
            dfs(i, cnt, maxi, maxw, totw);
        }
        if (cnt > 2 && totw / 2 > K) {
            mp[imp[maxi]] = cnt;
            ans++;
        }
    }
    cout << ans << endl;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << (it->first) << " " << (it->second) << endl;
    }
}
