#include <iostream>
#include <vector>
using namespace std;

class arr {
public:
    vector<int> list;
    int val;
    int pos;

    void insertstart() {
        cout << "Enter number: ";
        cin >> val;
        list.insert(list.begin(), val);
    }

    void insertend(){
        cout << "Enter number: ";
        cin >> val;
        list.push_back(val);
    }

    void insertatspecificpos() {
        cout << "Enter number: ";
        cin >> val;
        cout << "Enter value at pos: ";
        cin >> pos;

        if(pos<0|| pos> list.size()){
        	cout<<"invalid ";
        	return;
		}
		else{
			list.insert(list.begin() +pos, val);
		}
            
    }
   void deleteAtSpecificPos() {
    int pos;

    if (list.empty()) {
        cout << "List is empty\n";
        return;
    }

    cout << "Enter position: ";
    cin >> pos;

    if (pos < 0 || pos >= list.size()) {
        cout << "Invalid position\n";
        return;
    }

    list.erase(list.begin() + pos);
}
    void deletestart(){
    	cout<<"delete from start";
    	if(list.empty()){
    		cout<<"list is empty";
		}
		else {
			list.erase(list.begin());
		}
		cout<<endl;
	}
	
	
	void deleteEnd(){
		cout<<"delete fron end";
		if(list.empty()){
			cout<<"list is empty";
			
		}else {
				list.pop_back();
		
		}
		cout<<endl;
	}

	
	void update(){
		int key;
		if(list.empty()){
				cout<<"list is empty";
			
		}else{
		
			cout<<"enter the key";
			cin>> key;
			cout<<"enter the value";
			cin>>val;
			list[key]=val;
			
		}
	}
	void search(){
		cout<<"enter the value";
		cin>>val;
		bool found=false;
		for(int i=0; i<list.size(); i++){
			if(list[i]==val){
			list.erase(list.begin() +i);
			cout<<"found at pos"<<i+1<<endl;
			found=true;
			break;
		
		}
	}
			if(!found){
				cout<<"not found";
			}
		
	}

    void display() {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;;
    }
};

int main() {
    arr a1;

    a1.insertstart();
    a1.insertstart();
    a1.display();

    a1.insertend();
    a1.insertend();
    a1.display();

    a1.insertatspecificpos();
    a1.display();
    
       a1.deletestart();
    a1.display();
    
    a1.deleteEnd();
    a1.display();
    
    a1.deleteAtSpecificPos();
    a1.deleteAtSpecificPos();
    a1.display();

    a1.update();
    a1.display();
    
    a1.search();
    a1.display();

    return 0;
}
