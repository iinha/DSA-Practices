#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

Node* buildList(const vector<long long>& vals) {
    Node dummy(0);
    Node* tail = &dummy;
    for (long long v : vals) {
        tail->next = new Node(v);
        tail = tail->next;
    }
    return dummy.next;
}

// Implement the two functions below:
//   intersectLists(a, b) -> intersection (unique, sorted asc) of two linked lists
//   unionLists(a, b)     -> union (unique, sorted asc) of two linked lists



void printVec(const vector<long long>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<long long> aVals(n);
    for (int i = 0; i < n; i++) cin >> aVals[i];

    int m;
    cin >> m;
    vector<long long> bVals(m);
    for (int i = 0; i < m; i++) cin >> bVals[i];

    Node* a = buildList(aVals);
    Node* b = buildList(bVals);

    printVec(intersectLists(a, b));
    printVec(unionLists(a, b));

    return 0;
}
