#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
class Queue{
public:
    //判断是否空队列
    bool empty() {
        return Front == rear;
    }
    //元素入队
    void push(int n) {
        myQue[rear++] = n;
    }

    //出队元素
    void pop() {
        if(empty()) {
            cout << "invalid" << endl;;
            return;
        }
        cout << myQue[Front++] << endl;
    }

private:
    int Front = 0;
    int rear = 0;
    int myQue[MAX];
};

int main() {
    Queue que;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int m;
            cin >> m;
            //入队
            que.push(m);
        } else {
            que.pop();
        }
    }
    return 0;
}