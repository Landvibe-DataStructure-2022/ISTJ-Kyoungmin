//
//  wk3p1.cpp
//  BOJ
//
//  Created by 이경민 on 2022/03/16.
//

#include<iostream>
#include<string>
using namespace std;
 
int t, n, x;
string cmd;
 
class Stack {
public:
    int stack[10];
    int index;
 
    Stack() {
        index = 0;
    }
 
    bool empty() {
        return index == 0;
    }
 
    void top() {
        if (empty()) cout << "-1\n";
        else cout << stack[index-1] << "\n";
    }
 
    void push(int x) {
        if (index == t) cout << "FULL\n";
        else stack[index++] = x;
    }
 
    void pop() {
        if (empty()) cout << "-1\n";
        else cout << stack[--index] << "\n";
    }
};
 
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t >> n;
    Stack st;
 
    while (n--) {
        cin >> cmd;
        if (cmd == "empty") {
            cout << st.empty() << "\n";
        }
        else if (cmd == "top") {
            st.top();
        }
        else if (cmd == "push") {
            cin >> x;
            st.push(x);
        }
        else if (cmd == "pop") {
            st.pop();
        }
    }
}
