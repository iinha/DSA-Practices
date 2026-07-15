
#include <iostream>
using namespace std;

// Implement a stack of int yourself (array or linked list, do NOT use std::stack)
// and use it to write the function below:
//   void printBinary(int n)
//     Print the binary representation of n (no leading zeros), followed by a newline.
//     Hint: push n % 2, then n /= 2; finally pop the bits to print them (LIFO).

struct Node {
    int data;
    Node* next;
};

struct stack {
    Node* head;
    stack() {
        head = nullptr;
    }
    ~stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    void push(int c) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = head;
        head = newNode;
    }
    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    int top() {
        if (head != nullptr) {
            return head->data;
        }
        return 0;
    }
    bool isEmpty() {
        return head == nullptr;
    }
};

void printBinary(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    stack s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.isEmpty()) {
        cout << s.top();
        s.pop();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    printBinary(n);

    return 0;
}
