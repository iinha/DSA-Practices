#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long long firstNonRepeating(const vector<long long>& arr) {
    unordered_map <long long, int> count;
    for (const long long& num : arr) {
        count[num]++;
    }
    for (const long long& num : arr) {
        if (count[num] == 1)
            return num;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << firstNonRepeating(arr) << endl;
    return 0;
}
