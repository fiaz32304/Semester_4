#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int val){
		data = val;
		next = NULL;
	}
};
class single {
public:
	node* head;
	node* tail;

	single() {
		head = tail = NULL;

	}
	void insertstart(int val) {
		node* n1 = new node(val);
		if (head ==  NULL) {
			head = tail = n1;

		}
		else {
			n1->next = head;
			head = n1;

		}
	}	void deletestart() {
		node* temp = head;
		if(head== NULL){
			cout << "list is empty";
		}
		else {
			head = temp->next;
			temp->next =  NULL;
			delete temp;
		}
	}

	void deleteEnd() {
		node* temp =head;
		if(head==NULL){
			cout << "list is empty";
		}
		
		tail=temp;
		tail->next=NULL;
		temp=tail->next;
		delete temp;
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
int main() {

		single s1;
		s1.insertstart(10);
		s1.insertstart(20);
			s1.insertstart(20);
				s1.insertstart(20);
					s1.insertstart(20);
						s1.insertstart(20);
		s1.display();
		s1.deletestart();
			s1.display();
			s1.deleteEnd();
			s1.deleteEnd();
	return 0;
	
}
