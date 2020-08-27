#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n;
string putstd(string s, int& e) {
    string res;
    while (s.size() > 0 && s[0] == '0') {  //00001234.001234
        s.erase(s.begin());
    }
    if (s.size() == 0) {  //0
        e = 0;
    } else if (s[0] == '.') { //0.001234
        s.erase(s.begin()); //remove "."
        while (s.size() > 0  && s[0] == '0') {
            s.erase(s.begin());
            e--;
        }
        if (s.size() == 0) e = 0; //case 0.000
    } else {  //12345.1234 or 12345678
        int k = s.find(".");
        if (k == -1) e = s.size();
        else {
            e = k;
            s.erase(s.begin() + k);
        }
    }
    for (int i = 0; i < s.size() && i < n; i++) res += s[i];
    while (res.size() < n) res += "0";
    return res;
}

int main() {
    int e1 = 0, e2 = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;
    s1 = putstd(s1, e1);
    s2 = putstd(s2, e2);
    if (s1 == s2 && e1 == e2) {
        cout << "YES 0." << s1 << "*10^" << e1;
    } else {
        cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2;
    }
    return 0;
}
