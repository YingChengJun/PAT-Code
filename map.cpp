#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, int> mp;
    mp['a'] = 97;
    mp['b'] = 98;
    mp['c'] = 99;

    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    //if not find the key then it == mp.end()
    //also use mp.count(key) to check whether the key exist
    map<char, int>::iterator it = mp.find('b');
    cout << "The value of key b is : " << it->second << endl;   //output: 98
    mp.erase(it);
    mp.erase('c');
    cout << "Size after erase is: " << mp.size() << endl;  //output: 1

    mp['d'] = 100;
    mp['e'] = 101;
    mp['f'] = 102;
    mp['g'] = 103;
    map<char, int>::iterator start = mp.find('d');
    map<char, int>::iterator end = mp.find('f');
    mp.erase(start, end);
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    } //output: a f g

    mp.clear();
    cout << "Size after clear is: " << mp.size() << endl;  //output:0
}
