#include <iostream>
#include <vector>

using namespace std;

class empl{
	public:
	string name;
	int salary;
	
	void getinput(){
		cout<<"enter the name::";
		cin>>name;
		cout<<"enter the salry";
		cin>>salary;
		
	}
	void display(){
		cout<<"name :"<<name<<"salary "<<salary<<endl;
	}
	
	
};

int main(){
	vector<empl> employe(3);
	for(int i=0;i<3;i++){
		employe[i].getinput();
		
	}
	int maxindex=0;
		for(int i=1;i<employe.size();i++){

	if(employe[i].salary>employe[maxindex].salary){
		
		maxindex=i;
	}
	
}
cout<<"the max salary of employe is ";
employe[maxindex].display();
}



