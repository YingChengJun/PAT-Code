#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int n1 = (n + 2) / 3;
    int n2 = (n + 2) - 2 * n1;
    int blank = n2 - 2;
    int i;
    for (i = 0; i < n1 - 1; i++) {
        cout << s[i];
        for (int j = 0; j < blank; j++)
            cout << " ";
        cout << s[n - i - 1] << endl;
    }
    for (int j = 0; j < n2; j++) {
        cout << s[i];
        i++;
    }
}
