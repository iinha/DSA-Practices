#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long long firstNonRepeating(const vector<long long>& arr) {
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << firstNonRepeating(arr) << endl;
    return 0;
}
