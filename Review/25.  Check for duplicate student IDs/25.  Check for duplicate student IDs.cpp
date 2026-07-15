
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int HSIZE = 200003;

struct Node {
    string key;
    int cnt;
    Node* next;
};

Node* table[HSIZE];
vector<Node*> order;

int hashKey(const string& s) {
    int h = 0;
    for (char c : s) {
        h = (h * 131 + (int)c) % HSIZE;
    }
    return h;
}

// Implement duplicate detection with your own hash table.
// void add(const string& s);                       // insert s, or increment its count if present;
//                                                  // record first-appearance order in `order`
// void findDuplicates(const vector<string>& ids);  // count all ids, then print each id with count >= 2
//                                                  // once, in first-appearance order; print "NONE" if none

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> ids(n);
    for (int i = 0; i < n; i++) cin >> ids[i];

    findDuplicates(ids);

    return 0;
}
