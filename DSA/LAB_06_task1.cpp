#include  <iostream>
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

class queue{
	public:
		node* front;
		node* rear;
		
		queue(){
			front=rear=NULL;
		}
		
		bool is_empty(){
			return (front==NULL);
		}
		
		void display(){
			if(is_empty()){
				cout<<"queue is empty :";
			}else{
				node* temp=front;
				int index= 0;
				
				while(temp!=NULL){
					cout<<"value at index "<<index++<<" is "<<temp->data<<endl;
					temp=temp->next;
				}
			}
		}
		void enqueue(int x){
			node* newnode=new node(x);
			
			if(is_empty()){
				front =rear=newnode;
			}
			else{
				rear->next=newnode;
				rear=newnode;
			}
		}
		
		int dequeue(){
			if(is_empty()){
				cout<<"queue is empty ";
				
				return -1;
			}
			node *temp=front;
			int value=temp->data;
			
			if(front== rear){
				front=rear=NULL;
			}
			else{
				front=front->next;
			}
			delete temp;
			return value;
		}
};

int main(){
	queue q1;
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	
	q1.display();
	int x=q1.dequeue();
	cout<<"dequeue element is "<<x<<endl;
	q1.display();
	
	return 0;
}
