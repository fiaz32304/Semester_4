#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	
	node(int val){
		data=val;
		next=NULL;
		prev=NULL;
	}
};

class dequeue{
	public:
		node* front;
		node* rear;
		
		dequeue(){
			front=rear=NULL;
		}
		
		bool is_empty(){
			return (front==NULL);
			
		}
		void insert_front(int x){
			node* newnode=new node(x);
			
			if(is_empty()){
					front=rear=newnode;
				
			}else{
				newnode->next=front;
				front->prev=newnode;
				front=newnode;
				
			}
			
		}
		
		void insert_rear(int x){
			node* newnode=new node(x);
			
			if(is_empty()){
				front=rear=newnode;
			}
			else{
				rear->next=newnode;
				newnode->prev=rear;
				rear=newnode;
			}
			
		}
		int delete_front(){
			if(is_empty()){
				cout<<" dequeue is empty";
				return -1;
			}
			
			node*temp=front;
			int value =temp->data;
			
			if(front==rear){
				front=rear=NULL;
				
			}else{
				front=front->next;
				front->prev=NULL;
			}
			delete temp;
			return value;
		}
		
		int delete_rear(){
			if(is_empty()){
				cout<<" dequeue is empty";
				return -1;
			}
			node *temp=rear;
			int value=temp->data;
			
			if(front==rear){
				front=rear=NULL;
			}
			else{
				rear=rear->prev;
				rear->next=NULL;
			}
			delete temp;
			return value;
		}
		
		void display(){
			if(is_empty()){
				cout<<"dequeue is empty";
			}
			else{
				node *temp=front;
				int index=0;
				while(temp!=NULL){
					cout<<"value at index "<<index++<< " is "<<temp->data<<endl;
					 temp = temp->next; 
				}
			}
		}
};
int main(){
	dequeue q1;
	q1.insert_front(10);
	q1.insert_front(14);
	q1.display();
	
	q1.insert_rear(4);
	q1.insert_rear(7);
	q1.display();
	
	q1.delete_front();
	q1.display();
	
	q1.insert_rear(9);
	q1.delete_rear();
	q1.delete_rear();
	q1.display();
	
	return 0;
}
