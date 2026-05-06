#include <iostream>
using namespace std;

#define MAX 50

// Patient structure
struct Patient {
    int id;
    string name;
    string condition;
    int priority;
};

// Simple Priority Queue Class (public)
class Hospital {
public:
    Patient p[MAX];
    int size = 0;

    // Set priority
    int getPriority(string condition) {
        if (condition == "Critical")
            return 1;
        else if (condition == "Serious")
            return 2;
        else
            return 3;
    }

    // Insert patient
    void enqueue() {
        cout << "\nEnter ID: ";
        cin >> p[size].id;

        cout << "Enter Name: ";
        cin >> p[size].name;

        cout << "Enter Condition (Critical/Serious/Normal): ";
        cin >> p[size].condition;

        p[size].priority = getPriority(p[size].condition);
        size++;

        // Sort by priority
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (p[i].priority > p[j].priority) {
                    swap(p[i], p[j]);
                }
            }
        }

        cout << "Patient Added!\n";
    }

    // Serve patient
    void dequeue() {
        if (size == 0) {
            cout << "No patients!\n";
            return;
        }

        cout << "\nServing: " << p[0].name << endl;

        for (int i = 0; i < size - 1; i++) {
            p[i] = p[i + 1];
        }

        size--;
    }

    // Display patients
    void display() {
        if (size == 0) {
            cout << "Empty Queue\n";
            return;
        }

        cout << "\nPatients List:\n";
        for (int i = 0; i < size; i++) {
            cout << p[i].name << " - " << p[i].condition << endl;
        }
    }
};

int main() {
    Hospital h;
    int choice;

    do {
        cout << "\n1. Add Patient\n2. Serve Patient\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            h.enqueue();
        else if (choice == 2)
            h.dequeue();
        else if (choice == 3)
            h.display();

    } while (choice != 4);

    return 0;
}
