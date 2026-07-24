#include <iostream>
#include <string>
using namespace std;

// Implement an integer queue yourself (circular array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(int x)   - add x to the back
//   bool emptyQueue()     - return true if the queue is empty
//   int  frontValue()     - return the front value (the queue is non-empty)
//   int  dequeue()        - remove and return the front value (the queue is non-empty)
//   int  sizeQueue()      - return the number of elements currently in the queue

struct node {
    int data;
    node* next;
};

node* head = nullptr;
node* tail = nullptr;
int currentsize = 0;

void enqueue(int x) {
    node* newnode = new node();
    newnode->data = x;
    newnode->next = nullptr;

    if (tail == nullptr) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
    currentsize++;
}

bool emptyQueue() {
    return head == nullptr;
}

int frontValue() {
    if (head != nullptr) {
        return head->data;
    }
    return -1;
}

int dequeue() {
    if (head != nullptr) {
        int val = head->data;
        node* temp = head;

        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        currentsize--;
        return val;
    }
    return -1;
}

int sizeQueue() {
    return currentsize;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ENQUEUE") {
            int x;
            cin >> x;
            enqueue(x);
        }
        else if (cmd == "DEQUEUE") {
            if (emptyQueue()) cout << "EMPTY\n";
            else cout << dequeue() << '\n';
        }
        else if (cmd == "FRONT") {
            if (emptyQueue()) cout << "EMPTY\n";
            else cout << frontValue() << '\n';
        }
        else {
            cout << sizeQueue() << '\n';
        }
    }

    return 0;
}
