#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node*right;
	
	
	Node(int val){
		data=val;
		left=right=NULL;
		
	}
	
};
class bt{
	public:
	Node* insert(Node*root,int value){
		if(root==NULL){
			return new Node(value);
		}
		if(value<root->data){
			root->left=insert(root->left,value);
		}
		else{
			root->right=insert(root->right, value);
		}
		return root;
	}
	
	void printleafnodes(Node *root){
		if(root==NULL){
			return ;
		}
		if(root->left==NULL && root->right==NULL){
			cout <<root->data <<" ";
			return ;
		}
		printleafnodes(root->left);
			printleafnodes(root->right);
	}
	
	int countleafnodes(Node *root){
		if (root==NULL)
			return 0;
		
		if(root->left == NULL && root->right== NULL){
			return 1;
		}
			return countleafnodes(root->left) + countleafnodes(root->right);
		
	}
};
int main() {
	bt tree;
	Node* root= NULL;
	root=tree.insert(root,50);
	tree.insert(root, 30);
    tree.insert(root, 70);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 60);
    tree.insert(root, 80);
    
    cout<<" leaf nodes ";
    tree.printleafnodes(root);
    
    cout<<"\ntotal leaf nodes :";
    cout<<tree.countleafnodes(root);
    
    return 0;
}

	

