#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct BigNum {
    vector<int> v;
    BigNum() {

    }
    BigNum(int n) {
        while (n > 0) {
            v.insert(v.begin(), n % 10);
            n /= 10;
        }
    }
    void print() {
        for (int i = 0; i < v.size(); i++) {
            printf("%d", v[i]);
        }
    }
    int length() {
        return v.size();
    }
    bool isPalindromic() {
        vector<int> vv = v;
        reverse(vv.begin(), vv.end());
        return vv == v;
    }
};

BigNum addBigNum(BigNum &a, BigNum &b) {
    BigNum c;
    int posA = a.length() - 1, posB = b.length() - 1;
    int carry = 0, sum;
    while (posA >= 0 && posB >= 0) {
        sum = a.v[posA] + b.v[posB] + carry;
        carry = 0;
        if (sum >= 10) {
            carry = sum / 10;
            sum %= 10;
        }
        c.v.insert(c.v.begin(), sum);
        posA--;
        posB--;
    }
    while (posA >= 0) {
        sum = a.v[posA] + carry;
        carry = 0;
        if (sum >= 10) {
            carry = sum / 10;
            sum %= 10;
        }
        c.v.insert(c.v.begin(), sum);
        posA--;
    }
    while (posB >= 0) {
        sum = b.v[posB] + carry;
        carry = 0;
        if (sum >= 10) {
            carry = sum / 10;
            sum %= 10;
        }
        c.v.insert(c.v.begin(), sum);
        posB--;
    }
    if (carry > 0) {
        c.v.insert(c.v.begin(), carry);
    }
    return c;
};

BigNum reverseBigNum(BigNum &a) {
    BigNum b;
    b.v = a.v;
    reverse(b.v.begin(), b.v.end());
    return b;
}

int main() {
    int i = 0, n, k, cnt = 0;
    scanf("%d %d", &n, &k);
    BigNum a = BigNum(n), b, rev;
    if (!a.isPalindromic()) {
        for (i = 1; i <= k; i++) {
            rev = reverseBigNum(a);
            b = addBigNum(a, rev);
            a = b;
            if (b.isPalindromic()) {
                break;
            }
        }
    }
    a.print();
    if (i > k) {
        printf("\n%d", k);
    } else {
        printf("\n%d", i);
    }
}

