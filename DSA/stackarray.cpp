#include <iostream>
using namespace std;

class StackArray {
public:
    int arr[10];
    int top;

    StackArray() {
        top = -1;
    }

    void push(int x) {
        if (top == 9) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void update(int pos, int val) {
        if (pos < 0 || pos > top) {
            cout << "Invalid Position\n";
            return;
        }
        arr[pos] = val;
    }

    void find(int val) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == val) {
                cout << "Found at index: " << i << endl;
                return;
            }
        }
        cout << "Not Found\n";
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.update(1, 50);
    s.display();

    s.find(50);

    s.pop();
    s.display();

    return 0;
}
