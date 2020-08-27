#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, int> mp;
int mp2[100000] = { 0 };
const int maxn = 16;
struct Node
{
	vector<int> nums;
	bool flag = true;
} users[maxn];

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	mp[x] = 1;
	mp[y] = 1;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			scanf("%d", &num);
			users[i].nums.push_back(num);
		}
	}
	vector<int> vs;
	vs.push_back(x);
	vs.push_back(y);
	mp2[abs(x - y)] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!users[j].flag) continue;
			int num = users[j].nums[i];
			if (mp[num] || !mp2[num]) {
				printf("Round #%d: %d is out.\n", i + 1, j);
				users[j].flag = false;
			} else {
				mp[num] = 1;
				for (int k = 0; k < vs.size(); k++) {
					mp2[abs(num - vs[k])] = 1;
				}
				vs.push_back(num);
			}
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (users[i].flag) {
			ans.push_back(i);
		}
	}
	if (ans.size() == 0) {
		printf("No winner.");
	} else {
		printf("Winner(s):");
		for (int i = 0; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
	}
}