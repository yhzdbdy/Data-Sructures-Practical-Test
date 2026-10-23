#include<bits/stdc++.h>
using namespace std;
//直接逐一对着数组来操作肯定是On2的复杂度
int Count(int max, vector<int>& pos) {

    int ans = 0;
    //我们遍历每一个小数字，寻找它的倍数是否pos出现在前面
    //只要小于max/2就行，后面的数字不可能有倍数了
    for(int small = 1; small <= max/2; small++) {
        for(int big = 2 * small; big <= max; big += small) {
            if(pos[big] < pos[small]) ans++;
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        //初始化数组
        // vector<int> arr;
        int n; cin >> n; int val;
        //标记出现每个数字的下标,数字从1开始，我们的pos多一个位置
        vector<int> pos(n + 1);
        /*我们想在这里得到每个数字出现的下标*/
        for(int j = 0; j < n; j++) {
            cin >> val;
            // arr.push_back(val);
            pos[val] = j;
        }

        // 判断
        cout << Count(n, pos) << '\n';
    }
}