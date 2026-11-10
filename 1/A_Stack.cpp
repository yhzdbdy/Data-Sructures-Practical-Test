#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;

class A_Stack
{
public:
    bool empty() { return topIndex == -1; };
    void pop()
    {
        if(this -> empty()) {cout << "invalid" << endl;}
        else {cout << A[topIndex--] << endl;}
    }
    void push(int n) { A[++topIndex] = n; }

private:
    // 标记栈顶位置，初始化为-1
    int topIndex = -1;
    // 数组
    int A[MAX];
};

int main()
{
    A_Stack a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int m;
            cin >> m;
            a.push(m);
        } else {
            a.pop();
        }
    }
    return 0;
}