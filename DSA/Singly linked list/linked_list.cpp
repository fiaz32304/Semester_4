#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    explicit Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    Node* tail;

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
    ~SinglyLinkedList() {
        clear();
    }

    void insertFront(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head = n;
        }
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    // insert at index pos (0-based). If pos <= 0 inserts at front. If pos >= size inserts at end.
    void insertAt(int val, int pos) {
        if (pos <= 0 || !head) {
            insertFront(val);
            return;
        }
        Node* temp = head;
        int idx = 0;
        while (temp->next && idx < pos - 1) {
            temp = temp->next;
            ++idx;
        }
        if (!temp->next) { // reached end or pos beyond size
            insertEnd(val);
            return;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    bool removeValue(int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* t = head;
            head = head->next;
            if (!head) tail = nullptr;
            delete t;
            return true;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur) {
            if (cur->data == val) {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data;
            if (temp->next) std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << '\n';
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
    }

    int size() const {
        int count = 0;
        Node* cur = head;
        while (cur) { ++count; cur = cur->next; }
        return count;
    }
};

int main() {
    SinglyLinkedList s;
    s.insertFront(4);
    s.insertFront(3);
    s.display(); // 3 -> 4
    s.insertEnd(5);
    s.insertEnd(6);
    s.display(); // 3 -> 4 -> 5 -> 6
    s.insertAt(2, 3);
    s.display(); // 3 -> 4 -> 5 -> 2 -> 6  (depending on pos semantics)
    s.insertAt(0, 0);
    s.display(); // 0 -> 3 -> 4 -> 5 -> 2 -> 6
    s.removeValue(5);
    s.display(); // 0 -> 3 -> 4 -> 2 -> 6
    std::cout << "Size: " << s.size() << '\n';
    return 0;
}
