#include <iostream>
using namespace std;

int a[100005];

int binarySearch(int a[], int n, int x) {
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (x<a[m]) {
            r = m - 1;
        }
        else if (x> a[m]) {
            l = m + 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

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
