#include <iostream>
#include <vector>
using namespace std;

class arr{
	vector<int> list;
	public:
	int val;
	int pos;
	int key;
	
	void insertstart(){
			cout<<"enter the num ";
			cin>>val;
			list.insert(list.begin() ,val);
	}
	
	void insertEnd(){
			cout<<"enter the num ";
			cin>>val;
			list.push_back(val);	
	}
	
	void insertatspecificpos(){
			cout<<"enter the num ";
			cin>>val;
			cout<<"enter the pos ";
			cin>>pos;
		if(pos <0 || pos >list.size()){
			cout<<"invalid";
		}
		else{
		
			list.insert(list.begin() +pos , val);
		}
		cout<<endl;
	}
	
	void deletestart(){
		if(list.empty()){
			cout<<"list is empty";
		}
		else{
			cout<<"delete from start";
			list.erase(list.begin());
		}
		cout<<endl;
	}
	
	void deleteEnd(){
		if(list.empty()){
			cout<<"list is empty";
		}
		else{
			cout<<"delete from end";
			list.pop_back();	
		}
		cout<<endl;
	}
	
	void deletespecificpos(){
		if(list.empty()){
			cout<<"list is empty";
		}
		else if(pos <0 || pos >list.size()){
			cout<<"invalid";
		}
		else{
			cout<<"enter the pos";
			cin>>pos;
			list.erase(list.begin() +pos);
		}
		cout<<endl;
	}
	
	void update(){
		if(list.empty()){
			cout<<"list is empty";
		}
		else{
			for(int pos=0; pos<list.size();pos++)
			cout<<"enter the val";
			cin>>val;
			cout<<"enter the pos";
			cin>>pos;
				list[pos]=val;
			}
		}
	
	void search(){
		if(list.empty()){
			cout<<"list is emopty";
			
		}
		else{
			cout<<"enter the key";
			cin>>key;
			for(int i=0; i<list.size(); i++){
				if(list[i]==key){
					cout<<"value found at pos"<<i+1;
				}
				else{
					cout<<"not found";
				}
			}
		}	
	}
	
	void display(){
		for(int i=0; i<list.size();i++){
			cout<<list[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	arr a1;
	a1.insertstart();
	a1.insertstart();
	a1.insertstart();
	a1.display();
	
	a1.insertEnd();
	a1.insertEnd();
	a1.display();
	
	a1.insertatspecificpos();
	a1.display();
	
	a1.deletestart();
	a1.display();
	
	a1.deleteEnd();
	a1.display();
	
	a1.deletespecificpos();
	a1.display();
	
	a1.update();
	a1.display();
	
	a1.search();
	a1.display();
	
	return 0;
}

