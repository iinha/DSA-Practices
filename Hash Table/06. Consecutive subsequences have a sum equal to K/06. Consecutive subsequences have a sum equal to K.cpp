#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long long countSubarraysWithSum(const vector<long long>& arr, long long k) {
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << countSubarraysWithSum(arr, k) << endl;
    return 0;
}
