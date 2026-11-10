#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {

    }
};
/*我们要找到一个节点，左边有a，右边有b*/
void buildTree(Node* &node) {
    int val; cin >> val;
    if(val == 0) {
        node = nullptr;
        return;
    }
    node = new Node(val);
    buildTree(node -> left);
    buildTree(node -> right);
}
//采用后续遍历方法，判断两个子树是不是都有传入
Node* findNode(Node* root, int a, int b) {
    //终止条件
    if(root == nullptr) {
        return nullptr;
    }
    if(root -> val == a || root -> val == b) {
        return root;
    }

    Node* leftTree = findNode(root -> left, a, b);
    Node* rightTree = findNode(root -> right, a, b);

    //我们想要找到这个最近的公共祖先以后直接一直返回
    if(leftTree && rightTree) {
        return root;
    }
    //在往上走，只有一边有信号,返回这一边
    if(rightTree && !leftTree) {
        return rightTree;
    }
    if(leftTree && !rightTree) {
        return leftTree;
    }

    return nullptr;
}
void addPath(Node* root, int v, vector<int>& path, vector<int>& endPath) {
    path.push_back(root -> val);
    //终止条件  又写成了=   ！！！！
    if(root -> val == v) {
        endPath = path;
        return;
    }

    //两个方向
    if(root -> left) {
        addPath(root -> left, v, path, endPath);
        path.pop_back();
    }
    if(root -> right) {
        addPath(root -> right, v, path, endPath);
        path.pop_back();
    }
}
int main() {
    Node* root = nullptr;
    buildTree(root);
    int k; cin >> k;
    int a, b;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        //找到最近的公共祖先
        Node* parant = findNode(root, a, b);
        //开始找路径
        vector<int> pathLeft; vector<int> leftpath;
        vector<int> pathRight; vector<int> rightpath;
        addPath(parant, a, pathLeft, leftpath);
        addPath(parant, b, pathRight, rightpath);
        int sizeA = leftpath.size();
        int sizeB = rightpath.size();
        cout << sizeA + sizeB - 2 << '\n';
        for(int m = sizeA - 1; m >= 0; m--) {
            cout << leftpath[m] << " ";
        }
        for(int n = 1; n < sizeB; n++) {
            cout << rightpath[n] << " ";
        }
        cout << '\n';
    }
    return 0;
}