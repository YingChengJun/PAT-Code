#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 0;
    string usr, pwd;
    vector<string> usrs, pwds;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> usr >> pwd;
        bool flag = false;
        for (int j = 0; j < pwd.size(); j++) {
            if (pwd[j] == '1') {
                pwd[j] = '@';
                flag = true;
            }
            if (pwd[j] == '0') {
                pwd[j] = '%';
                flag = true;
            }
            if (pwd[j] == 'l') {
                pwd[j] = 'L';
                flag = true;
            }
            if (pwd[j] == 'O') {
                pwd[j] = 'o';
                flag = true;
            }
        }
        if (flag) {
            cnt++;
            usrs.push_back(usr);
            pwds.push_back(pwd);
        }

    }
    if (cnt == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            cout << usrs[i] << " " << pwds[i] << endl;
        }
    }
}
