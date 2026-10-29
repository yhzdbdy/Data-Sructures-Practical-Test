#include<bits/stdc++.h>
using namespace std;
/*
后缀，我们直接反转字符串建立反转以后的next数组
拿到最大值
*/

int buildNext(string& s, vector<int>& next) {
    int len = s.size();
    int max = 0;
    int k = -1; next[0] = -1;
    for(int i = 0; i < s.size(); i++) {
        while(k >= 0 && s[k] != s[i]) {
            k = next[k];
        }
        next[i+1] = ++k;
        if(max < k) {
            max = k;
        }
    }
    return max;
}
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> next(s.size() + 1);
    cout << buildNext(s, next) << endl;
}