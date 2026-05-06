#include <iostream>
using namespace std;

class node{
	public:
	int data;
node* next;
	node(int val){
		data = val;
		next=NULL;

	}
};

class cir {
	public:
	node* head;
	

	cir(){
		head = NULL;
	}

	void insertstart(int val){
		
		node* n1 = new node(val);
		node* temp=head;
		if (head == NULL) {
			head = n1;
		}
		else {
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=n1;
			n1->next = head;
			head = n1;
		}
		
	}
		void insertEnd(int val){
		node* n1 = new node(val);
		node* temp=head;
		if (head == NULL) {
			head = n1;
		}
		else {
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=n1;
			n1->next = head;
		}
		
	}
	void display(){
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "-> ";
			temp = temp->next;
		}
		cout<<"head";
		cout<<endl;
	}

};
int main() {
	cir c1;
	c1.insertstart(10);
	c1.insertstart(20);
	c1.insertstart(30);
	c1.display();
	c1.insertEnd(22);
	c1.insertEnd(23);
	c1.display();
	
	return 0;	
}
