#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> count;

    for (char c : s)
        count[c]++;

    for (char c : t)
    {
        if (count.find(c) == count.end() || count[c] == 0)
            return false;
        count[c]--;
    }

    return true;
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << (isAnagram(s, t) ? "YES" : "NO") << endl;
    return 0;
}
