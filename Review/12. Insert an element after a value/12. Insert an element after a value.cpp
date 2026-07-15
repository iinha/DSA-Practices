#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* node = new Node();
    node->data = x;
    node->next = nullptr;
    return node;
}

// Implement the operation below (do NOT use std::list):
//   void insertAfter(Node* head, int x, int y)
//     Insert a new node with value x right after the first node whose value is y.
//     If no node has value y, do nothing.

void insertAfter(Node* head, int x, int y) {
    Node* q = head;
    if (head == NULL) return;
    else {
        while (q != NULL) {
            if (q->data == y) {
                Node* p = createNode(x);
                p->next = q->next;
                q->next = p;
                return;
            }
            q = q->next;
        }
    }
}

void printList(Node* head) {
    bool first = true;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (!first) cout << ' ';
        cout << cur->data;
        first = false;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        Node* node = createNode(v);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        insertAfter(head, x, y);
    }

    printList(head);

    return 0;
}
