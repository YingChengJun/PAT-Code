#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


bool mp[257] = {0};

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.size(); i++) {
        mp[s2[i]] = true;
    }
    for (int i = 0; i < s1.size(); i++) {
        if (!mp[s1[i]]) {
            printf("%c", s1[i]);
        }
    }
}
