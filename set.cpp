#include <stdio.h>
#include <set>
using namespace std;

int main(void) {
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d ", *it);

    set<int>::iterator it = st.find(2);
    printf("\n%d\n", *it);

    st.erase(st.find(2));  //remove by iterator
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d ", *it);
    printf("\n");

    st.erase(3);  //remove by value
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d ", *it);
    printf("\n");

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(6);
    st.erase(st.find(2), st.find(5)); //remove number in [2,5)
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d ", *it);
    printf("\n");

    return 0;
}
