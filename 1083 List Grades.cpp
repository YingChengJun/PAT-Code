#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct User {
    string name;
    string id;
    int grade;
    bool operator < (const User &u) const {
        return grade > u.grade;
    }
    User(string a, string b, int c): name(a), id(b), grade(c) {};
};
vector<User> v, w;

int main() {
    int n, grade, up, down;
    cin >> n;
    string name, id;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> grade;
        v.push_back(User(name, id, grade));
    }
    cin >> down >> up;
    for (int i = 0; i < n; i++) {
        if (v[i].grade >= down && v[i].grade <= up) {
            w.push_back(v[i]);
        }
    }
    sort(w.begin(), w.end());
    if (w.size() == 0) {
        cout << "NONE";
    } else {
        for (int i = 0; i < w.size(); i++) {
            cout << w[i].name << " " << w[i].id;
            if (i != w.size() - 1) cout << endl;
        }
    }
}
