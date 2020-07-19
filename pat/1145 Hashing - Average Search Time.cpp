#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int x) {
	if (x == 2) return true;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int nextPrime(int x) {
	while (!isPrime(x)) {
		x++;
	}
	return x;
}

int main() {
	int size, m, n, num;
	cin >> size >> m >> n;
	size = nextPrime(size);
	vector<int> v(size, -1);
	while (m--) {
		cin >> num;
		int i;
		for (i = 0; i < size; i++) {
			int pos = (num + i * i) % size;
			// 如果已经存在相同的key或者没有被占用
			if (v[pos] == num || v[pos] == -1) {
				v[pos] = num;
				break;
			}
		}
		if (i == size) {
			printf("%d cannot be inserted.\n", num);
		}
	}
	int tot = 0;
	for (int j = 0; j < n; j++) {
		int ans = 0;
		cin >> num;
		for (int i = 0; i <= size; i++) {
			int pos = (num + i * i) % size;
			// 为-1的时候说明没找到, 相等的时候说明找到了
			if (v[pos] == num || v[pos] == -1) {
				ans = i + 1;
				break;
			}
		}
		if (ans == 0) ans = size + 1;
		tot += ans;
	}
	printf("%.1f", 1.0 * tot / n);
}