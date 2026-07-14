#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};

bool Compare(const SanPham& a, const SanPham& b) {
    if (a.gia != b.gia) {
        return a.gia < b.gia; 
    }
    return a.ma < b.ma;           
}

void merge(SanPham* a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    SanPham* L = new SanPham[n1];
    SanPham* R = new SanPham[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (Compare(L[i], R[j])) {
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
        }
    }


    while (i < n1) {
        a[k++] = L[i++];
    }

    while (j < n2) {
        a[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(SanPham* a, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SanPham* a = new SanPham[n];
    for (int i = 0; i < n; i++) cin >> a[i].ma >> a[i].ten >> a[i].gia;

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].ma << ' ' << a[i].ten << ' ' << a[i].gia << '\n';
    }
    return 0;
}
