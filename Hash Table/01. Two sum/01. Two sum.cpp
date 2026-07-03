#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;


pair<int, int> twoSum(const vector<long long>& arr, long long target) {
    unordered_map<long long, int> seen;

    for (int i = 0; i < arr.size(); i++) {
        long long complement = target - arr[i];
        if (seen.find(complement) != seen.end()) {
            return { seen[complement]+1, i+1 };
        }
        seen[arr[i]] = i;
    }

    return { -1, -1 };
}

int main() {
    int n;
    long long target;
    cin >> n >> target;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    pair<int, int> ans = twoSum(arr, target);
    if (ans.first == -1) {
        cout << -1 << endl;
    }
    else {
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
