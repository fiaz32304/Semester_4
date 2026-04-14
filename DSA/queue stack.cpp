#include <iostream>
using namespace std;

class Queue {
private:
    int arr[5];
    int front;
    int rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Insert (Enqueue)
    void enqueue(int value) {
        if (rear == 4) {
            cout << "Queue Overflow\n";
        } else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = value;
            cout << value << " inserted\n";
        }
    }

    // Delete (Dequeue)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
        } else {
            cout << arr[front] << " deleted\n";
            front++;
        }
    }

    // Peek (Front element)
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Find
    void find(int value) {
        bool found = false;
        for (int i = front; i <= rear; i++) {
            if (arr[i] == value) {
                cout << "Found at index: " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Not found\n";
        }
    }

    // Update
    void update(int index, int value) {
        if (index < front || index > rear) {
            cout << "Invalid index\n";
        } else {
            arr[index] = value;
            cout << "Updated\n";
        }
    }

    // Display
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue empty\n";
        } else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.find(20);

    q.update(1, 50);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
