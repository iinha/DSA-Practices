
#include <iostream>
#include <string>
using namespace std;

const int MAXM = 1005;

int m;
int slots[MAXM];
bool used[MAXM];

// Implement the linear-probing operations below (h(x) = x % m, probe (idx + 1) % m).
// void insertVal(int x);   // store x at the first free slot starting from h(x)
// int  searchVal(int x);   // return the 0-based slot holding x, or -1 if not found
//                          // (stop probing as soon as an empty slot is reached)
// void printTable();       // print one line of m values: the slot value, or "-" if empty

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
            cout << searchVal(x) << "\n";
        }
        else {
            printTable();
        }
    }

    return 0;
}
