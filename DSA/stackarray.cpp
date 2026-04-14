#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];   // fixed size array
    int top;      // top variable

public:
    // Constructor
    Stack() {
        top = -1;   // stack empty
    }

    // Push (Insert)
    void push(int value) {
        if (top == 4) {
            cout << "Stack Overflow\n";
        } else {
            top++;
            arr[top] = value;
            cout << value << " inserted\n";
        }
    }

    // Pop (Delete)
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top] << " deleted\n";
            top--;
        }
    }

    // Top (Peek)
    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Find
    void find(int value) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
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
        if (index < 0 || index > top) {
            cout << "Invalid index\n";
        } else {
            arr[index] = value;
            cout << "Updated\n";
        }
    }

    // Display
    void display() {
        if (top == -1) {
            cout << "Stack empty\n";
        } else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.find(20);

    s.update(1, 50);
    s.display();

    s.pop();
    s.display();

    return 0;
}
