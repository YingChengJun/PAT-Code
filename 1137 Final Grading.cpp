#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int Gp = -1;
    int Gm = -1;
    int Gf = -1;
    string id;
    Node(string s) : id(s) {};
    int getG() const {
        if (Gp < 200 || Gf == -1)
            return -1;
        if (Gf >= Gm)
            return Gf >= 60 ? Gf : -1;
        int g = (int)round((0.4 * Gm + 0.6 * Gf));
        return g >= 60 ? g : -1;
    }
    bool operator < (const Node &node) const {
        int g1 = getG();
        int g2 = node.getG();
        if (g1 == -1 || g2 == -1) {
            return g2 < g1;
        } else if (g1 == g2) {
            return id < node.id;
        } else {
            return g1 > g2;
        }
    }
};

vector<Node> v;
map<string, int> mp;

int getID(string name) {
    map<string, int>::iterator it = mp.find(name);
    if (it != mp.end()) {
        return it->second;
    } else {
        v.push_back(Node(name));
        mp[name] = v.size() - 1;
        return v.size() - 1;
    }
}

int main() {
    int p, n, m, id, score;
    string name;
    cin >> p >> n >> m;
    while (p--) {
        cin >> name >> score;
        id = getID(name);
        v[id].Gp = score;
    }
    while (n--) {
        cin >> name >> score;
        id = getID(name);
        v[id].Gm = score;
    }
    while (m--) {
        cin >> name >> score;
        id = getID(name);
        v[id].Gf = score;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int g = v[i].getG();
        if (g == -1) break;
        cout << v[i].id << " " << v[i].Gp << " " << v[i].Gm<< " " << v[i].Gf << " " << g << endl;
    }
}
