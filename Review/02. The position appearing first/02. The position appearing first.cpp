

#include <iostream>
using namespace std;

int a[100005];

int firstOccurrence(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    int result = -1; 

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (a[m] == x) {
            result = m + 1; 
            r = m - 1;    
        }
        else if (a[m] > x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return result;
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
        cout << firstOccurrence(a, n, x) << "\n";
    }

    return 0;
}
