#include <iostream>
#include <stack>
using namespace std;

class node{
	public:
	int data;
	node* next;
	
	node(int val){
	
		data=val;
		next=NULL;
	}
};

class stacksin{
	public:
	node* top;
	int count;
	
	stacksin(){
	
	top=NULL;
	count=0;
}

	void push(int val){
		node* n1=new node(val);
		if(top==NULL){
			top=n1;
		}
		else {
			n1->next=top;
			top=n1;
			count++;
		}
	}
	void pop(){
		node *temp=top;
		if(top==NULL){
			cout<<"stack is empty";
		}
		else{
			top=temp->next;
			temp->next=NULL;
			count--;
			delete temp;
			
		}
	}
	
	void update(int val , int pos){
		node* temp=top;
		if(top==NULL){
			cout<<"stack is empty";
		}
		else if(pos<1){
			cout<<"invalid";
		}
		else{
			for(int i=1;i<pos &temp->next!=NULL;i++){
				temp=temp->next;
			}
			temp->data=val;
		}
	}
	
	void find(int key){
		node *temp=top;
		int pos=1;
		for(int i=1; i<pos &&temp!=NULL  ;i++){
			if(temp->data==key){
				cout<<"value fount at pos"<<pos<<endl;
			  return ;
			}
			temp=temp->next;
			pos++;
		}
				cout<<"not foud";	
	   }
	
	void display(){
		node* temp=top;
		while(temp!=NULL){
			cout<<temp->data;
			temp=temp->next;
			
		}
		cout<<endl;
	}
};
int main(){
	stacksin s1;
	s1.push(2);
	s1.push(3);
	s1.push(6);
	s1.push(8);
	s1.display();
	s1.pop();
	s1.display();
	s1.update(1,2);
	s1.display();
	s1.find(3);
	s1.display();
	
	return 0;
}
