#include <iostream>
#include <vector>

using namespace std;

class student{
	public:
	string name;
	int id;
	int marks;
	
	void input(){
		cin>>name >>id >>marks;
		
	}
	void display(){
		cout<<name <<id <<marks <<endl;
	}
};

int main(){
	vector<student> students;
	student s;
	
	for(int i=0;i<3;i++){
		cout<<"enter the data of stu "<<i+1<<endl;
		s.input();
		students.push_back(s);
		
	}
	for(int i=0;i<students.size();i++){
		students[i].display();
	}
	
	
	return 0;
	}

