//这种题我们不用递归，容易爆栈，直接使用dp就行

#include<bits/stdc++.h>
using namespace std;
//用一维数组就行
vector<long long> ans;
void initAns() {
    for(int i = 0; i < 100; i++) {
        //只能走一步
        if(i == 0) ans.push_back(1);
        //可以走两个一步+一个两步
        else if(i == 1) ans.push_back(2);
        else if(i == 2) ans.push_back(4);
        else if(i == 3) ans.push_back(8);
        else {
            ans.push_back(ans[i - 1] + ans[i - 2] + ans[i - 3] + ans[i - 4]);
        }
    }
}
int main() {
    int m;
    cin >> m;
    initAns();
    for(int i = 0; i < m; i++) {
        int n;
        cin >> n;
        //换行改成\n会好很多，时间变少
        cout << ans[n - 1] << '\n';
    }
}