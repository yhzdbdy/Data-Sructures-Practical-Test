#include<bits/stdc++.h>
using namespace std;
//用map来标记当前字符最后一次出现的位置后面不重复的元素个数
unordered_map<char, int> myMap;
void buildHash(vector<int>& isAppear, string& s) {
    int len = s.size();
    //最后一位初始化为0，后面没有字符
    isAppear[len - 1] = 0;
    // myMap.insert({s[len - 1], 0});
    //从后往前找
    for(int i = len - 1; i > 0; i--) {
        //当前字符是第一次出现,也代表他是最后一个这个字符
        // if(i == 0) continue;
        if(myMap.find(s[i]) == myMap.end()) {
            //前一个字符后面不相同的字符数量加一
            isAppear[i - 1] = isAppear[i] + 1;
            //插入当前字符和它的后面不同字符数量
            myMap.insert({s[i], isAppear[i]});
        }
        else {
            //只要初始化数组就行
            isAppear[i - 1] = isAppear[i];
        }
    }
    if(myMap.find(s[0]) == myMap.end()) {myMap.insert({s[0], isAppear[0]});}
}

int main() {
    string s;
    cin >> s;
    int len = s.size();
    vector<int> isApear(len);
    buildHash(isApear, s);
    string s1 = "";
    for(int i = 0; i < len; i++) {
        s1 += ('a' + myMap[s[i]]);
    }
    cout << s1;
}