#include<bits/stdc++.h>
using namespace std;
//这里只要顺时针，我们只设置单项循环就行
class Node{
public:
    int val;
    Node* next;
    Node(int val) {
        this -> val = val;
        this -> next = nullptr;
    }
};

void getLine(Node* head, Node* tail, int n, int m) {
    Node* pre = tail;
    while(n > 1) {
        //顺时针m1个
        int m1 = m % n;
        if(m1 == 0) m1 = n;
        for(int i = 1; i < m1; i++) {
            pre = head;
            head = head -> next;
        }
        //删除
        pre -> next = head -> next;
        cout << head -> val << " ";
        delete(head);
        n--;
        head = pre -> next;
        m++;
    }
    cout << head -> val << " " << '\n';
}
int main() {
    int n, m;
    cin >> n >> m;
    //初始化链表
    Node* head = new Node(1);
    Node* tail = head;
    for(int i = 2; i <= n; i++) {
        Node* cur = new Node(i);
        tail -> next = cur;
        tail = cur;
    }
    tail -> next = head;
    getLine(head, tail, n, m);
    return 0;
}