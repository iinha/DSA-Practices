#include <iostream>
#include <string>
using namespace std;

// Implement a queue of document names yourself (array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(const string& name) - add a document name to the back
//   bool emptyQueue()                - return true if the queue is empty
//   string dequeue()                 - remove and return the front document name (queue is non-empty)

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
