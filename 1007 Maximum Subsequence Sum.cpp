#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int a[10000] = { 0 };
	cin >> n;
	int curSum = 0, maxSum = 0, cur = 0, start = 0, end = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		curSum += a[i];
		if (curSum < 0) {
			curSum = 0;
			cur = i + 1;
		}
		if (curSum > maxSum) {
			maxSum = curSum;
			start = cur;
			end = i;
		}
	}
	if (maxSum == 0) { //for test case: [-2, 0, 0, -1]
		int j;
		for (j = 0; j < n; j++) {
			if (a[j] == 0) break;  //find value 0
		}
		if (j < n) {
			start = end = j;
		}
	}
	cout << maxSum << " " << a[start] << " " << a[end];
	return 0;
}