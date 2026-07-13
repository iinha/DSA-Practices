#include <iostream>
using namespace std;

void quickSort(int* a, int b, int e) {
    if (b >= e) return;
    int x = a[b + (e - b) / 2];
    int i = b, j = e;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]); 
            i++;
            j--;
        }
    }
    if (b < j) quickSort(a, b, j);
    if (i < e) quickSort(a, i, e);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n > 0) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
