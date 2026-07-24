#include <iostream>
#include <string>
using namespace std;

// Implement a queue of document names yourself (array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(const string& name) - add a document name to the back
//   bool emptyQueue()                - return true if the queue is empty
//   string dequeue()                 - remove and return the front document name (queue is non-empty)
struct node {
    string data;
    node* next;
};

node* head = nullptr;
node* tail = nullptr;

void enqueue(const string& name) {
    node* newnode = new node();
    newnode->data = name;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

bool emptyQueue() {
    return head == nullptr;
}

string dequeue() {
    if (head != nullptr) {
        string val = head->data;
        node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return val;
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string name;
            cin >> name;
            enqueue(name);
        }
        else {
            if (emptyQueue()) cout << "NO DOCUMENT\n";
            else cout << dequeue() << '\n';
        }
    }

    return 0;
}
