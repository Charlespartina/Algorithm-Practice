#import <iostream>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v) : val(v),left(NULL),right(NULL){}
};

struct BST{
	Node* root;
	int sz;
	BST() : sz(0),root(NULL){}

	void insert(int val){
		insert(val,root);
	}
	void insert(int val, Node* now){
		if(now == NULL) now = new Node(val);
		else if (val <= now->val){
			insert(val,now->left);
		}
		else{
			insert(val,now->right);
		}
	}
	void remove(int val, Node* now){
		if(now == NULL){
			cout << "NOT FOUND" << endl;
		}
		else if(now->val < val){
			remove(val, now->left);
		}
		else if(now->val > val){
			remove(val, now->right);
		}
		else{
			
		}
	}
};

int main(){


	return 0;
}
