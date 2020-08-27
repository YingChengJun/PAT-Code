#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    int m, gap, s;
    string str;
    map<string, bool> mp;
    vector<string> v, ans;
    cin >> m >> gap >> s;
    for (int i = 0; i < m; i++) {
        cin >> str;
        v.push_back(str);
    }
    int i = s - 1;
    int cnt = 0;
    while (i < v.size()) {
        if (cnt == 0 && !mp[v[i]]) {
            ans.push_back(v[i]);
            mp[v[i]] = 1;
            cnt = gap - 1;
        } else if (!mp[v[i]]) {
            cnt--;
        }
        i++;
    }
    if (ans.size() == 0) {
        cout << "Keep going..." << endl;
        return 0;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
