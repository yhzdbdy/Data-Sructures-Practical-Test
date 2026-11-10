#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : val(val), left(nullptr), right(nullptr) {

    }
};
void buildTree(Node* &node) {
    int val;
    cin >> val;
    if(val == 0) {
        node = nullptr;
        return;
    }

    node = new Node(val);
    buildTree(node -> left);
    buildTree(node -> right);
}
int main() {
    Node* root = nullptr;
    buildTree(root);
    if(root == nullptr) {
        return 0;
    }

    //s型层序遍历
    //使用双向队列
    deque<Node*> que;
    que.push_back(root);
    //标记接下来遍历的是第几层
    int lever = 1;
    while(!que.empty()) {
        int size = que.size();
        Node* cur = nullptr;
        //这一层要从左遍历
        if(lever % 2 == 1) {
            //但是上一层是从右向左遍历的，我们要从队尾开始pop
            for(int i = size; i > 0; i--) {
                cur = que.back(); que.pop_back();
                cout << cur -> val << " ";
                //先入右节点再左节点
                if(cur -> right)
                    que.push_front(cur -> right);
                if(cur -> left)
                    que.push_front(cur -> left);
            }
            lever++;
        }
        //要从右遍历
        else {
            //队列就是从左向右排列的
            for(int i = 0; i < size; i++) {
                cur = que.front();  que.pop_front();
                cout << cur -> val << " ";

                if(cur -> left)
                    que.push_back(cur -> left);
                if(cur -> right)
                    que.push_back(cur -> right);
            }
            lever++;
        }
    }
    return 0;
}