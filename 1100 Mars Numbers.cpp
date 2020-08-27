#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                        "jly", "aug", "sep", "oct", "nov", "dec"
                       };
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo",
                       "syy", "lok", "mer", "jou"
                      };
map<string, int> marToEarth;
string earthToMar[170];

void init() {
    for (int i = 0; i < 13; i++) {
        marToEarth[unitDigit[i]] = i;
        marToEarth[tenDigit[i]] = i * 13;
        earthToMar[i] = unitDigit[i];
        earthToMar[13 * i] = tenDigit[i];
    }
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j++) {
            string str = tenDigit[i] + " " + unitDigit[j];
            earthToMar[i * 13 + j] = str;
            marToEarth[str] = i * 13 + j;
        }
    }
}

int main() {
    int n;
    init();
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') {
            int num = 0;
            for (int i = 0; i < str.length(); i++)
                num = num * 10 + (str[i] - '0');
            cout << earthToMar[num] << endl;
        } else { //mars
            cout << marToEarth[str] << endl;
        }
    }
}
