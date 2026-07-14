#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

Node* createNode(int x) {
    Node* node = new Node();
    node->data = x;
    node->next = nullptr;
    return node;
}

// Implement the following operations on the singly linked list (do NOT use std::list):
//   void addHead(List& lst, int x)      - insert x at the head
//   void addTail(List& lst, int x)      - insert x at the tail
//   void deleteValue(List& lst, int x)  - remove the first node equal to x (ignore if absent)
//   bool findValue(List& lst, int x)    - return true if x is in the list
//   void printList(List& lst)           - print the list "a b c", or "EMPTY" if it is empty

void addHead(List& lst, int x) {
    Node* p = createNode(x);
    if (lst.head == NULL) {
        lst.head = p;
        lst.tail = lst.head;
    }
    else {
        p->next = lst.head;
        lst.head = p;
    }
}

void addTail(List& lst, int x) {
    Node* p = createNode(x);
    if (lst.head == NULL) {
        lst.head = p;
        lst.tail = lst.head;
    }
    else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

void deleteValue(List& lst, int x) {
    Node* p = lst.head;
    Node* q = NULL;

    while ((p != NULL) && (p->data != x)) {
        q = p;
        p = p->next;
    }
    if (p == NULL) return;

    if (q != NULL) {
        q->next = p->next;
        if (p == lst.tail) {
            lst.tail = q;
        }
    }
    else {
        lst.head = p->next;
        if (lst.head == NULL) {
            lst.tail = NULL;
        }
    }

    delete p;
}

bool findValue(List& lst, int x) {
    Node* p = lst.head;
    while ((p != NULL) && (p->data != x)) {
        p = p->next;
    }
    if (p == NULL) { return false; }
    else {
        return true;
    }
}

void printList(List& lst) {
    if (lst.head == NULL) {
        cout << "EMPTY\n";
        return;
    }

    Node* p = lst.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    List lst = List{ nullptr, nullptr };

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD_HEAD") {
            int x;
            cin >> x;
            addHead(lst, x);
        }
        else if (cmd == "ADD_TAIL") {
            int x;
            cin >> x;
            addTail(lst, x);
        }
        else if (cmd == "DELETE") {
            int x;
            cin >> x;
            deleteValue(lst, x);
        }
        else if (cmd == "FIND") {
            int x;
            cin >> x;
            cout << (findValue(lst, x) ? "YES" : "NO") << '\n';
        }
        else {
            printList(lst);
        }
    }

    return 0;
}
