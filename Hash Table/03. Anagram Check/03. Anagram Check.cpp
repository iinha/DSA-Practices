#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


bool isAnagram(const string& s, const string& t) {
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << (isAnagram(s, t) ? "YES" : "NO") << endl;
    return 0;
}
