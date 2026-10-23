#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int op;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        cin >> op;
        if(op == 1) st.push(1);
        else if(op == 0) {
            if(!st.empty()) st.pop();
            else {cout << 0; return 0;}
        }
    }
    st.empty() ? cout << 1 : cout << 0;
    return 0;
}