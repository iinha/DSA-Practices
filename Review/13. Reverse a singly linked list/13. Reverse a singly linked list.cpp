
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

// Implement the operation below (reverse by relinking nodes, do NOT build an auxiliary array):
//   Node* reverseList(Node* head)
//     Reverse the singly linked list and return the new head.

Node* reverseList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* nextt = nullptr;
    while (curr != nullptr) {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }
    return prev;
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

    head = reverseList(head);

    printList(head);

    return 0;
}
