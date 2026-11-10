#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    char c;
    Node* left;
    Node* right;
    Node(char c) : c(c), left(nullptr), right(nullptr) {

    }
};
//传引用
void buildTree(Node* &node) {
    char c; cin >> c;
    //终止条件
    if(c == '#') {
        node = nullptr;
        return;
    }

    //先根遍历先创建本次节点
    node = new Node(c);
    buildTree(node -> left);
    buildTree(node -> right);
}
int main() {
    Node* root = nullptr;
    buildTree(root);

    if(root == nullptr) {
        cout << 0 << '\n';
        return 0;
    }
    //层序遍历
    queue<Node*> que;
    que.push(root);
    while(!que.empty()) {
        //本层节点数
        int size = que.size();
        int count = 0;
        for(int i = 0; i < size; i++) {
            //出队
            Node* cur = que.front(); que.pop();
            if((cur -> left == nullptr && cur -> right != nullptr) || (cur -> left != nullptr && cur -> right == nullptr)) {
                count += 1;
            }
            if(cur -> left != nullptr)
                que.push(cur -> left);
            if(cur -> right != nullptr) 
                que.push(cur -> right);
        }
        cout << count << '\n';
    }
    return 0;
}