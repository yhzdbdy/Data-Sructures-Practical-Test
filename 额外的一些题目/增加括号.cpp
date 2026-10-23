#include<bits/stdc++.h>
using namespace std;

int operate(string& s) {
    stack<char> st;
    //记录开始和结束位置要添加的括号数目
    int begin = 0; int end = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') st.push('(');
        else if(s[i] == ')') {
            //要加一个‘（’
            if(st.empty()) {begin++;}
            else st.pop();
        }
    }
    //末尾要添加这么多')'
    if(!st.empty()) {
        end = st.size();
    }

    for(int i = 0; i < begin; i++) {
        s = '(' + s;
    }
    for(int j = 0; j < end; j++) {
        s += ')';
    }  
    return end + begin;
}

int main() {
    string s;
    while(cin >> s) {
        int n = operate(s);
        if(n == 0) {
            cout << "Match" << '\n';
        }
        else cout << n << '\n' << s << '\n';
    }
}