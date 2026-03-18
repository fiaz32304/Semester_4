#include <iostream>
#include <vector>

using namespace std;

class Student{
public:
    int id;
    int marks;
    string name;

    void input(){
        cin >> id >> marks >> name;
    }

    void display(){
        cout << id << marks<< name << endl;
    }
};

int main(){
    vector<Student> students;
    Student s;

    for(int i=0;i<3;i++){
        s.input();
        students.push_back(s);
    }
for(int i = 0; i < students.size(); i++){
    students[i].display();

    }

    return 0;
}
