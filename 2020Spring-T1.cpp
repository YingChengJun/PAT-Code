#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int atoi(string s) {
	stringstream ss;
	int val;
	ss << s;
	ss >> val;
	return val;
}

int main() {
	string s;
	cin >> s;
	bool flag = true;
	for (int i = 0; i < 8; i++) {
		string t = s.substr(i);
		cout << t;
		if (isPrime(atoi(t))) {
			cout << " Yes" << endl;
		} else {
			cout << " No" << endl;
			flag = false;
		}
	}
	if (flag) cout << "All Prime!";
}