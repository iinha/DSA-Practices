#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> anagramsgroup;
    for (const string & word : words) {
        string sortedword = word;
        sort(sortedword.begin(), sortedword.end());
        anagramsgroup[sortedword].push_back(word);
    }
    vector<vector <string>> result;
    for (auto& entry : anagramsgroup) {
        sort(entry.second.begin(), entry.second.end());
        result.push_back(entry.second);
    }
    sort(result.begin(), result.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[0] < b[0];
        });
    return result;
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
