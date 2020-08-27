#include <iostream>
#include <string>
using namespace std;

bool vis[256] = {0};

int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    for (int i = 0; i < len2; i++) {
        if (s2[i] >= 'a' && s2[i] <= 'z') s2[i] = s2[i] - 'a' + 'A';
        vis[s2[i]] = true;
    }
    for (int i = 0; i < len1; i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') s1[i] = s1[i] - 'a' + 'A';
        if (!vis[s1[i]]) {
            cout << s1[i];
            vis[s1[i]] = true;
        }
    }
}
