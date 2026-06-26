//Tim MEX (ver2)
#include <iostream>
#include <vector>
using namespace std;

void search(const vector<int>& a, int n) {
	vector <bool>seen(n + 1, false);
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0 && a[i] <= n) {
			seen[a[i]] = true;
		}
		while (m <= n && seen[m]) {
			m++;
		}
		cout << m << " ";
	}
	cout << "\n";
}

int main() {
	int n;
	if (!(cin >> n)) return 0;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	search(a, n);
	return 0;
}