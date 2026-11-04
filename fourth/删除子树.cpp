#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(int val) : val(val) {
		
	}
};
void buildTree(Node* &root) {
	//终止条件	
	int n; cin >> n;
	if(n == 0) {
		root = nullptr;
		return;
	} 
	root = new Node(n);
	buildTree(root -> left);
	buildTree(root -> right);
}

//一定要接受引用，否则删除的只是副本！！！
Node*& findNode(Node*& root, int n) {
	if(root == nullptr) return root;
	if(root -> val == n) return root;
	
	Node*& tmp = findNode(root -> left, n);
	if(tmp != nullptr) return tmp;
	return findNode(root -> right, n); 
}

//删除子树,进行指针的修改一定要注意引用，不然修改的只是副本
void del(Node* &root) {
	if(root == nullptr) return;
	//删除要使用后序遍历，先遍历到底再删除节点
	del(root -> left);
	del(root -> right);
	//后续处理当前节点 
	delete root;
	root = nullptr; 
} 

void inOrder(Node* root) {
	if(root == nullptr) return;
	stack<Node*> st;
	Node* p = root;
	while(true) {
		while(p != nullptr) {
			st.push(p);
			p = p -> left;
		}
		if(st.empty()) return;
		p = st.top(); st.pop();
		cout << p -> val << " ";
		p = p -> right;
	}
}
int main() {
	Node* root = new Node(-1);
	buildTree(root);
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int n; cin >> n;
		
		//一定要接受引用，否则删除的只是副本！！！
		Node*& cur = findNode(root, n);
		if(cur == nullptr) {
			cout << 0 << '\n';
		}
		else {
			del(cur);
			inOrder(root);
			cout << '\n';
		}
	}
	return 0;
}
