#include<bits/stdc++.h>
using namespace std;

void traversal(int n, int k) {
    //用栈来存每次操作后的数
    stack<int> st;
    while(n != 0) {
        int m = n % k;
        n /= k;
        st.push(m);
    }
    //弹栈得到转换得到的数字
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    traversal(n, k);
    cout << endl;
    return 0;
}