#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindromic(string s) {
    string str(s);
    reverse(str.begin(), str.end());
    return str == s;
}

string add(string a, string b) {
    string ans;
    int lenA = a.size() - 1, lenB = b.size() - 1;
    int carry = 0, sum = 0;
    while (lenA >= 0 && lenB >= 0) {
        sum = (a[lenA] - '0') + (b[lenB] - '0') + carry;
        carry = sum / 10;
        ans = (char)((sum % 10) + 48) + ans;
        lenA--;
        lenB--;
    }
    while (lenA >= 0) {
        sum = (a[lenA] - '0') + carry;
        carry = sum / 10;
        ans = (char)((sum % 10) + 48) + ans;
        lenA--;
    }
    while (lenB >= 0) {
        sum = (b[lenB] - '0') + carry;
        carry = sum / 10;
        ans = (char)((sum % 10) + 48) + ans;
        lenB--;
    }
    if (carry) ans = (char)(carry + 48) + ans;
    int i = 0;
    while (ans[i] == '0') {
        i++;
    }
    ans.erase(ans.begin(), ans.begin() + i);
    return ans;
}

int main() {
    string s, rev, ans;
    cin >> s;
    int k = 10;
    if (isPalindromic(s)) {
        cout << s << " is a palindromic number." << endl;;
        return 0;
    }
    while (k--) {
        rev = s;
        reverse(rev.begin(), rev.end());
        ans = add(s, rev);
        cout << s << " + " << rev << " = " << ans << endl;
        if (isPalindromic(ans)) {
            cout << ans << " is a palindromic number." << endl;;
            return 0;
        }
        s = ans;
    }
    cout <<"Not found in 10 iterations." << endl;
}
