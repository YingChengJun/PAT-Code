#include <iostream>
#include <string>
using namespace std;

int mp1[128] = {0};
int mp2[128] = {0};
int mis = 0;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        mp1[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        mp2[s2[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (mp2[i] > mp1[i]) {
            mis += (mp2[i] - mp1[i]);
        }
    }
    if (mis) {
        printf("No %d", mis);
    } else {
        printf("Yes %d", s1.length() - s2.length());
    }
}
