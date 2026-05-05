#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    int priority;
};

class HospitalPQ {
private:
    Patient H[50];
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    void swapPatient(Patient &a, Patient &b) {
        Patient temp = a;
        a = b;
        b = temp;
    }

    void shiftUp(int i) {
        while (i > 0 && H[parent(i)].priority < H[i].priority) {
            swapPatient(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int maxIndex = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left <= size && H[left].priority > H[maxIndex].priority)
            maxIndex = left;

        if (right <= size && H[right].priority > H[maxIndex].priority)
            maxIndex = right;

        if (i != maxIndex) {
            swapPatient(H[i], H[maxIndex]);
            shiftDown(maxIndex);
        }
    }

public:
    HospitalPQ() {
        size = -1;
    }

    // Register patient
    void registerPatient(int id, string name, int priority) {
        size++;
        H[size].id = id;
        H[size].name = name;
        H[size].priority = priority;

        shiftUp(size);
    }

    // Treat highest priority patient
    void treatPatient() {
        if (size < 0) {
            cout << "No patients!\n";
            return;
        }

        cout << "Treating: " << H[0].name 
             << " (Priority: " << H[0].priority << ")\n";

        H[0] = H[size];
        size--;
        shiftDown(0);
    }

    // Display patients
    void display() {
        cout << "\nPatients in Queue:\n";
        for (int i = 0; i <= size; i++) {
            cout << H[i].name << " (Priority: " 
                 << H[i].priority << ")\n";
        }
    }
};

// Main function
int main() {
    HospitalPQ h;

    h.registerPatient(1, "Ali", 3);
    h.registerPatient(2, "Sara", 5);
    h.registerPatient(3, "Ahmed", 2);

    h.display();

    h.treatPatient();
    h.display();

    return 0;
}
