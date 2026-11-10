#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	char c;
	Node* left;
	Node* right;
	Node(char c) : c(c) {
		
	}
};
bool invalid;
/*
后续： *左子树*  *右子树*  root
中序： *左子树*  root  *右子树*
*/
int findIndex(string& s, char c) {
    int i = 0;
    for(; i < s.size(); i++) {
        if(s[i] == c) break;
    }
    return i;
}
Node* buildTree(string& s1, string& s2) {
    //要添加一个两个序列长度的比较 ！！！！！
    int len = s1.size();
    int len2 = s2.size();

    if(len == 0 || invalid == false) return nullptr;
    //先找到根
    char root = s1[len-1];
    //根据根的位置切分左右子树
    int index = findIndex(s2, root);
    //找不到根节点代表非法序列
    /* 这里只改变了标志， 要记得返回！！！！*/
    if(index == len || len != len2) {invalid = false; return nullptr;}
    //构造节点
    Node* cur = new Node(root);
    /*
    切分，如果是vector容器就是vector<int> t(v.begin() + 1, v.begin() + 4)迭代器写法
    */
    string s1left = s1.substr(0, index);
    string s1right = s1.substr(index, len - index - 1);
    string s2left = s2.substr(0, index);
    string s2right = s2.substr(index+1, len - index - 1);
    cur -> left = buildTree(s1left, s2left);
    cur -> right = buildTree(s1right, s2right);
    return cur;
}
//高度使用后序遍历
int hight(Node* root) {
    if(root == nullptr) return -1;
    return max(hight(root -> left), hight(root -> right)) + 1;
}
void preOrder(Node* root) {
    stack<Node*> st;
    Node* p = root;
    while(true) {
        //这里写成了 ==   ！！！！
        while(p != nullptr) {
            cout << p -> c;
            st.push(p);
            p = p -> left;
        }
        if(st.empty()) return;
        p = st.top(); st.pop();
        p = p -> right;
    }
}
//后续+中序
int main() {
    string s1, s2;
    while(cin >> s1 >> s2) {
        //全局标记
        invalid = true;
        Node* root = buildTree(s1, s2);
        if(invalid == false) {
            cout << "INVALID" << '\n';
        }
        else {
            cout << hight(root) << '\n';
            preOrder(root); 
            cout << '\n';
        }
    }
    return 0;
}