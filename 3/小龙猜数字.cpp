#include<bits/stdc++.h>
using namespace std;

void buildNext(string& s, vector<int>& next) {
    int k = -1; next[0] = -1;
    int len = s.size();
    for(int i = 0; i < len; i++) {
        while(k >= 0 && s[k] != s[i]) {
            k = next[k];
        }
        next[i + 1] = ++k;
    }
}
long long cac(string& s, int len, vector<int>& next) {
    long long ans = 0;
    //长度为1就是加0，直接略过
    for(int i = 1; i <= len; i++) {
        int k = next[i];
        if(k <= 0) {
            ans += 0;
            continue;
        }
        //一直寻找最短的知道下一个是0
        while(k > 0 && next[k] > 0) {
            k = next[k];
        }

        //我们这里直接更新next[i]
        next[i] = k;
        
        ans += i - k;
    }
    return ans;
}

int main() {
    int len; cin >> len;
    string s; cin >> s;
    //依旧多一位
    vector<int> next(len + 1);
    buildNext(s,next);
    cout << cac(s, len, next) << endl;
}