#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int id;
    Node *next;
    Node *prev;
    Node(int id, Node *next, Node *prev)
    {
        this->id = id;
        this->next = next;
        this->prev = prev;
    }
};

void getLine(Node *head, int m, int k, int n)
{
    Node *pre = head->prev;
    Node *nextn = head->next;
    // 当有两个以上节点一直操作
    while (n > 1)
    {
        // 逆向m个
        int m1 = m % n;
        if (m1 == 0)
            m1 = n;
        for (int i = 1; i < m1; i++)
        {
            head = head->prev;
            pre = pre->prev;
            nextn = nextn->prev;
        }
        // 删除
        nextn->prev = pre;
        pre->next = nextn;
        cout << head->id << " ";
        delete (head);
        // n变化
        n--;
        // 更新
        head = pre;
        pre = pre->prev;
        if (n > 1)
        {
            // 顺向k个
            int k1 = k % n;
            if (k1 == 0)
                k1 = n;
            for (int j = 1; j < k1; j++)
            {
                head = head->next;
                nextn = nextn->next;
                pre = pre->next;
            }
            // 删除
            pre->next = nextn;
            nextn->prev = pre;
            cout << head->id << " ";
            delete (head);
            n--;
            // 更新
            head = nextn;
            nextn = nextn->next;
        }
    }
    cout << head -> id << " " << '\n';
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    // 用链表来操作可以最快速的解决删除节点问题
    // 为了循环我们还要让这个链表循环
    Node *head = new Node(1, nullptr, nullptr);
    Node *tail = head;
    for (int i = 2; i <= n; i++)
    {
        Node *node = new Node(i, nullptr, nullptr);
        // 为节点的下一个是新节点,新节点的前置是尾节点
        tail->next = node;
        node->prev = tail;
        // 新节点现在是尾结点
        tail = node;
    }
    // 首尾相连
    tail->next = head;
    head->prev = tail;
    getLine(head, m, k, n);

    return 0;
}