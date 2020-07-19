#include <iostream>
#include <vector>
#define left(x) (2*(x))
#define right(x) (2*(x)+1)
using namespace std;

vector<int> post;
bool isMax, isMin;

void postOrder(vector<int> &v, int cur, int n) {
	if (left(cur) <= n) {
		if (v[left(cur)] < v[cur]) isMin = false;
		if (v[left(cur)] > v[cur]) isMax = false;
		postOrder(v, left(cur), n);
	}
	if (right(cur) <= n) {
		if (v[right(cur)] < v[cur]) isMin = false;
		if (v[right(cur)] > v[cur]) isMax = false;
		postOrder(v, right(cur), n);
	}
	post.push_back(v[cur]);
}

int main() {
	int n, m;
	cin >> m >> n;
	while (m--) {
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		post.clear();
		isMax = isMin = true;
		postOrder(v, 1, n);
		if (isMax) cout << "Max Heap" << endl;
		else if (isMin) cout << "Min Heap" << endl;
		else cout << "Not Heap" << endl;
		for (int i = 0; i < post.size(); i++) {
			if (i > 0) cout << " ";
			cout << post[i];
		}
		cout << endl;
	}
}