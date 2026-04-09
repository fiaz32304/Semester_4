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
		void preorder(Node *root){
			if(root==NULL){
				return ;
			}
			cout<<root->data <<"  ";
			preorder(root->right);
			preorder(root->left);
		}
		
		void inorder(Node *root){
			if(root==NULL){
				
				return;
			}
			inorder (root->right);
			cout<< root->data<<" ";
			inorder( root ->left);
		}
		void postorder(Node* root){
			if(root==NULL){
				return ;
			}
			postorder(root->right);
			postorder(root->left);
			cout<<root->data<<" ";
		}
};
int main(){
	bt tree;
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	
	cout<<"preorder NRL ";
	tree.preorder(root);
	
	cout<<"\ninorder RNL " ;
	tree.inorder(root);
	
	cout<<"\npostorder RLN ";
	tree.postorder(root);
	
	return 0; 
	
}

