#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
    explicit Queue(int capacity) : myQue(new int[capacity]) {}

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
            cout << "invalid" << '\n';
            return;
        }
        cout << myQue[Front++] << '\n';
    }

private:
    int Front = 0;
    int rear = 0;
    unique_ptr<int[]> myQue;
};

int main() {
    int n;
    if (!(cin >> n) || n < 0) {
        return 0;
    }
    Queue que(n);
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
