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
	//当前节点
	root = new Node(n);
	buildTree(root -> left);
	buildTree(root -> right); 
} 

Node* findFather(Node* root, int target) {
	//终止条件 
	if(root == nullptr) return nullptr;
	/*这样写会漏查*/
	// if(root -> left == nullptr || root -> right == nullptr) return nullptr;
	// if(root -> left -> val == target || root -> right -> val == target) {
	// 	return root;
	// }
	if((root->left != nullptr && root->left->val == target) ||(root->right != nullptr && root->right->val == target)) {
    	return root;
	}
	
	//递归寻找元素写法，不能直接返回left，不然可能为空就直接return了 
	Node* tmp = findFather(root -> left, target);
	if(tmp != nullptr) return tmp;
	return findFather(root -> right, target);
}
int main() {
	Node* root = new Node(-1);
	buildTree(root);
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int target; cin >> target;
		if(root -> val == target) {
			cout << 0 << '\n';
			continue;
		}
		Node* cur = findFather(root, target);
		cout << (cur == nullptr ? 0 : cur -> val) << '\n'; 
	}
	return 0;
}
