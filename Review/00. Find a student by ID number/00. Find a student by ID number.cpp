#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int id;
    string ten;
};

SinhVien sv[100005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sv[i].id >> sv[i].ten;
    }

    int x;
    cin >> x;

    int idx = linearSearch(sv, n, x);
    if (idx == -1) {
        cout << "NOT FOUND" << "\n";
    }
    else {
        cout << sv[idx].ten << "\n";
    }

    return 0;
}
