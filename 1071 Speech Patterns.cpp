#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> mp;
    map<string, int>::iterator it;
    string word;
    string maxword;
    int max = -1;
    char rd;
    while ((rd = cin.get()) != '\n') {
        if ((rd >= '0' && rd <= '9') || (rd >= 'a' && rd <= 'z')) {
            word = word + rd;
        } else if (rd >= 'A' && rd <= 'Z') {
            rd = rd - 'A' + 'a';
            word = word + rd;
        } else {
            //cout << "word:" << word << endl;
            if (word.size() == 0) continue; //also non-alphanumerical word
            mp[word]++;
            if (mp[word] > max || (mp[word] == max && word < maxword)) {
                max = mp[word];
                maxword = word;
            }
            word = "";
        }
    }
    if (word.size() > 0) {  //check last word for case: [:/abc]
        mp[word]++;
        if (mp[word] > max || (mp[word] == max && word < maxword)) {
            max = mp[word];
            maxword = word;
        }
    }
    cout << maxword << " " << max;
}
