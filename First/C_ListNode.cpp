#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int n) {
        this -> val = n;
        this -> next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;
    //哨兵节点
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        ListNode* cur = new ListNode(m);
        pre -> next = cur;
        pre = cur;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int op;
        cin >> op;
        //插入
        if(op == 0) {
            int index;
            int value;
            cin >> index >> value;
            //忽略
            if(index > n) continue;
            //创建节点
            ListNode* addNode = new ListNode(value);
            //遍历寻找需要插入的位置
            ListNode* cur = head;
            for(int j = 0; j < index; j++) {
                cur = cur -> next;
            }
            //现在cur是需要插入位置的前一个节点
            ListNode* follow = cur -> next;
            cur -> next = addNode;
            addNode -> next = follow;
            //链表长度加一
            n++;
        } else {
            int index;
            cin >> index;
            if(index <= 0 || index > n) continue;
            ListNode* pre = head;
            ListNode* cur = head -> next;
            for(int j = 1; j < index; j++) {
                pre = cur;
                cur = cur -> next;
            }
            ListNode* follow = cur -> next;
            pre -> next = follow;
            delete(cur);
            n--;
        }
    }

    ListNode* cur = head -> next;
    while(cur != nullptr) {
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    return 0;
}