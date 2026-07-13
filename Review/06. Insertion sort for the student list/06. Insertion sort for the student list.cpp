#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maso;
    string ten;
    int diem;
};

bool compare(const SinhVien &m, const SinhVien &p) {
    if (m.diem != p.diem) {
        return (m.diem > p.diem);
    }
    else{
        return (m.ten < p.ten);
    }
}
void insertionSort(SinhVien a[], int n) {
    for (int i = 1; i < n; i++) {
        SinhVien key = a[i];
        int j = i - 1;
        while (j >= 0 && compare(key,a[j])) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SinhVien* a = new SinhVien[n];
    for (int i = 0; i < n; i++) cin >> a[i].maso >> a[i].ten >> a[i].diem;

    insertionSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i].maso << ' ' << a[i].ten << ' ' << a[i].diem << '\n';
    }
    return 0;
}
