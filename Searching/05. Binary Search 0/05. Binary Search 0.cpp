#include <iostream>
#include <algorithm> 
using namespace std;

bool myBinarySearch(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return true;
        else if (a[m] > x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x;
    int a[100005];

    if (!(cin >> n >> q)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < q; i++) {
        cin >> x;
        if (myBinarySearch(a, n, x)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}