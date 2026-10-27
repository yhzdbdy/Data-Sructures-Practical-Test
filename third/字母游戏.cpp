/*
最长重复后缀就是倒着构建next数组里的最大值
第二场相等前后缀长度 next[next[n]]
*/
#include<bits/stdc++.h>
using namespace std;
int maxLen = -1;

void buildNext(vector<int>& next, string& s) {
    //一定要记得每次调用都重置一遍maxLen
    maxLen = -1;
    int k = -1; next[0] = -1;
    int len = s.size() + 1;
    for(int i = 0; i < len - 1; i++) {
        while(k >= 0 && s[k] != s[i]) {
            k = next[k];
        }
        next[i + 1] = ++k;
        maxLen = k > maxLen ? k : maxLen;
    }
}

int main() {
    string s;
    while(cin >> s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        //多构件一位到最后一个字符
        vector<int> next1(s.size() + 1);
        buildNext(next1, s1);
        //前后缀两个要*2
        int n1 = s.size() - next1[next1[s.size()]] * 2;
        //有一个问题就是如果next1[next1[s.size()]] = 0，第二长的就是next[0] = -1
        if(next1[s.size()] == 0) n1 = s.size(); 
        //而且减法要保证n1长度大于等于0
        else if(n1 < 0) n1 = 0;
        cout << n1 + maxLen << endl;
        // cout << maxLen;
        // cout << next1[next1[s.size()]];
    }
}