#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    string t;
    int val;
    Node() {};
    Node(string s, int v): t(s), val(v) {};
};

bool cmp(const Node &a, const Node &b) {
    return a.val == b.val ? a.t < b.t : a.val > b.val;
}

int main() {
    int n, score, query, type;
    string s;
    cin >> n >> query;
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].t >> v[i].val;
    }
    for (int i = 1; i <= query; i++) {
        cin >> type >> s;
        printf("Case %d: %d %s\n", i, type, s.c_str());
        vector<Node> ans;
        if (type == 1) {
            for (int j = 0; j < n; j++) {
                if (v[j].t[0] == s[0]) ans.push_back(Node(v[j].t, v[j].val));
            }
        } else if (type == 2) {
            int num = 0, tot = 0;
            for (int j = 0; j < n; j++) {
                if (v[j].t.substr(1, 3) == s) {
                    num++;
                    tot += v[j].val;
                }
            }
            if (num != 0) printf("%d %d\n", num, tot);
            else printf("NA\n");
        } else if (type == 3) {
            unordered_map<string, int> mp;
            for (int j = 0; j < n; j++) {
                if (v[j].t.substr(4, 6) == s) {
                    mp[v[j].t.substr(1, 3)]++;
                }
            }
            for (auto it = mp.begin(); it != mp.end(); it++) {
                ans.push_back(Node(it->first, it->second));
            }
        }
        if (type == 1 || type == 3) {
            if (ans.size() == 0) {
                printf("NA\n");
            } else {
                sort(ans.begin(), ans.end(), cmp);
                for (int j = 0; j < ans.size(); j++) {
                    printf("%s %d\n", ans[j].t.c_str(), ans[j].val);
                }
            }
        }
    }
}
