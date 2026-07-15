
#include <iostream>
#include <string>
using namespace std;

const int MAXM = 1005;

struct Node {
    int val;
    Node* next;
};

int m;
Node* head[MAXM];
Node* tail[MAXM];

Node* createNode(int v) {
    Node* p = new Node();
    p->val = v;
    p->next = nullptr;
    return p;
}

// Implement the four hash table operations below (chaining, h(x) = x % m).
// void insertVal(int x);   // append x at the tail of bucket h(x)
// bool searchVal(int x);   // return true if x is in the table
// void deleteVal(int x);   // delete the first node whose value is x in its bucket
// void printTable();       // print m lines: "i: v1 v2 ...", empty bucket -> "i:"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> m >> q;

    string op;
    for (int t = 0; t < q; t++) {
        cin >> op;
        if (op == "INSERT") {
            int x;
            cin >> x;
            insertVal(x);
        }
        else if (op == "SEARCH") {
            int x;
            cin >> x;
            cout << (searchVal(x) ? "YES" : "NO") << "\n";
        }
        else if (op == "DELETE") {
            int x;
            cin >> x;
            deleteVal(x);
        }
        else {
            printTable();
        }
    }

    return 0;
}
