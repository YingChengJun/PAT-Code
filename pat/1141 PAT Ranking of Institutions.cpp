#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	string name;
	int ns = 0;
	int sa = 0;
	int sb = 0;
	int st = 0;
	int score() const {
		return sa + sb / 1.5 + st * 1.5;
	}
	Node(string s) : name(s) {};
	bool operator < (const Node& node) const {
		if (score() == node.score()) {
			if (ns == node.ns) {
				return name < node.name;
			}
			return ns < node.ns;
		}
		return score() > node.score();
	}
};
vector<Node> v;
map<string, int> pos;
int getIndex(string name) {
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	if (pos.find(name) == pos.end()) {
		v.push_back(Node(name));
		pos[name] = v.size() - 1;
	}
	return pos[name];
}

int main() {
	int n;
	cin >> n;
	string str, name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> str >> score >> name;
		int index = getIndex(name);
		if (str[0] == 'A') {
			v[index].sa += score;
		} else if (str[0] == 'B') {
			v[index].sb += score;
		} else if (str[0] == 'T') {
			v[index].st += score;
		}
		v[index].ns++;
	}
	sort(v.begin(), v.end());
	int rank = 1, pre = -1;
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		if (pre != v[i].score()) {
			rank = i + 1;
		}
		pre = v[i].score();
		cout << rank << " " << v[i].name << " " << v[i].score() << " " << v[i].ns << endl;
	}
}