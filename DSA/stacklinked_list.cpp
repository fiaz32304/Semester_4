#include <iostream>
using namespace std;

class node{
	public:
		int  data;
		node* next;
		
		node(int val){
			data = val;
			next = NULL;
		}
	};
		class stck{
			public:
			node * top;
			
			stck(){
					top=NULL;
			}
			
			void push(int val){
				node * n1=new node(val);
				if(top==NULL){
					top=n1;
				}
				else{
					n1->next=top;
					top=n1;
				}
			}
			void pop(){
				node * temp=top;
				if(top==NULL){
					cout<<"stack is empty";
				}
				else{
						top=temp->next;
						temp->next=NULL;
						delete temp;
					
				}
			}
			
			void update(int pos, int val){
				node * temp=top;
				if(top==NULL){
					cout<<"stack is empty";
				}
				else{
					for(int i=1; i<pos && temp!=NULL;i++){
						temp=temp->next;	
			}
							temp->data=val;
					cout<<"updated successfully"<<endl;
				}
			}
			
//			void find (int key){
//				int pos=1;
//				bool found=false;
//				node * temp=top;
//				if(top==NULL){
//					cout<<"stack is empty";
//					
//				}
//				else{
//					while(temp!=NULL){
//						if(temp->data==key){
//							cout<<"found at pos"<<pos<<endl;
//							found=true;
//							break;
//						}
//							temp=temp->next;
//						pos++;
//						if(!found){
//						
//							cout<<"not found";
//						}
//					
//					}
//				}
//			}
			void find(int key){
				node * temp=top;
				int pos=1;
				if(top==NULL){
					cout<<"stack is empty";
				}
				else{
					for(int i=1; i<pos & temp!=NULL;i++){
					
						if(temp->data==key){
							cout<<"value found at pos"<<pos<<endl;
						}
						temp=temp->next;
						pos++;
						
					}
					
				}
			}
		
		void display(){
			node * temp= top;
			while(temp!=NULL){
			cout << temp->data<<endl;
				temp=temp->next;
			}
		}
		
};
int main(){
	stck s1;
	s1.push(3);
	s1.push(5);
	s1.push(6);
	s1.display();
	s1.pop();
	s1.display();
	s1.update(2,7);
	s1.display();
	
	s1.find(7);
	s1.display();
			return 0;
}
