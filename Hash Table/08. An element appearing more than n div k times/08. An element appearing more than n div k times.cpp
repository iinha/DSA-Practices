#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<long long> majorityNK(const vector<long long>& arr, int k) {
    unordered_map <long long, int> count;
    for (const auto& num : arr) {
        count[num]++;
    }
    vector <long long> result;
    int p = arr.size() / k;
    for (const auto& m : count){
        if (m.second > p) {
            result.push_back(m.first);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<long long> ans = majorityNK(arr, k);
    if (ans.empty()) {
        cout << -1 << "\n";
    }
    else {
        for (size_t i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
