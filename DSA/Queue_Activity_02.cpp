#include <iostream>
using namespace std;

class queue{
	public:
		int size;
		int *q;
		int front;
		int rear;
		
		queue(){
			size=10;
			q=new int[size];
			front=rear=-1;
			
		}
		queue(int x){
			size=x;
			q=new int[size];
			front=-1;
			rear=-1;
		}
		
		bool is_empty(){
			if(rear==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool is_full(){
			if(rear==size-1){
				return true;
				
			}else{
				return false;
			}
		}
		
		void display(){
			if(is_empty()){
				cout<<"queue is empty";
			}
			else{
				for(int i=front;i<=rear;i++){
				cout<<"value at index "<< i<<"is "<<q[i]<<endl;
				}
				
			}
		}
		void enqueue(int x){
			if(is_full()){
				cout<<"No space";
			}
			else{
				if(is_empty()){
					front =rear=0;
				}
				else{
					rear++;
				}
				q[rear]=x;
			}
		}
		
		int dequeue(){
			if(is_empty()){
					cout<<"queue is already empty ";
					return -1; 
			}
			else{
				int x=q[front];
				if(front ==rear){
					front =rear =-1;
				}
				else{
					front++;
				}
				return x;
			}
		
		}
		
		
int deque{
	int temp;
	if(!isEmpty()){
		temp=queue[front];
		if(front ==rear){
			front =rear=-1;
		}else{
			shift_left(front,rear);
		}
		rear--;
	}
	else{
		cout<<"sorry";
		temp=-1;
	}
	return temp;
	
	void shift_left(int front,int rear){
		int x=front;
		while(x+1!=rear){
			que[x]=que[x+1];
		}
	}
};
		
		int main(){
			queue q2(2);
			q2.enqueue(4);
			q2.enqueue(2);
			q2.enqueue(7);
			q2.display();
		
			int x=q2.dequeue();
			cout<<"dequeue element from q3 is "<<x<<endl;
			q2.display();
			
			return 0;
			
		}		
		


