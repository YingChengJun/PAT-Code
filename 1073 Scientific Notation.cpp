#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string value;
    cin >> str;
    int len = str.size(), i, exp = 0;
    bool isNegative = false, isExpNegative = false;
    if (str[0] == '-') isNegative = true;
    value = str[1];
    for (i = 3; i < len; i++) {
        if (str[i] == 'E') break;
        else value += str[i];
    }
    if (str[++i] == '-') isExpNegative = true;
    while (++i < len) {
        exp = exp * 10 + (str[i] - '0');
    }
    if (isNegative) cout << "-";
    if (!isExpNegative) {
        if (1 + exp >= value.size()) {
            for (int j = 0; j < value.size() - 1 - exp; j++) {
                value += "0";
            }
        } else {
            value.insert(1 + exp, ".");
        }
    } else {
        value.insert(0, exp - 1, '0');
        value = "0." + value;
    }
    cout << value << endl;
}

