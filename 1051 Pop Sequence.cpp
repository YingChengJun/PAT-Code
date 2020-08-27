#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int m, n, r, num;
    stack<int> st;
    cin >> m >> n >> r;
    for (int i = 0; i < r; i++) {
        int top = 0;
        bool flag = true;
        while (!st.empty()) { //clear the stack when a query begin
            st.pop();
        }
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (!flag)
                continue;
            //when we push a number, we need to confirm all the numbers less than it
            //have already been pushed into the stack
            //the variable top reference to the maximum pushed number
            if (num > top) {
                //push all the number from (top, num] and check the size of stack
                for (int k = top + 1; k <= num; k++) {
                    st.push(k);
                    if (st.size() > m) {
                        flag = false;
                        continue;
                    }
                }
                top = num;  //update maximum pushed number
                st.pop(); //pop the current number
            } else if (st.top() == num) {  //fortunately the number we need to pop is on the top of the stack
                st.pop();
            } else {  //it implies the number is in the stack or already poped
                flag = false;
                continue;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
