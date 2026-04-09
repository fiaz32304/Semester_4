#include <iostream>
using namespace std;

class node{
	public:
		
	int data;
	node*next;
	
	node(int val){
		data=val;
		next=NULL;
		
	}
	
};
class sin{
	public:
	node*head;
	node*tail;
	
	sin(){
		head=tail=NULL;
	}
	
	void insert(int val){
		node *newnode=new node(val);
		if (head==NULL){
			head=tail=newnode;
		}
			
			else{
				newnode->next=head;
				head=newnode;
			
			
		}
		
		
	}
	void insertend(int val){
	node *newnode=new node(val);
		if (head==NULL){
			head=tail=newnode;
		}
		else{
			tail->next = newnode;
			tail=newnode;
		}
	}
	
	void insertspe(int val, int pos){
		node *n1=new node(val, pos);
		if(head==NULL){
			cout<<"list is empty";
		}
		else if(pos<0){
			cout<<"invalid";
		}
		else if(pos==0){
			insert(val);
		}
		else{
			node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;	
			}
			n1->next=temp->next;
			temp->next=n1;
		}
	}
	void display(){
		node* temp=head;
		
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
	

			cout<<endl;
	}
	
};
int main(){
	sin l1;
	l1.insert(2);
	l1.insert(5);
	l1.display();
	l1.insertend(6);
	l1.insertend(1);
	l1.display();
	l1.insertspe(12,3);
	l1.insertspe(8,2);
	
	return 0;
}
