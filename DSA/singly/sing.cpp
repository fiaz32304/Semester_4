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
	}


	void insertend(int val) {
		node* n1 = new node(val);
			if(head== NULL){
			head = tail = n1;
		}
			else {
				tail->next = n1;
				tail = n1;
			}
	}

	void insertatspecificpos(int val, int pos) {
		node* n1 = new node(val);

		if (head ==  NULL) {
			cout << "list is empty";
		}
		else if (pos < 1) {
			cout << "invalid pos";
		}
		else if (pos == 1) {
			insertstart(val);

		}
		else {
			node* temp = head;
			for (int i = 1; i< pos - 1 && temp!=  NULL; i++){
				temp = temp->next;

			}
			n1->next = temp->next;
			temp->next = n1;
		}
	}


	void deletestart() {
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
		else {
			while(temp->next!=NULL){
				temp=temp->next;	
			}
			temp->next=NULL;
			delete temp;
		}
	}

	void deleteatspecificpos(int pos) {
		node* temp = head;
		node* temp2 = temp;
			if (head ==  NULL) {
				cout << "list is empty";
			}
			else if (pos < 1) {
				cout << "invalid";
			}
			else if (pos == 1) {
				deletestart();
			}
			else {
				node* temp = head;
				for (int i = 1;i < pos - 1 && temp!= NULL; i++) {
					temp = temp->next;
				}
				temp->next = temp2->next;
				temp2->next =  NULL;
				delete temp2;
			}
	}
	void update(int val, int pos){
		node* temp=head;
		if(head==NULL){
			cout<<"list is empty";
		}
		else if(pos<1){
			cout<<"invalid";
		}
		else{
		for(int i=1;i<pos-1 &&temp!=NULL;i++){
			temp=temp->next;
		}
		temp->data=val;
			}
		}
	void find(int key){
		node* temp=head;
			int pos=1;
		if(head==NULL){
			cout<<"list is empty";
		}
		else{
			while(temp!=NULL){
				if(temp->data==key){
					cout<<"value fund at pos"<<pos<<endl;
				}
				temp=temp->next;
				pos++;
			}
			
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
		s1.display();
		s1.insertend(30);
		s1.insertend(40);
		s1.display();
		s1.insertatspecificpos(25, 3);
		s1.insertatspecificpos(5, 1);
		s1.display();
		s1.deletestart();
		s1.display();
		s1.deleteEnd();
		s1.display();
		s1.deleteatspecificpos(2);
		s1.display();
		s1.update(50,2);
		s1.display();
		
		return 0;
	}

