#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	while (k--) {
		stack<int> s;
		int num;
		int flag = 1;
		vector<int> vis(n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (!flag) continue;
			for (int j = 1; j <= num; j++) {
				if (!vis[j]) {
					s.push(j);
					vis[j] = 1;
				}
			}
			if (s.empty()) {
				int a = 1;
			}
			if (s.top() == num && s.size() <= m) {
				s.pop();
			} else {
				flag = 0;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
}