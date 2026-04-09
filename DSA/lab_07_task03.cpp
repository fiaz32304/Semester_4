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
class bst{
	public:
	Node* insert(Node* root , int value){
		if(root==NULL){
			return new Node(value);
		}
		if(value < root->data){
			root->left=insert(root->left,value);
		}
		else{
			root->right=insert(root->right, value);
		}
		return root;
	}
	
		Node *findMin(Node*root){
			while(root->left!=NULL)
			root=root->left;
			
			return root;
		}
		
		Node *deleteNode(Node* root , int key){
			if(root==NULL)
			return NULL;
			
			if(key < root->data)
			root->left= deleteNode(root->left, key);
			
			else if(key > root->data)
			root->right= deleteNode(root->right, key);
			
			else{
				
				 
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

        
            else {
                Node* temp = findMin(root->right); 
                root->data = temp->data;           
                root->right = deleteNode(root->right, temp->data); 
            }
        }

        return root;
    }

    
    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

// ----------- Main -----------
int main() {
    bst tree;
    Node* root = NULL;

    
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 70);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 60);
    tree.insert(root, 80);

    cout << "Original Tree : ";
    tree.inorder(root);

    
    root = tree.deleteNode(root, 50);

    cout << "\nAfter Deletion : ";
    tree.inorder(root);

    return 0;
}
			

	

