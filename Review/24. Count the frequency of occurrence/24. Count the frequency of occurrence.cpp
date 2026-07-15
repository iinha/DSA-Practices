
#include <iostream>
#include <vector>
using namespace std;

const int HSIZE = 200003;

struct Node {
    int key;
    int cnt;
    Node* next;
};

Node* table[HSIZE];
vector<Node*> order;

int hashKey(int x) {
    return x % HSIZE;
}

// Implement frequency counting with your own hash table.
// void add(int x);                              // insert x, or increment its count if present;
//                                               // record first-appearance order in `order`
// void countFrequencies(const vector<int>& a); // process the array, then print "value count"
//                                               // for each distinct value in first-appearance order

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    countFrequencies(a);

    return 0;
}
