#include <iostream>
using namespace std;

class node{
	public:
	int data;
	int *next;
	
	node(int val){
		data=val;
		next=NULL;
		
	}
};

class single{
	public:
	node* head;
	node* tail;
	
	single(){
		head=tail=NULL;
		
	}
	
	void insertstart(int val){
		node* n1=new node(val);
		
		if(head==NULL){
			head=tail=n1;
			
	}
	else{
		n1->next=head;
		head=n1;
	}
	
	void display(){
		node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main(){
	single s1;
	s1.insertstart(4);
	s1.insertstart(3);
	s1.display();
	
	return 0;
}
