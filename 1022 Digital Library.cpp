#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

void putMap(map<string, set<int> > &mp, string &key) {
    if (mp.find(key) == mp.end()) {
        printf("Not Found\n");
        return;
    }
    set<int>& st = mp[key];
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        printf("%07d\n", *it); //should notice it!
    }
}

int main() {
    map<string, set<int> > titleMap;
    map<string, set<int> > authorMap;
    map<string, set<int> > keyMap;
    map<string, set<int> > publishMap;
    map<string, set<int> > yearMap;
    int n, m, id;
    string title, author, keys, publisher, year;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%*c", &id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keys);
        getline(cin, publisher);
        getline(cin, year);
        titleMap[title].insert(id);
        authorMap[author].insert(id);
        publishMap[publisher].insert(id);
        yearMap[year].insert(id);
        istringstream iss(keys);
        string temp;
        while (getline(iss, temp, ' ')) {
            keyMap[temp].insert(id);
        }
    }
    scanf("%d", &m);
    int type;
    string word;
    for (int i = 0; i < m; i++) {
        scanf("%d: ", &type);
        getline(cin, word);
        cout << type << ": " << word << endl;
        switch(type) {
            case 1: putMap(titleMap, word); break;
            case 2: putMap(authorMap, word); break;
            case 3: putMap(keyMap, word); break;
            case 4: putMap(publishMap, word); break;
            case 5: putMap(yearMap, word); break;
        }
    }

}
