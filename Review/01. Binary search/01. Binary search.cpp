#include <iostream>
using namespace std;

int a[100005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << (binarySearch(a, n, x) ? "YES" : "NO") << "\n";
    }

    return 0;
}
