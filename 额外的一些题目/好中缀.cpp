#include<bits/stdc++.h>
using namespace std;
/*
第二长前后缀就是next[next[n]]
*/

void buildNext(string& p, vector<int>& next) {
    int k = -1; next[0] = -1;
    for(int i = 0; i < next.size() - 1; i++) {
        while(k >= 0 && p[k] != p[i]) {
            k = next[k];
        }
        next[i+1] = ++k;
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    //依旧多构建一位
    vector<int> next(s.size() + 1);
    buildNext(s, next);
    if(next[next.size() - 1] == 0) {cout << s.size() << '\n'; return 0;}
    int len = next[next[next.size() - 1]];
    //注意这里不要写.size模式，减为负数的时候会回绕成为一个很大的正数
    cout << (n - 2 * len >= 0 ? n - 2 * len : 0) << endl;
    // cout << (s.size() - 2 * len >= 0 ? s.size() - 2 * len : 0) << '\n';
    return 0;
}