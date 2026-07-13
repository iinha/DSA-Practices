#include <iostream>
using namespace std;

int a[100005];

int countLessEqual(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    int pos = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] <= x) {
            pos = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return pos + 1;
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
        cout << countLessEqual(a, n, x) << "\n";
    }

    return 0;
}
