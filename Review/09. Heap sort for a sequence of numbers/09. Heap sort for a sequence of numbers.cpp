#include <iostream>
using namespace std;

void heapify(int* a, int k, int n) {
    int j = 2 * k + 1;
    while (j < n) {
        if (j + 1 < n) {
            if (a[j] < a[j + 1]) j = j + 1;
        }
        if (a[k] >= a[j]) return;
        swap(a[k], a[j]);
        k = j; j = 2 * k + 1;
    }
}

void buildHeap(int* a, int n) {
    int i;
    i = (n - 1) / 2;
    while (i >= 0) {
        heapify(a, i, n);
        i--;
    }
}
void heapSort(int a[], int n) {
    buildHeap(a, n);
    while (n > 0) {
        n = n - 1;
        swap(a[0], a[n]);
        heapify(a, 0, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    heapSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
