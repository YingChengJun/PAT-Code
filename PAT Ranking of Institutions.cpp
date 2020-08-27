#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Node {
    int scoreA = 0;
    int scoreB = 0;
    int scoreT = 0;
    int ns = 0;
    string name;
    Node(string s): name(s) {};
    int getScore() const {
        return scoreA + scoreB / 1.5 + scoreT * 1.5;
    }
    bool operator < (const Node &node) const {
        int sA = getScore(), sB = node.getScore();
        if (sA == sB) {
            if (ns == node.ns) {
                return name < node.name;
            }
            return ns < node.ns;
        }
        return sA > sB;
    }
};
vector<Node> v;
map<string, int> mp;

int getID(string s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    map<string, int>::iterator it = mp.find(s);
    if (it == mp.end()) {
        v.push_back(Node(s));
        mp[s] = v.size() - 1;
        return v.size() - 1;
    } else {
        return it->second;
    }
}

int main() {
    int n, score;
    string id, sch;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> score >> sch;
        int sid = getID(sch);
        v[sid].ns++;
        switch(id[0]) {
            case 'A': v[sid].scoreA += score; break;
            case 'B': v[sid].scoreB += score; break;
            case 'T': v[sid].scoreT += score; break;
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    int rank = 1;
    for (int i = 0; i < v.size();) {
        printf("%d %s %d %d\n", rank, v[i].name.c_str(), v[i].getScore(), v[i].ns);
        i++;
        while (i < v.size() && v[i].getScore() == v[i-1].getScore()) {
            printf("%d %s %d %d\n", rank, v[i].name.c_str(), v[i].getScore(), v[i].ns);
            i++;
        }
        rank = i + 1;
    }
}
