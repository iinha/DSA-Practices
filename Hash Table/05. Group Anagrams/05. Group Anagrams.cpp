#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<vector<string>> groupAnagrams(const vector<string>& words) {
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    vector<vector<string>> groups = groupAnagrams(words);
    for (auto& g : groups) {
        for (size_t i = 0; i < g.size(); i++) {
            if (i) cout << " ";
            cout << g[i];
        }
        cout << "\n";
    }
    return 0;
}
