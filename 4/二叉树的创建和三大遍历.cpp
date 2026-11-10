#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(int val) : val(val){
		
	}
};

//前序遍历构造 ,传引用 
void buildTree(Node* &node) {
	//终止条件
	int n; cin >> n; 
	if(n == 0) {
		node = nullptr;
		return;
	}
	node = new Node(n);
	//左右
	buildTree(node -> left);
	buildTree(node -> right);
}

void preOrder(Node* root) {
	if(root == nullptr) return;
	stack<Node*> st;
	Node* p = root;
	while(true) {
		while(p != nullptr) {
			//先遍历中节点
			cout << p -> val << " ";
			st.push(p);
			p = p -> left; 
		}
		if(st.empty()) return;
		//向左遍历到空节点，弹栈遍历右节点
		p = st.top(); st.pop();
		p = p -> right; 
	}
}
void inOrder(Node* root) {
	if(root == nullptr) return;
	stack<Node*> st;
	Node * p = root;
	while(true) {
		while(p != nullptr) {
			//先找左节点
			st.push(p);
			p = p -> left; 
		}
		if(st.empty()) return;
		p = st.top(); st.pop();
		cout << p -> val << " ";
		p = p -> right;
	}
}
void postOrder(Node* root) {
	if(root == nullptr) return;
	stack<Node*> st;
	Node* p = root;
	//额外一个空间用来存储前一个遍历的结点 
	Node* pre = nullptr;
	while(true) {
		while(p != nullptr) {
			//一直向左遍历
			st.push(p);
			p = p -> left; 
		}
		if(st.empty()) return;
		//在这里不要弹栈 
		p = st.top();
		//在右节点为空或者刚才访问过可以遍历当前节点
		if(p -> right == nullptr || p -> right == pre) {
			st.pop(); 
			cout << p -> val << " ";
			//更新pre和p 
			pre = p;
			p = nullptr; 
		} 
		else {
			p = p -> right;
		}
	}
}
int main() {
	Node* root = new Node(-1);
	buildTree(root);
	
	//三个遍历
	preOrder(root); cout << '\n';
	inOrder(root); cout << '\n';
	postOrder(root); cout << '\n';
	
	return 0;
}

