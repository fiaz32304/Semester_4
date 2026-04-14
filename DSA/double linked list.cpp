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
class doublel{
	public:
	node* head;
	node* tail;
	
	doublel(){
		head=tail=NULL;
	}	
	void insertst(int val){
		node* n1= new node(val);
		if(head==NULL){
			head=tail=n1;
		}
		else{
			n1->next=head;
			head->prev=n1;
			head=n1;
		}
	}
	void insertend(int val){
			node* n1= new node(val);
		if(head==NULL){
			head=tail=n1;
		}else{
			tail->next=n1;
			n1->prev=tail;
			tail=n1;
		}
	}
	
	void deletes(){
		node * temp=head;
		if(head==NULL){
			cout<<"list is empty";
		}
		else{
			head=head->next;
			head->prev=NULL;
		
		}
			delete temp;
	}
	
	void deleteEnd(){
		node * temp=tail;
		if(head==NULL){
			cout<<"list is empty";
				
    	}
    	else if(head==tail){
    		head=tail=NULL;
		}
		else{
    		tail=tail->prev;
			tail->next=NULL;
			
		}
			delete temp;
   }
   void insertatspecificpos(int pos ,int val){
   	node * n1=new node(val);
   	if(head==NULL){
   		cout<<"list is empty";
	   }
	   else if(pos<1){
	   	cout<<"invalid";
	   }
	   else if(pos==1){
	   	insertst(val);
		}
	   else{
	   	node *temp=head;
	   	for(int i=1; i<pos-1 && temp!=NULL; i++){
	   		temp=temp->next;
		   }
		   n1->next=temp->next;
		   n1->prev=temp;
		   temp->next->prev=n1;
		   temp->next=n1;
	   }
   }
   void deleteatspecific(int pos){
 
   	if(head==NULL){
   		cout<<"list is empty";
	   }
	   else if(pos<1){
	   	cout<<"invalid";
	   }
	   else if(pos==1){
	   	deletes();
	   }
	   else{
	     	node *temp=head;
	     	for(int i=0;i<pos-1 &&temp->next!=NULL;i++){
	     		temp=temp->next;
			 }
			 node* temp2=temp->next;
			 temp->next=temp2->next;
			 if(temp2->next!=NULL){
			 	temp2->next->prev=temp;
			 }
			 delete temp2;	 
	   }
   }
   void update(int val ,int pos){
   	node * temp=head;
   	if(head==NULL){
   		cout<<"list is empty";
	   }
	   else if(pos<1){
	   	cout<<"invalid";
	   }
	   else{
	   	for(int i=1; i<pos &&temp->next!=NULL; i++){
	   		temp=temp->next;
	  
	   }
	   	 temp->data=val;
   }
   
   }
	void display(){
		node * temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<endl;	
	}
	
};
int main(){
	doublel l1;
	l1.insertst(3);
	l1.insertst(4);
	l1.display();
	l1.insertend(5);
	l1.insertend(6);
	l1.display();
	
	l1.deletes();
	l1.display();
	l1.deleteEnd();
	l1.display();
	
	l1.insertatspecificpos(2,7);
	l1.insertatspecificpos(1,8);
	l1.display();
	l1.deleteatspecific(3);
	l1.display();
	l1.update(10,3);
	l1.display();
	
	return 0;
}
