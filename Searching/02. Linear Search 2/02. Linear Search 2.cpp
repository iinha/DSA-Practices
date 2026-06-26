#include <iostream>
#include <vector>
using namespace std;

void search(const vector<int>& a, int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			count++;
		}
	}
	if (count == 0) {
		cout << 0 << endl;
		return;
	}
	else {
		cout << count << endl;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << i <<" "<< i+1 << endl;
		}
	}
	return;
}
int main() {
	int n, x;
	if (!(cin >> n)) return 0;
	vector<int> arr(n); 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	search(arr, n, x);
	return 0;
}