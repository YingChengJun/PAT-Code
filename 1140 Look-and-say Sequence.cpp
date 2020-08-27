#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string itos(int v) {
    stringstream ss;
    string ans;
    ss << v;
    ss >> ans;
    return ans;
}

int main() {
    int n, i, j;
    string s;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string temp;
        for (i = 0; i < s.size(); i = j) {
            for (j = i; j < s.size() && s[j] == s[i]; j++);
            temp += s[i] + itos(j - i);  //use temp = temp + s[i] + itos(j-i) will cause time exceed error!
        }
        s = temp;
    }
    cout << s;
}
