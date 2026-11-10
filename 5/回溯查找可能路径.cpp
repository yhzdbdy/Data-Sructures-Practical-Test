#include<bits/stdc++.h>
using namespace std;

//查找所有可能的路径一定用深搜的回溯
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {

    }
};
//存放所有可行的路径
vector<vector<int>> ans;
//当前深搜的路径
vector<int> path;

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
void backTrack(Node* root, int sum, int k) {
    //处理当前节点
    path.push_back(root -> val);
    //终止条件  看题！！！！要是叶子节点
    if(sum == k && root -> left == nullptr && root -> right == nullptr) {
        ans.push_back(path);
        return;
    }
    //不会遇到空节点
    // if(root == nullptr) {
    //     return;
    // }

    //两个方向，一左一右
    if(root -> left){
        backTrack(root -> left, sum + root -> left -> val, k);
        path.pop_back();
    }
    if(root -> right) {
        backTrack(root -> right, sum + root -> right -> val, k);
        path.pop_back();
    }
}
int main() {
    Node* root = nullptr;
    buildTree(root);

    //一定要处理根节点为空情况！！！
    if(root == nullptr) {
        cout << 0;
        return 0;
    }

    int k; cin >> k;
    //递归入口
    backTrack(root, root -> val, k);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
        int j = ans[i].size();
        for(int m = 0; m < j; m++) {
            cout << ans[i][m] << " ";
        }
        cout << '\n';
    }
    return 0;
}