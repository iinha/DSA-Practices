#include <iostream>
using namespace std;

void search(int a[], int n, int x) {
	int first_idx = -1;
	int first_steps = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			first_idx = i;
			first_steps = i + 1;
			break;
		}
	}
	if (first_idx == -1) { 
		cout << -1 <<endl; 
		return;
	}
	int last_idx = -1;
	int last_steps = 0 ;
	for (int j = n - 1; j >= 0; j--) {
		if (a[j] == x) {
			last_idx = n-1-j;
			last_steps = n - j;
			break;
		}
	}
	cout << first_idx <<endl;
	cout << first_steps << endl;
	cout << last_idx << endl;
	cout << last_steps << endl;
}
int main() {
	int a[100], n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	search(a, n, x);
	return 0;
}