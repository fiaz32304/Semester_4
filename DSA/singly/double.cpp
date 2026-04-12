#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node*prev;

	node(int val){
		data = val;
		prev=NULL;
		next = NULL;
	}
};
class doubly {
    public:
	node* head;
	node* tail;

	doubly() {
		head = tail = NULL;

	}
	void insertstart(int val){
		node* n1=new node(val);
	
	if(head==NULL){
		head=tail=n1;
		
	}else{
		n1->next=head;
		head->prev=n1;
		head=n1;
	}	
}

	void display() {
		node* temp = head;
		while(temp!= NULL){
			cout << temp->data << "->";
			temp = temp->next;

		}
		cout << endl;
	}

};
int main(){
	doubly d1;
	d1.insertstart(2);
	d1.insertstart(3);
	d1.display();
	
	return 0;
}
