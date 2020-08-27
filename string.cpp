#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "abcd";
    string str2 = "rst";
    str.insert(3, "opq"); //output: abcopqd
    str.insert(str.begin() + 6, str2.begin(), str2.end()); //output: abcopqrstd
    str.erase(str.end() - 1); //output: abcopqrst
    str.erase(str.begin(), str.begin() + 3); //output: opqrst
    str.erase(1, 3); //output: ost
    str.append("uvwxyz"); //output: ostuvwxyz
    str.replace(1, 3, "abcdefg"); //output: oabcdefgvwxyz
    str.replace(1, 7, ""); //output: ovwxyz
    str.replace(str.begin(), str.end(), "pqr"); //output: pqr
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        printf("%c", *it);
    }
    printf("\n");
    cout << str.substr(2, 5) << endl;  //output: tuvwx
    str = "abcdebcdg";
    cout << str.find("bcd") << endl;    //1
    cout << str.find("bcd", 5) << endl;  //5
    cout << (str.find("efg") == -1) << endl; //true
}
